#include <catch2/catch.hpp>
#include <raylib/surfaces/sphere.hpp>

using namespace raylib;

TEST_CASE("Sphere initialization", "[surfaces][sphere][init]") {
    SECTION("No radius") {
        Sphere sphere;
        CHECK(sphere.radius() == 1.0f);
    }

    SECTION("Radius") {
        Sphere sphere(123.0f);
        CHECK(sphere.radius() == 123.0f);
    }
}

TEST_CASE("Sphere intersection", "[surfaces][sphere][math][ray]") {
    SECTION("Axis aligned") {
        Sphere sphere(1.0f);
        Vec3 position(0.0f, 0.0f, -10.0f);
        INFO(sphere);

        SECTION("Hit") {
            Ray ray(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            HitInfo result = sphere.checkHit(ray, position);
            INFO(ray << "\nResult position: " << result.position << "\nResult normal" << result.normal);
            CHECK(result.hit);
            CHECK(result.position.approx(Vec3(0.0f, 0.0f, -9.0f)));
            CHECK(result.normal.approx(Vec3(0.0f, 0.0f, 1.0f)));
        }

        SECTION("Hit 2") {
            Ray ray(Vec3(0.5f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            HitInfo result = sphere.checkHit(ray, position);
            INFO(ray << "\nResult position: " << result.position << "\nResult normal" << result.normal);
            CHECK(result.hit);
            // TODO
        }

        SECTION("Scrape") {
            Ray ray(Vec3(0.99999f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            HitInfo result = sphere.checkHit(ray, position);
            INFO(ray << "\nResult position: " << result.position << "\nResult normal" << result.normal);
            CHECK(result.hit);
            // TODO
        }

        SECTION("Miss") {
            Ray ray(Vec3(1.1f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray, position);
            CHECK_FALSE(result.hit);
        }

        SECTION("Opposite direction") {
            Ray ray(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f));
            INFO(ray);
            HitInfo result = sphere.checkHit(ray, position);
            CHECK_FALSE(result.hit);
        }
    }
}
