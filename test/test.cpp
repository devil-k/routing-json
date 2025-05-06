#include "routing_json.h"

#include <iostream>
#include <cstdio>

int main(void) {
    printf("hello world\n");

    printf("call library code[%d]\n", test_library(20));

    routing_json::Link link(2,
        std::vector<routing_json::Coordinate> {
            routing_json::Coordinate {10, 20},
            routing_json::Coordinate {30, 40},});

    link.addNextConnInfo(routing_json::ConnInfo{3,
        0,
        nlohmann::json {{"angle", 50}, {"distance", 50}}});
    link.addNextConnInfo(routing_json::ConnInfo{4,
        0,
        nlohmann::json {{"angle", 20}, {"distance", 50}}});

    link.addPrevConnInfo(routing_json::ConnInfo{1,
        0,
        nlohmann::json {{"angle", 20}, {"distance", 50}}});

    link.addProperty("length", nlohmann::json{"value", 30});
    link.addProperty("fare", nlohmann::json{"value", true});

    auto obj = link.toGeoJson();

    std::cout << obj.dump(2) << std::endl;

    printf("bye world!!\n");

    return 0;
}