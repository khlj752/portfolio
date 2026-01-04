# Week 8: GPU Particles (Compute Shader)

## Goal
적 처치 시 화려하게 터지는 이펙트 구현. CPU 부하를 주지 않고 GPU의 연산 능력을 활용한다.

## To-Do List

### 1. Compute Shader Setup
- [ ] **Pipeline**: Compute PSO 생성.
- [ ] **Resources**:
    - [ ] Particle Pool (Structured Buffer): 위치, 속도, 수명 정보.
    - [ ] Dead List / System Buffer: 파티클 생성/소멸 관리용 카운터.

### 2. Implementation
- [ ] **Spawn (Emit)**:
    - [ ] 적이 죽은 위치에서 이벤트 발생 -> Compute Shader에 생성 요청.
- [ ] **Update (simulate)**:
    - [ ] `CS_Update`: 속도에 따라 위치 이동 + 중력 적용 + 수명 감소.
- [ ] **Render**:
    - [ ] `DrawInstancedIndirect` 또는 `DrawInstanced` 사용.
    - [ ] Geometry Shader를 써서 Point -> Quad로 확장하거나, Vertex Shader에서 확장.

### 3. Integration
- [ ] 적 사망 시 -> 파티클 펑! (색상과 속도 랜덤화)

## Visuals
- Additive Blending (빛나는 효과) 적용.
- Bloom 이펙트 (시간 남으면 도전).
