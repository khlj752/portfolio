# Week 6: Optimization & AI

## Goal
수만 개의 객체가 움직일 때 CPU 병목을 최소화하기 위한 데이터 구조 개선.

## To-Do List

### 1. Data-Oriented Design (DOD)
- [ ] **SoA (Structure of Arrays)**:
    - [ ] 기존: `struct GameObject { Vector3 pos; Vector3 vel; float hp; }` (AoS)
    - [ ] 변경: `struct TransformSystem { vector<Vector3> positions; vector<Vector3> velocities; }`
- [ ] **Reason**: CPU 캐시 히트율(Cache Hit Rate)을 높여 위치 업데이트 성능 극대화.

### 2. Simple AI (The Horde Behavior)
- [ ] **Logic**: 모든 적이 플레이어를 향해 직선 이동.
- [ ] **Update Loop**:
    - [ ] `vel = normalize(targetPos - myPos) * speed`
    - [ ] `pos += vel * deltaTime`
    - [ ] 이 루프를 SIMD(Vectorization) 친화적으로 작성 (자동 벡터화 유도).

### 3. Indirect Draw (Optional / Advanced)
- [ ] **GPU Culling**: 화면 밖의 적은 아예 그리지 않도록 GPU에서 판별 (Compute Shader) 후 그리기 명령 생성.
- [ ] *우선순위 낮음: Instancing만으로 충분하다면 생략 가능.*

## Debugging
- 프레임 드랍이 일어난다면 CPU 문제인지 GPU 문제인지 파악 (Visual Studio Profiler 사용)
