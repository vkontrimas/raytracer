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

TEST_CASE("Sphere intersection", "[surfaces][shere][math][ray]") {
    SECTION("Axis aligned") {
        Sphere sphere(Vec3(0.0f, 0.0f, -10.0f), 1.0f);
        INFO(sphere);

        SECTION("Hit") {
            Ray ray(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray);
            CHECK(result.hit);
        }

        SECTION("Hit 2") {
            Ray ray(Vec3(0.5f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray);
            CHECK(result.hit);
        }

        SECTION("Scrape") {
            Ray ray(Vec3(0.99999f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray);
            CHECK(result.hit);
        }

        SECTION("Miss") {
            Ray ray(Vec3(1.1f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray);
            CHECK_FALSE(result.hit);
        }

        SECTION("Opposite direction") {
            Ray ray(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray);
            CHECK_FALSE(result.hit);
        }
    }
}
