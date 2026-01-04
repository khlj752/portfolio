# Common Design Principles & Coding Standards

본 프로젝트는 구글 C++ 스타일 가이드와 RAII 패턴을 핵심 철학으로 삼습니다.

## 1. Google C++ Style Guide 기반 규칙
- **Naming**:
    - Types/Classes: `PascalCase` (e.g., `Window`, `GraphicsDevice`)
    - Functions: `PascalCase` (e.g., `Initialize()`, `Resize()`)
    - Variables: `snake_case` (e.g., `window_width`, `is_running`)
    - Member Variables: `snake_case` + trailing underscore (e.g., `width_`, `hwnd_`)
    - Constants: `kPascalCase` (e.g., `kMaxFrames`)
- **Formatting**:
    - Indent: 2 or 4 spaces (일관성 유지).
    - Limit function length.

## 2. RAII (Resource Acquisition Is Initialization)
- **원칙**: 리소스의 할당은 생성자에서, 해제는 소멸자에서 수행한다.
- **포인터 소유권**: `new`와 `delete`를 직접 사용하지 않는다.
    - 소유권 독점: `std::unique_ptr<T>`
    - 소유권 공유: `std::shared_ptr<T>` (꼭 필요한 경우에만)
    - 관찰자 (Non-owning): Raw Pointer (`T*`) 허용하되, 소유하지 않음.
- **DirectX 객체**: `Microsoft::WRL::ComPtr<T>` 사용 필수.
    - 예: `ComPtr<ID3D12Device> device_;`

## 3. Exception Handling
- **오류 처리**: 치명적인 오류(초기화 실패 등) 발생 시 예외(`std::runtime_error` 파생)를 던진다.
- **Fail Fast**: 문제가 발생한 시점에 즉시 크래시를 내거나 종료하여 디버깅을 돕는다.

## 4. Class Design
- **Rule of Zero/Five**: 소멸자를 정의했다면 이동/복사 생성자 및 대입 연산자도 명시적으로 처리(`default` or `delete`)한다.
- **Immutability**: 변경되지 않는 멤버 함수는 반드시 `const`로 선언한다.
