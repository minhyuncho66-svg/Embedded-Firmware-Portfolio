# Project-2: STM32 UART Communication

## 개요
STM32 Nucleo-F411RE로 UART 통신, 인터럽트 기반 수신, 링버퍼, 명령어 파싱을 구현한 프로젝트

## 구현 과정 (단계별)

### 1단계: UART 기초 송신
HAL_UART_Transmit()으로 1초마다 "Hello STM32!" 송신

### 2단계: 데이터 포맷팅
sprintf()로 가상 BMS 센서 데이터(온도, 전압)를 포맷팅해서 송신

### 3단계: RX 인터럽트 + 링버퍼
HAL_UART_Receive_IT()와 콜백 함수로 1바이트씩 수신, 링버퍼에 저장, Echo 기능 구현

### 4단계: 명령어 파싱 (최종)
링버퍼 데이터를 선형버퍼로 조립, strcmp()로 "LED_ON"/"LED_OFF" 명령어 인식, 실제 LED 원격 제어 성

**최종 코드는 main.c에서 확인 가능합니다.**

## Project-1과의 연결
- Project-1에서 쓴 LED 제어(HAL_GPIO_WritePin)를 UART 명령어 처리에 재활용

## 시행착오
### RX 인터럽트 콜백이 호출되지 않음
- TX는 되는데 RX(Echo)만 안 됨
- 콜백 첫 줄에 브레이크포인트를 걸었는데 문자를 입력해도 안 멈춤 → 콜백이 호출 자체가 안 되는 것
- stm32f4xx_it.c에 USART2_IRQHandler가 없는 걸 발견
- CubeMX NVIC Settings에서 USART2 global interrupt가 체크 안 돼 있었음 → 체크 후 Generate Code

## 배운 것
- 폴링 vs 인터럽트의 차이와 각각의 장단점
- 링버퍼(원형)와 선형버퍼의 역할 차이
