*OLED(SSD1306) 실전 연결

■학습 내용
- OLED 모듈 실물 핀 구조 확인: GND-VCC-SCL-SDA 순서, 뒷면에 I2C 주소 선택(0x3C/0x3D) 저항 점퍼 확인
동작전압 확인 절차: 구매처 스펙에서 3.3~5V 겸용(레벨 변환 칩 불필요) 확인 후 배선 — 
VCC는 로직 레벨 통일 위해 Nucleo 3V3에 연결 / afiskon/stm32-ssd1306 라이브러리 통합
ssd1306_Init(), ssd1306_UpdateScreen() 등으로 "STM32 OLED" 텍스트 출력 성공

*BMP280 + OLED + UART 통합

■학습 내용
- I2C 멀티 슬레이브 버스 공유: 한 SCL/SDA 버스에 BMP280(0x76), SSD1306(0x3C) 두 디바이스를 
병렬 연결 가능한 원리 학습
- Blocking 함수 개념: HAL_I2C_Mem_Read/Write가 통신이 끝날 때까지 다음 코드로 안 넘어가는 성질
  때문에 코드에 순서대로 줄만 세워도 BMP280→OLED 순차 통신이 자동 보장됨을 이해. 
  Non-blocking(인터럽트 버전)이었다면 추가 동기화 로직이 필요했을 것도 개념적으로 확인
- 버퍼오버플로우 방어: OLED용/UART용 문자열 버퍼를 각각 만들고, sprintf 결과의 케이스를 계산해서 
  버퍼 크기(oled_msg[16], uart_msg[32])가 충분한지 검증
- 오타 디버깅: white→White, ssd_UpdateScreen→ssd1306_UpdateScreen (컴파일 에러로 즉시 발견)