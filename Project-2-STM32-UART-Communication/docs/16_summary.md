#16 
학습 내용
- UART 이론(TX/RX, 보레이트, 데이터프레임) 학습
- CubeMX에서 USART2(115200bps) 설정
- HAL_UART_Transmit()으로 1초마다 "Hello STM32!" 송신하는 코드 작성
- Putty로 실제 터미널 통신 확인

- HAL_UART_Transmit(&huart2, msg, sizeof(msg), 100)를 사용해서 문자열을 송신.
  - &huart2: 어떤 UART 채널을 쓸지 지정
  - msg: 보낼 데이터
  - sizeof(msg): 보낼 길이
  - 100: 최대 대기시간(ms)"
