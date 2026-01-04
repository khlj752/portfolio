# Week 7: Collision & Spartial Partitioning

## Goal
수많은 적과 플레이어의 총알 간 충돌을 효율적으로 계산한다. O(N^2)을 O(N)으로 줄이기.

## To-Do List

### 1. Collision Basics
- [ ] **Shapes**: Sphere vs AABB (Axis-Aligned Bounding Box)
    - [ ] AABB 충돌 검사 함수 구현 (가장 비용이 저렴)

### 2. Spatial Partitioning (Grid System)
- [ ] **Concept**: 맵을 격자(Grid)로 나누고, 같은 칸에 있는 애들끼리만 충돌 검사.
- [ ] **Uniform Grid Implementation**:
    - [ ] `std::vector<int> cells[GRID_WIDTH * GRID_HEIGHT]`
    - [ ] 매 프레임 객체 위치에 따라 셀 등록 및 갱신 (Insert/Clear)
    - [ ] *주의*: 객체가 셀 경계에 걸쳐 있을 때 처리 (두 셀 모두 등록 등)

### 3. Weapon System
- [ ] **Bullets**: 총알도 오브젝트 풀(Object Pool)로 관리.
- [ ] **Hit Detection**:
    - [ ] 총알이 속한 셀과 인접 셀의 적들만 검사.
    - [ ] 충돌 시 적 HP 감소 및 상태 변경 (Dead).

## Challenge
- 충돌 처리 로직도 멀티스레딩이 가능한가? (Parallel_for)
