#include <catch2/catch.hpp>
#include <raylib/vec3.hpp>

using namespace raylib;

TEST_CASE("Vec3 initialization", "[vec3][init]") {
    SECTION("Default") {
        Vec3 vector;
        CHECK(vector.x == 0.0f);
        CHECK(vector.y == 0.0f);
        CHECK(vector.z == 0.0f);
    }
    SECTION("With single scalar") {
        Vec3 vector(1337.0f);
        CHECK(vector.x == 1337.0f);
        CHECK(vector.y == 1337.0f);
        CHECK(vector.z == 1337.0f);
    }
    SECTION("With values") {
        Vec3 vector(1.0f, 2.0f, 3.0f);
        CHECK(vector.x == 1.0f);
        CHECK(vector.y == 2.0f);
        CHECK(vector.z == 3.0f);
    }
}
