cmake_minimum_required(VERSION 3.31)

add_executable(MyEngine 
    src/main.cpp
    src/Core/Window.cpp
)

target_include_directories(MyEngine PRIVATE ${CMAKE_SOURCE_DIR}/include)

# DirectX 12 라이브러리 링크
target_link_libraries(MyEngine PRIVATE
    d3d12
    dxgi
    d3dcompiler
    user32
)

# (선택 사항) 유니코드 문자셋 사용 설정 (L"String" 사용 시 필요)
target_compile_definitions(MyEngine PRIVATE UNICODE _UNICODE)