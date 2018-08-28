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

    SECTION("Single value") {
        Color color(2.0f);
        CHECK(color.r == 2.0f);
        CHECK(color.g == 2.0f);
        CHECK(color.b == 2.0f);
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

TEST_CASE("Color equality operators", "[color][operators]") {
    Color a(1.0f, 2.0f, 3.0f, 0.2f);
    Color b(3.0f, 2.0f, 1.0f, 0.2f);

    SECTION("Equality") {
        SECTION("A") {
            CHECK(a == Color(1.0f, 2.0f, 3.0f, 0.2f));
            CHECK_FALSE(a == Color(10.0f, 2.0f, 3.0f, 0.2f));
            CHECK_FALSE(a == Color(1.0f, 20.0f, 3.0f, 0.2f));
            CHECK_FALSE(a == Color(1.0f, 2.0f, 30.0f, 0.2f));
            CHECK_FALSE(a == Color(1.0f, 2.0f, 3.0f, 0.8f));
        }

        SECTION("B") {
            CHECK(b == Color(3.0f, 2.0f, 1.0f, 0.2f));
            CHECK_FALSE(b == Color(0.0f, 2.0f, 1.0f, 0.2f));
            CHECK_FALSE(b == Color(3.0f, 0.0f, 1.0f, 0.2f));
            CHECK_FALSE(b == Color(3.0f, 2.0f, 0.0f, 0.2f));
            CHECK_FALSE(b == Color(3.0f, 2.0f, 1.0f, 0.5f));
        }

        SECTION("No side effects") {
            CHECK_FALSE(a == b);
            CHECK(a.r == 1.0f);
            CHECK(a.g == 2.0f);
            CHECK(a.b == 3.0f);
            CHECK(a.a == 0.2f);
            CHECK(b.r == 3.0f);
            CHECK(b.g == 2.0f);
            CHECK(b.b == 1.0f);
            CHECK(b.a == 0.2f);
        }
    }

    SECTION("Inequality") {
        SECTION("A") {
            CHECK(a != Color(10.0f, 2.0f, 3.0f, 0.2f));
            CHECK(a != Color(1.0f, 20.0f, 3.0f, 0.2f));
            CHECK(a != Color(1.0f, 2.0f, 30.0f, 0.2f));
            CHECK(a != Color(1.0f, 2.0f, 3.0f, 0.8f));
            CHECK_FALSE(a != Color(1.0f, 2.0f, 3.0f, 0.2f));
        }

        SECTION("B") {
            CHECK(b != Color(0.0f, 2.0f, 1.0f, 0.2f));
            CHECK(b != Color(3.0f, 0.0f, 1.0f, 0.2f));
            CHECK(b != Color(3.0f, 2.0f, 0.0f, 0.2f));
            CHECK(b != Color(3.0f, 2.0f, 1.0f, 0.5f));
            CHECK_FALSE(b != Color(3.0f, 2.0f, 1.0f, 0.2f));
        }

        SECTION("No side effects") {
            CHECK(a != b);
            CHECK(a.r == 1.0f);
            CHECK(a.g == 2.0f);
            CHECK(a.b == 3.0f);
            CHECK(a.a == 0.2f);
            CHECK(b.r == 3.0f);
            CHECK(b.g == 2.0f);
            CHECK(b.b == 1.0f);
            CHECK(b.a == 0.2f);
        }
    }
}
