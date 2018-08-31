#include <catch2/catch.hpp>
#include <raylib/util.hpp>
#include <vector>

TEST_CASE("Util raylib::approx()", "[util][math]") {
    struct TestData {
        float number;
        float comparison;
    };

    const float epsilon = 0.0001f;
    INFO("Epsilon is: " << epsilon);

    SECTION("True tests") {
        const std::vector<TestData> data {
            { 0.1f, 0.09999f },
            { 0.1f, 0.10001f },
            { 0.2f, 0.19999f },
            { 0.2f, 0.20001f },
            { 1.0f, 0.99999f },
            { 2.0f, 1.99999f },
            { 1.0f, 1.00001f },
            { 2.0f, 2.00001f },
            { 1000.0f, 1000.01f },
            { 1000.0f, 999.99f },
            { 2411.0f, 2410.99f },
            { 2411.0f, 2411.01f }
        };

        for (auto &&element : data) {
            INFO(element.number << " is approximately " << element.comparison);
            CHECK(raylib::approx(element.number, element.comparison, epsilon));
        }
    }

    SECTION("False tests") {
        const std::vector<TestData> data {
            { 0.1f, 0.099f },
            { 0.1f, 0.101f },
            { 0.2f, 0.199f },
            { 0.2f, 0.201f },
            { 1.0f, 0.999f },
            { 2.0f, 1.999f },
            { 1.0f, 1.001f },
            { 2.0f, 2.001f },
            { 1000.0f, 1000.5f },
            { 1000.0f, 999.5f },
            { 2411.0f, 2410.5f },
            { 2411.0f, 2411.5f }
        };

        for (auto &&element : data) {
            INFO(element.number << " is not approximately " << element.comparison);
            CHECK_FALSE(raylib::approx(element.number, element.comparison, epsilon));
        }
    }
}
