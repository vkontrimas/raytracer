#include <catch2/catch.hpp>
#include <raylib/camera.hpp>

using namespace raylib;

TEST_CASE("Camera initialization", "[camera][init]") {
    SECTION("Position and direction") {
        Camera camera(Vec3(10.0f, 9.0f, 8.0f), Vec3(0.0f, 0.0f, -1.0f));
        REQUIRE(camera.position() == Vec3(10.0f, 9.0f, 8.0f));
        REQUIRE(camera.direction() == Vec3(0.0f, 0.0f, -1.0f));
        REQUIRE(camera.fov() == 80.0f);
    }

    SECTION("Position, diretion and fov") {
        Camera camera(Vec3(10.0f, 9.0f, 8.0f), Vec3(0.0f, 0.0f, -1.0f), 123.0f);
        REQUIRE(camera.position() == Vec3(10.0f, 9.0f, 8.0f));
        REQUIRE(camera.direction() == Vec3(0.0f, 0.0f, -1.0f));
        REQUIRE(camera.fov() == 123.0f);
    }
}

TEST_CASE("Camera::lookAt()", "[camera][math]") {
    SECTION("At origin") {
        Camera camera(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
        SECTION("X") {
            camera.lookAt(Vec3(10.0f, 0.0f, 0.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(1.0f, 0.0f, 0.0f)));
        }
        SECTION("-X") {
            camera.lookAt(Vec3(-10.0f, 0.0f, 0.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(-1.0f, 0.0f, 0.0f)));
        }
        SECTION("Y") {
            camera.lookAt(Vec3(0.0f, 10.0f, 0.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(0.0f, 1.0f, 0.0f)));
        }
        SECTION("-Y") {
            camera.lookAt(Vec3(0.0f, -10.0f, 0.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(0.0f, -1.0f, 0.0f)));
        }
        SECTION("Z") {
            camera.lookAt(Vec3(0.0f, 0.0f, 10.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(0.0f, 0.0f, 1.0f)));
        }
        SECTION("-Z") {
            camera.lookAt(Vec3(0.0f, 0.0f, -10.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(0.0f, 0.0f, -1.0f)));
        }
        SECTION("Interesting vector") {
            camera.lookAt(Vec3(6.0f, 5.0f, 11.0f));
            INFO(camera.direction());
            REQUIRE(camera.direction().approx(Vec3(0.4447f, 0.3706f, 0.8153f)));
        }
    }

    SECTION("Away from origin") {
        Camera camera(Vec3(10.0f, 0.0f, 5.0f), Vec3(0.0f, 0.0f, -1.0f));
        camera.lookAt(Vec3(3.0f, 10.0f, 17.0f));
        INFO(camera.direction());
        REQUIRE(camera.direction().approx(Vec3(-0.4089f, 0.5842f, 0.7010f)));
    }
}
