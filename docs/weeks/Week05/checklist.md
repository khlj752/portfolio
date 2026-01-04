# Week 5: The Horde - Hardware Instancing

## Goal
단 한 번의 그리기 명령(`DrawInstanced`)으로 수천 개의 큐브를 화면에 띄운다. (엔진 성능의 첫 번째 마일스톤)

## To-Do List

### 1. Instancing Basics
- [ ] **Concept**: 같은 Mesh를 위치/회전/색상만 다르게 여러 번 그리기
- [ ] **Data Structure**:
    - [ ] Instance Data 구조체 정의 (WorldMatrix, Color 등)
    - [ ] `std::vector<InstanceData>` 관리

### 2. Implementation Approach (Choose One)
- [ ] **Method A: Vertex Buffer Instancing**:
    - [ ] Instance Data를 별도의 Vertex Buffer에 담아 Input Assembler에 바인딩 (Input Layout 수정 필요).
    - [ ] 구현이 쉽고 표준적임.
- [ ] **Method B: Structured Buffer (SRV)**:
    - [ ] Instance Data를 Structured Buffer에 담아 VS에서 `SV_InstanceID`로 인덱싱하여 읽음.
    - [ ] 더 유연하고 모던한 방식 (권장).

### 3. Engine Update
- [ ] **Scene Management**: 10,000개의 큐브 위치를 랜덤하게 초기화
- [ ] **Render Loop**:
    - [ ] 매 프레임 Instance Data 버퍼 업데이트 (Map/Unmap 또는 Copy)
    - [ ] `DrawIndexedInstanced(indexCount, 10000, 0, 0, 0)` 호출

## Performance Check
- 1,000개 vs 10,000개 vs 100,000개 프레임 비교 및 기록 (`dev_log.md`)
