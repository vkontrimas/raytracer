#include <catch2/catch.hpp>
#include <raylib/scene.hpp>
#include <raylib/surfaces/sphere.hpp>

using namespace raylib;

TEST_CASE("Scene initialization", "[scene][init]") {
    SECTION("Default") {
        Scene scene;
    }
}
