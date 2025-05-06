#pragma once

#include "json.hpp"

#include <string>
#include <vector>

#include <cstdint>

int test_library(int num);

namespace routing_json {
    typedef struct Coordinate {
        double m_lon;
        double m_lat;
    }Coordinate;

    typedef struct ConnInfo {
        uint64_t m_Id;
        uint32_t m_Type;
        nlohmann::json m_propertyJson;
    }ConnInfo;

    class Item {
    protected:
        uint64_t m_id;

        std::vector<ConnInfo> m_nextConnInfoList;
        std::vector<ConnInfo> m_prevConnInfoList;

        nlohmann::json m_propertyJson;
    };

    class Link {
    private:
        uint64_t m_id;
        std::vector<Coordinate> m_shape;

        std::vector<ConnInfo> m_nextConnInfoList;
        std::vector<ConnInfo> m_prevConnInfoList;

        nlohmann::json m_propertyJson;
    public:
        Link(uint64_t id, const std::vector<Coordinate>& shape);

        void setId(uint64_t id);
        [[nodiscard]] uint64_t getId() const;
        void setShape(const std::vector<Coordinate>& shape);
        [[nodiscard]] std::vector<Coordinate> getShape() const;

        void addNextConnInfo(const ConnInfo& nextConnInfo);
        [[nodiscard]] std::vector<ConnInfo> getNextConnInfoList() const;
        void addPrevConnInfo(const ConnInfo& prevConnInfo);
        [[nodiscard]] std::vector<ConnInfo> getPrevConnInfoList() const;

        void addProperty(const std::string& name, const nlohmann::json& property);
        [[nodiscard]] nlohmann::json getProperty(const std::string& name) const;

        [[nodiscard]] nlohmann::json toGeoJson() const;
    };

    class Node {
    private:
        uint64_t m_id;
        Coordinate m_coord;

        std::vector<ConnInfo> m_nextConnInfoList;
        std::vector<ConnInfo> m_prevConnInfoList;

        nlohmann::json m_propertyJson;
    public:
    };


} // routing_json

