# I2C 통신 프로토콜 규격서

## 물리 규격
- I2C Speed: 400kHz (Fast Mode)
- SCL/SDA 핀: [TODO - CubeMX .ioc 확인 후 기재]
- BMP280 슬레이브 주소: 0x76 (SDO=GND 고정)
- SSD1306 슬레이브 주소: 0x3C

## 디바이스 정보

| 디바이스 | 주소 | 역할 |
|---|---|---|
| BMP280 | 0x76 | 온도 센서 (I2C/SPI 겸용, CSB=VDDIO 풀업으로 I2C 모드 고정) |
| SSD1306 | 0x3C | OLED 디스플레이 (128x64) |

## 레지스터 맵 (BMP280)

| 레지스터 주소 | 이름 | 역할 | Read/Write |
|---|---|---|---|
| 0x88~0x8D | dig_T1, dig_T2, dig_T3 | 보정계수 — 온도 보정 공식에 사용 | Read |
| 0xF4 | CTRL_MEAS | 센서 동작 모드(오버샘플링, Sleep/Forced/Normal) 설정 | Write |
| 0xFA~0xFC | TEMP (MSB/LSB/XLSB) | 측정된 raw 온도 데이터 | Read |

## 통신 시퀀스

1. (초기화, 한 번만) 보정계수(dig_T1~T3) 읽기 — 0x88~0x8D
2. (초기화, 한 번만) CTRL_MEAS(0xF4)에 모드 설정값(0x27) write — 측정 시작
3. (반복, 1초 주기) TEMP 레지스터(0xFA~0xFC)에서 raw 데이터 읽기
4. (반복) raw 데이터를 보정 공식 함수(bmp280_compensate_T_int32)에 대입 → 실제 온도값 계산
5. (반복) 온도값을 UART + OLED로 동시 출력