# Project-4: STM32 Motor Control

## 개요
STM32 Nucleo-F411RE와 TB6612FNG 모터 드라이버로 DC 모터(GA12-N20)의 방향/속도 제어와 엔코더 RPM 측정을 구현한 프로젝트

https://github.com/user-attachments/assets/127600d0-7e26-4928-a653-ade3ed2fd58c



## 하드웨어
- STM32 Nucleo-F411RE
- TB6612FNG 모터 드라이버
- GA12-N20 DC 모터 (엔코더 내장, 감속비 1:50, 7ppr)

## 구현 과정 (단계별)

### 1단계: 모터 정/역방향 구동
TB6612FNG의 AIN1/AIN2를 GPIO로 제어해 방향을 바꾸고, TIM2 PWM(1kHz)의 듀티로 속도 조절

### 2단계: 엔코더 RPM 측정
TIM3 Encoder Mode(TI1 and TI2)로 100ms마다 펄스를 읽어 RPM으로 환산(7ppr × 50 = 350펄스/회전), UART로 출력
