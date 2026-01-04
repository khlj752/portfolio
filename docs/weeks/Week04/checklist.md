# Week 4: Textures & Input

## Goal
큐브에 이미지를 입히고(Texturing), 키보드와 마우스로 카메라를 조종(FPS Style)한다.

## To-Do List

### 1. Texture Loading
- [ ] **Image Library**: `stb_image.h` 통합
- [ ] **Texture Resource**:
    - [ ] 이미지를 읽어서 GPU 용 Texture 2D 리소스 생성
    - [ ] Upload Heap을 통해 Texture Data 복사 (UpdateSubresources)
- [ ] **SRV (Shader Resource View)**:
    - [ ] SRV Descriptor 생성 (Descriptor Heap Indexing)
    - [ ] 쉐이더에서 Texture2D 및 Sampler 사용

### 2. Input System
- [ ] **Input Class**:
    - [ ] Win32 메시지(`WM_KEYDOWN`, `WM_MOUSEMOVE` 등) 캡처
    - [ ] `GetKey(KeyCode)` 형태의 질의(Polling) 인터페이스 제공
    - [ ] 마우스 델타(이동량) 계산 (카메라 회전용)

### 3. FPS Camera Controller
- [ ] **Movement**: WASD 키로 카메라 위치 이동 (Forward 벡터 기반)
- [ ] **Rotation**: 마우스 이동으로 Pitch/Yaw 회전
- [ ] **Constraint**: Pitch 제한 (고개가 뒤집히지 않도록 -90도~90도)

## Optimization Note
- 텍스처 업로드 시 `GenerateMips` 처리 여부 고민 (DX12는 자동 생성 함수가 없음, 쉐이더로 만들거나 미리 생성된 DDS 사용)
