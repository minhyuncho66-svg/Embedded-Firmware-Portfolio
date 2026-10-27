# 전동화 펌웨어/ECU 제어 포트폴리오

자동차 전동화 펌웨어 엔지니어(인버터, 컨버터, BMS, 모터 제어 SW)를 목표로
STM32 기반 통신·센서·제어 프로젝트를 설계하고 구현한 기록입니다.

# 프로젝트 목표
- C언어 기초를 STM32 실전 프로젝트에 적용
- 자동차 임베디드 실무(BMS, 레지스터 제어)와 연결된 학습 설계

# 프로젝트 목록
STM32 실전 프로젝트 (자기주도)
- [Project 1: STM32 LED Control (GPIO/PWM)](./Project-1-STM32-LED-Control)
- [Project 2: STM32 UART Communication (인터럽트/링버퍼)](./Project-2-STM32-UART-Communication)
- [Project 3: STM32 Temperature Logger (I2C, BMP280, OLED)](./Project-3-STM32-Temperature-Logger)
- Project 4: STM32 Motor Control (진행 예정)

# 진행 현황
| 주요 내용 | 진행 상태 |
| :--- | :---: |
| STM32CubeIDE 환경구축, GPIO/PWM/버튼 제어 | 완료 |
| UART 통신, 링 버퍼, 명령어 프로토콜 | 완료 |
| I2C, BMP280 온도센서, SSD1306 OLED | 완료 |

```text
Embedded-Firmware-Portfolio/
├── Project-1-STM32-LED-Control/
├── Project-2-STM32-UART-Communication/ 
├── Project-3-STM32-Temperature-Logger/
└──Project-4-STM32-Motor-Controller/
```

# 사용 기술 / 도구
- 언어: C
- IDE: STM32CubeIDE
- 보드: STM32 Nucleo-F411RE
- 버전관리: Git / GitHub Desktop

# 학습 방식
1. **이론 학습**: 유튜브/책/AI로 개념 파악, 손으로 그림 그리기
2. **예측하기**: 코드 짜기 전 스스로 답을 먼저 추측
3. **코드 실습**: 직접 설계 + 타이핑 (막히면 AI를 이용한 참고)
4. **기록하기**: 배운 것, 예측이 틀린 이유, 시행착오 정리
