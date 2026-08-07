# UART 통신 프로토콜 규격서

## 물리 규격
- Baud Rate: 115200 bps
- Data Bits: 8
- Parity: None
- Stop Bits: 1

## 명령어 형식
- 종단문자(Delimiter): \n (개행문자)
- 대소문자 구분함

## 지원 명령어

| 명령어 | 동작 | 응답 |
|--------|------|------|
| LED_ON | LED 켜기 | (해당 시 추가) |
| LED_OFF | LED 끄기 | (해당 시 추가) |