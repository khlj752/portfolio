# Week 1: The Foundation - Window & Initialization

## Goal
검은 화면을 띄우고, 종료 버튼을 누르면 정상적으로 꺼지는 Win32 애플리케이션 완성. DX12 초기화의 첫 단추 끼우기.

## To-Do List

### 1. Project Scaffolding
- [ ] `src/main.cpp` 엔트리 포인트 정리 (Console vs Windows Subsystem 결정 및 설정)
- [ ] `CMakeLists.txt` 라이브러리 링크 확인 (`d3d12.lib`, `dxgi.lib`, `d3dcompiler.lib`)

### 2. Window Class Implementation
- [ ] **Window Class Design**: `Window.h` / `Window.cpp` 생성
    - [ ] RAII 패턴 적용: 생성자에서 `CreateWindow`, 소멸자에서 `DestroyWindow`
    - [ ] `WNDCLASSEX` 설정 및 `RegisterClassEx` 호출
- [ ] **Message Loop**:
    - [ ] `PeekMessage`를 사용한 Non-blocking Loop 구현 (게임 루프용)
    - [ ] `WM_CLOSE`, `WM_DESTROY`, `WM_QUIT` 메시지 처리
- [ ] **WndProc Connection**:
    - [ ] `GWLP_USERDATA`를 활용하여 정적(Static) WndProc와 멤버 함수 WndProc 연결

### 3. DirectX 12 Initialization (Part 1)
- [ ] **Device Creation**:
    - [ ] `D3D12CreateDevice` 호출 (실패 시 Warp Adapter 시도 로직 포함?)
    - [ ] Debug Layer 활성화 (`ID3D12Debug`)
- [ ] **Command Queue**:
    - [ ] `D3D12_COMMAND_QUEUE_DESC` 작성 및 `CreatCommandQueue` (Type: DIRECT)
- [ ] **SwapChain**:
    - [ ] `IDXGIFactory4` 생성 -> `CreateSwapChainForHwnd` 호출
    - [ ] Double Buffering (BufferCount = 2) 설정

## Technical Considerations (Questions & Answers)
- **Q**: `WinMain` vs `main`? -> `main` for easy debugging.
- **Q**: Exception Handling? -> `HRESULT` 검사 매크로(`ThrowIfFailed` 등) 만들 필요 있음.
