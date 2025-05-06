add_library(routing_json)

# 소스/헤더 파일
target_sources(routing_json
    PRIVATE
        src/routing_json.cpp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/routing_json.h>
)

# include 디렉터리 설정
target_include_directories(routing_json
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# 외부 라이브러리 연결
target_link_libraries(routing_json
    PUBLIC nlohmann_json
)
