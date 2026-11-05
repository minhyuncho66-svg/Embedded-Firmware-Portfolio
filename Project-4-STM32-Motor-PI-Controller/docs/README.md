# Project-4: STM32 Motor Control

## 개요
STM32 Nucleo-F411RE와 TB6612FNG 모터 드라이버로 DC 모터(GA12-N20)의 구동과 엔코더 RPM 측정을 구현한 프로젝트

## 시연

### 모터 구동
TB6612FNG로 정방향 회전, PWM 듀티로 속도 조절

https://github.com/user-attachments/assets/2c0e020b-39d7-4b9f-a166-07e06b6fec71

### RPM 측정
엔코더 펄스를 100ms마다 읽어 RPM으로 환산, PuTTY로 실시간 출력

https://github.com/user-attachments/assets/0917b1c2-d982-4ada-a075-78794d8c30f2

### OLED 출력
측정한 RPM을 OLED에 표시

https://github.com/user-attachments/assets/1c6b889e-4730-4284-9381-92e8c08734d1

## 하드웨어
- STM32 Nucleo-F411RE
- TB6612FNG 모터 드라이버
- GA12-N20 DC 모터 (엔코더 내장, 감속비 1:50, 7ppr)

## 구현 과정 (단계별)

### 1단계: 모터 구동
TB6612FNG의 AIN1/AIN2를 GPIO로 제어해 방향을 정하고, TIM2 PWM(1kHz)의 듀티로 속도 조절

### 2단계: 엔코더 RPM 측정
TIM3 Encoder Mode(TI1 and TI2)로 100ms마다 펄스를 읽어 RPM으로 환산(7ppr × 50 = 350펄스/회전), UART로 출력

### 3단계: OLED 출력
측정한 RPM을 SSD1306 OLED에 표시
