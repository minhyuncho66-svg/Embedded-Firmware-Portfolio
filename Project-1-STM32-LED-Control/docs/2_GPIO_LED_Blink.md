학습 내용
- HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, ...)과 HAL_Delay(500)으로
  "켜기→대기→끄기→대기" 순서의 0.5초 점멸 코드를 설계하고 보드에서 동작 확인
- HAL_Delay는 대기하는 동안 CPU가 다른 일을 못 하는 블로킹 방식임을 확인
  (→ 이후 UART 프로젝트에서 인터럽트를 쓰게 된 배경)
- HAL_GPIO_WritePin 내부를 직접 열어 구현 확인

학습 중 생긴 의문
- WritePin 내부에 GPIOx->BSRR = GPIO_Pin; 이 있는데 BSRR은 무엇이고
  이 문법은 앞서 연습한 구조체 포인터와 같은 것인가?

답변
- GPIOx는 GPIO_TypeDef 구조체를 가리키는 포인터이고 ->로 멤버(BSRR)에
  접근하는 방식은 구조체 포인터 문법과 동일함
- GPIOA는 ((GPIO_TypeDef *)GPIOA_BASE)로 정의되어 고정된 하드웨어
  주소를 구조체 포인터로 캐스팅한 것임
- 구조체 멤버가 __IO(volatile)로 선언된 것은 레지스터 값이 하드웨어에 의해
  바뀔 수 있어 컴파일러 최적화를 막기 위함
- BSRR: 하위 16비트에 1을 쓰면 해당 핀 set, 상위 16비트에 1을 쓰면 reset
