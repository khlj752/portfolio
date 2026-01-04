
# Window

## Structures
### WNDCLASS(WEX/EX)
- 구조체
- Window를 생성하기 위해, Window를 설명하는 설계도 

### MSG
- 구조체
- OS에서 발생한 Message를 담는 구조체
- 해당 Message는 Message Queue가 존재하는 Thread에서 전달 됨

## Functions
### RegisterClassEx
- WNDCLASS(WEX/EX)를 등록하는 함수
- CreateWindow를 호출하기 전에 호출 되어야 함
- 등록된 window class는 어플리케이션이 종료되면 자동으로 해제되나, dll인 경우 명시적으로 해제해야 함.

### CreateWindowEx
- 등록된 WNDCLASS를 사용하여 Window를 생성(인스턴스)하는 함수
- 창의 형태에 대한 정보를 전달 함

### AdjustWindowRect
- 클라이언트 영역의 크기를 정확하게 맞추기 위해 윈도우 전체 크기를 계산

## Message Loop
### PeekMessage
- 게임 엔진은 멈추면 안되기 때문에 PeekMessage를 사용
    - PeekMessage ( Non-Blocking )
    - GetMessage ( Blocking )

### TranslateMessage & DispatchMessage
- 꺼내온 메시지를 WndProc로 보냄

# Procedure
## Window Proc Callback
- 모든 이벤트가 들어오는 함수

## DefWindowProc
- 처리하지 않은 메시지들이 OS가 처리하도록 넘겨주는 함수 ( 창 이동, 최소화 등)