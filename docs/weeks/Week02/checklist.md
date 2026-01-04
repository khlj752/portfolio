# Week 2: First Triangle (Hello World of Graphics)

## Goal
화면에 삼각형 하나를 그리는 것. 그래픽스 프로그래머에게 가장 위대한 첫걸음.

## To-Do List

### 1. DirectX 12 Initialization (Part 2)
- [ ] **Descriptor Heap**:
    - [ ] RTV(Render Target View)용 힙 생성
    - [ ] SwapChain 버퍼에 대한 RTV 생성 및 핸들 연결
- [ ] **Command Allocator & List**:
    - [ ] 프레임별 `CommandAllocator` 생성
    - [ ] `CommandList` 생성 및 Reset 로직

### 2. Resources & Pipeline
- [ ] **Vertex Buffer**:
    - [ ] 삼각형 정점(Vertex) 구조체 정의 (Position, Color)
    - [ ] Upload Heap에 데이터 복사 -> Default Heap으로 전송 (혹은 단순히 Upload Heap 사용)
- [ ] **Root Signature**:
    - [ ] 가장 단순한 형태(Empty) 혹은 Vertex Shader 입력 정의
- [ ] **Shaders**:
    - [ ] `shaders.hlsl` 작성 (VS, PS)
    - [ ] `D3DCompile` 혹은 `dxc`를 이용한 쉐이더 컴파일
- [ ] **PSO (Pipeline State Object)**:
    - [ ] `D3D12_GRAPHICS_PIPELINE_STATE_DESC` 채우기 (Input Layout, Root Signature, VS/PS 바이트코드 등)

### 3. Rendering Loop
- [ ] **Synchronization**:
    - [ ] Fence 객체 및 Event 생성
    - [ ] `WaitForPreviousFrame` (GPU가 다 그릴 때까지 CPU 대기 - 초기에는 단순하게)
- [ ] **Record Commands**:
    - [ ] `ResourceBarrier` (Present -> RenderTarget)
    - [ ] `ClearRenderTargetView` (화면 지우기)
    - [ ] `DrawInstanced` (삼각형 그리기!)
    - [ ] `ResourceBarrier` (RenderTarget -> Present)
- [ ] **Present**:
    - [ ] `SwapChain->Present(1, 0)` (V-Sync On)

## Study Points
- Root Signature가 무엇인지? (GPU 파이프라인에 연결되는 데이터 슬롯 개념)
- PSO가 왜 불변(Immutable)인지? (드라이버 최적화 연관성)
