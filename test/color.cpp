#include <catch2/catch.hpp>
#include <raylib/color.hpp>

using namespace raylib;

TEST_CASE("Color initialization", "[color][init]") {
    SECTION("Default") {
        Color color;
        CHECK(color.r == 0.0f);
        CHECK(color.g == 0.0f);
        CHECK(color.b == 0.0f);
        CHECK(color.a == 1.0f);
    }

    SECTION("RGB, default A") {
        Color color(1.0f, 2.0f, 3.0f);
        CHECK(color.r == 1.0f);
        CHECK(color.g == 2.0f);
        CHECK(color.b == 3.0f);
        CHECK(color.a == 1.0f);
    }

    SECTION("RGBA") {
        Color color(1.0f, 2.0f, 3.0f, 0.5f);
        CHECK(color.r == 1.0f);
        CHECK(color.g == 2.0f);
        CHECK(color.b == 3.0f);
        CHECK(color.a == 0.5f);
    }
}
