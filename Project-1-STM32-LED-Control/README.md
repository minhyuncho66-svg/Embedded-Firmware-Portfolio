# Project-1: STM32 LED Control

## 개요
STM32 Nucleo-F411RE 보드로 
GPIO, PWM, 버튼 입력을 활용한 LED 제어 프로젝트

## 하드웨어
- STM32 Nucleo-F411RE
- 내장 LED (PA5, LD2)
- 내장 버튼 (PC13, B1)

## 구현 과정 (단계별)

### 1단계 (Day 12): GPIO Blink
HAL_GPIO_WritePin(), HAL_Delay()로 
LED를 0.5초 간격으로 깜빡이는 기본 동작 구현

### 2단계 (Day 13): PWM 밝기 조절
TIM2_CH1을 PWM으로 설정(ARR=999), 
__HAL_TIM_SET_COMPARE()로 밝기를 
0→999→0으로 서서히 변화시키는 
"숨쉬기 LED" 효과 구현

### 3단계 (Day 14): 버튼 입력 (최종 코드)
기존 PWM 로직을 버튼 상태에 따라 
조건부로 실행하도록 확장. 
버튼(B1)을 누르면 최대밝기(999), 떼면 꺼짐(0)

## 2주차와의 연결 (핵심 발견)
- F12로 HAL_GPIO_WritePin() 내부를 열어서 
  GPIOx->BSRR (구조체 포인터+화살표 연산자) 확인
- main.h에서 #define B1_Pin GPIO_PIN_13 매크로를 
  직접 찾아서 CubeMX 설정이 코드로 
  어떻게 변환되는지 이해함
- SFR 뷰어로 TIM2->CCR1 레지스터 값이 
  실제로 999(0x3e7)로 바뀌는 것을 
  디버그 모드에서 직접 확인함

## 배운 것
- CubeMX 환경설정 → 코드 생성 → 
  실제 하드웨어 업로드 전체 사이클
- 순서(로직)를 먼저 한글로 설계하고 
  코드로 옮기는 습관
- 디버깅: 브레이크포인트, SFR 뷰어 활용법