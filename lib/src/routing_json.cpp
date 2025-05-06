#include "routing_json.h"

using namespace routing_json;

int test_library(int num) {
    return num + 10;
}

Link::Link(const uint64_t id, const std::vector<Coordinate>& shape) {
    m_id = id;
    m_shape = shape;
}

void Link::setId(uint64_t id) {
    m_id = id;
}
uint64_t Link::getId() const {
    return m_id;
}

void Link::setShape(const std::vector<Coordinate>& shape) {
    m_shape = shape;
}
std::vector<Coordinate> Link::getShape() const {
    return m_shape;
}

void Link::addNextConnInfo(const ConnInfo &nextConnInfo) {
    m_nextConnInfoList.push_back(nextConnInfo);
}
std::vector<ConnInfo> Link::getNextConnInfoList() const {
    return m_nextConnInfoList;
}
void Link::addPrevConnInfo(const ConnInfo &prevConnInfo) {
    m_prevConnInfoList.push_back({prevConnInfo});
}
std::vector<ConnInfo> Link::getPrevConnInfoList() const {
    return m_prevConnInfoList;
}

void Link::addProperty(const std::string &name, const nlohmann::json &property) {
    m_propertyJson[name] = property;
}
nlohmann::json Link::getProperty(const std::string &name) const {
    return m_propertyJson[name];
}

nlohmann::json Link::toGeoJson() const {
    nlohmann::json geojson;

    geojson["type"] = "Feature";

    geojson["geometry"] = {
        {"type", "LineString"},
        {"coordinates", nlohmann::json::array()}
    };

    for (const auto& coord : m_shape) {
        geojson["geometry"]["coordinates"].push_back({coord.m_lon, coord.m_lat});
    }

    geojson["properties"] = m_propertyJson;

    // nextConnections 배열 추가
    nlohmann::json nextList = nlohmann::json::array();
    for (const auto& conn : m_nextConnInfoList) {
        nextList.push_back({
            {"id", conn.m_Id},
            {"type", conn.m_Type},
            {"property", conn.m_propertyJson}
        });
    }
    geojson["properties"]["nextConnections"] = nextList;

    // prevConnections 배열 추가
    nlohmann::json prevList = nlohmann::json::array();
    for (const auto& conn : m_prevConnInfoList) {
        prevList.push_back({
            {"id", conn.m_Id},
            {"type", conn.m_Type},
            {"property", conn.m_propertyJson}
        });
    }
    geojson["properties"]["prevConnections"] = prevList;

    return geojson;
}











