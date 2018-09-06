#include <catch2/catch.hpp>
#include <raylib/scene.hpp>
#include <raylib/surfaces/sphere.hpp>

using namespace raylib;

TEST_CASE("Scene initialization", "[scene][init]") {
    SECTION("Default") {
        Scene scene;
    }
}

TEST_CASE("Scene ray intersection", "[scene][ray]") {
    Scene scene;
    Sphere sphere;
    scene.addObject(Object(Vec3(0.0f, 0.0f, -10.0f), &sphere));
    scene.addObject(Object(Vec3(0.0f, 0.0f, -20.0f), &sphere));

    SECTION("Hit") {
        Ray ray(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
        HitInfo result = scene.checkHit(ray);
        INFO(ray << "\nResult position: " << result.position << "\nResult normal" << result.normal);
        CHECK(result.hit);
        CHECK(result.position.approx(Vec3(0.0f, 0.0f, -9.0f)));
        CHECK(result.normal.approx(Vec3(0.0f, 0.0f, 1.0f)));
    }

    SECTION("Hit 2") {
        Ray ray(Vec3(0.5f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
        HitInfo result = scene.checkHit(ray);
        INFO(ray << "\nResult position: " << result.position << "\nResult normal" << result.normal);
        CHECK(result.hit);
        // TODO
    }

    SECTION("Scrape") {
        Ray ray(Vec3(0.99999f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
        HitInfo result = scene.checkHit(ray);
        INFO(ray << "\nResult position: " << result.position << "\nResult normal" << result.normal);
        CHECK(result.hit);
        // TODO
    }

    SECTION("Miss") {
        Ray ray(Vec3(1.1f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -1.0f));
        INFO(ray);
        HitInfo result = scene.checkHit(ray);
        CHECK_FALSE(result.hit);
    }

    SECTION("Opposite direction") {
        Ray ray(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f));
        INFO(ray);
        HitInfo result = scene.checkHit(ray);
        CHECK_FALSE(result.hit);
    }
}
