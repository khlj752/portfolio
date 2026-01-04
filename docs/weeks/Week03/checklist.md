# Week 3: 3D Visualization - Math & Camera

## Goal
2D 화면의 삼각형을 3D 공간의 큐브로 확장하고, 시점을 자유롭게 이동시킨다.

## To-Do List

### 1. Math Library
- [ ] **Selection**: GLM 라이브러리 사용 vs 직접 구현 (XMVECTOR 등 DirectXMath 추천)
- [ ] **Basic Types**: Vector3, Vector4, Matrix4x4, Quaternion 확인
- [ ] **Transformations**:
    - [ ] Translate, Rotate, Scale 행렬 계산 함수

### 2. Constant Buffer (Shader Resources)
- [ ] **CBV (Constant Buffer View)**:
    - [ ] 쉐이더에 `World`, `View`, `Projection` 행렬을 넘겨줄 버퍼 생성
    - [ ] Descriptor Heap (CBV_SRV_UAV) 설정
    - [ ] Root Signature에 CBV 슬롯 추가

### 3. Depth-Stencil Buffer
- [ ] **DSV (Depth Stencil View)**:
    - [ ] Depth 텍스처 리소스 생성
    - [ ] DSV Descriptor Heap 생성 및 View 생성
    - [ ] PSO에 Depth Format 및 Depth Test 설정 (Z-Buffering 활성화)

### 4. Camera System
- [ ] **Camera Class**:
    - [ ] Position, Forward, Up 벡터 관리
    - [ ] View Matrix 계산 (`XMMatrixLookAtLH`)
    - [ ] Projection Matrix 계산 (`XMMatrixPerspectiveFovLH`)
- [ ] **Integration**:
    - [ ] 매 프레임 카메라 행렬을 Constant Buffer에 업데이트

## Key Concepts
- 좌표계: 왼손 좌표계(DirectX) vs 오른손 좌표계(OpenGL)
- Row-major vs Column-major 행렬 메모리 레이아웃
