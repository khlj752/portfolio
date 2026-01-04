# Week 9: Gameplay Loop & UI

## Goal
기술 데모가 아닌 '게임'으로 만든다. 시작, 플레이, 종료, 재시작의 흐름을 완성.

## To-Do List

### 1. UI System (ImGui Integration)
- [ ] **ImGui Setup**: DX12 백엔드 연결.
- [ ] **HUD (Heads-Up Display)**:
    - [ ] 플레이어 HP 바
    - [ ] 적 처치 수 (Kill Count)
    - [ ] 레벨업 선택지 (카드 선택 UI)

### 2. Game State Management
- [ ] **States**: `Title` -> `InGame` -> `Paused` -> `GameOver` -> `Title`
- [ ] **Progression**:
    - [ ] 적 웨이브 관리 (시간이 지날수록 더 많이, 더 강하게)
    - [ ] 플레이어 스탯 업그레이드 로직

### 3. Save/Load (Serialization)
- [ ] **Data**: 최고 기록(High Score), 해금 요소.
- [ ] **Format**: JSON (`nlohmann/json`) 또는 바이너리 파일 입출력.

## Finishing Touches
- 사운드 연동 (배경음악, 타격음).
- 게임 밸런스 조정 (너무 어렵거나 쉽지 않게).
