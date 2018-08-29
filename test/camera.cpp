#include <catch2/catch.hpp>
#include <raylib/camera.hpp>

using namespace raylib;

TEST_CASE("Camera initialization", "[camera][init]") {
    SECTION("Position and direction") {
        Camera camera(Vec3(10.0f, 9.0f, 8.0f), Vec3(0.0f, 0.0f, -1.0f));
        REQUIRE(camera.position() == Vec3(10.0f, 9.0f, 8.0f));
        REQUIRE(camera.direction() == Vec3(0.0f, 0.0f, -1.0f));
    }
}
