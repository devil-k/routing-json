add_executable(routing_json_test test.cpp)

target_link_libraries(routing_json_test
    PRIVATE
        routing_json
        nlohmann_json
)
