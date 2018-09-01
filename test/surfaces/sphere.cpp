#include <catch2/catch.hpp>
#include <raylib/surfaces/sphere.hpp>

using namespace raylib;

TEST_CASE("Sphere initialization", "[surfaces][sphere][init]") {
    SECTION("Position and no radius") {
        Sphere sphere(Vec3(1.0f, 2.0f, 3.0f));
        CHECK(sphere.position() == Vec3(1.0f, 2.0f, 3.0f));
        CHECK(sphere.radius() == 1.0f);
    }

    SECTION("Position and radius") {
        Sphere sphere(Vec3(1.0f, 2.0f, 3.0f), 123.0f);
        CHECK(sphere.position() == Vec3(1.0f, 2.0f, 3.0f));
        CHECK(sphere.radius() == 123.0f);
    }
}
