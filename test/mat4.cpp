#include <catch2/catch.hpp>
#include <raylib/mat4.hpp>

using namespace raylib;

TEST_CASE("Mat4 initialization", "[mat4][init]") {
    SECTION("Default") {
        Mat4 mat4;
        CHECK(mat4.m11 == 0.0f);
        CHECK(mat4.m12 == 0.0f);
        CHECK(mat4.m13 == 0.0f);
        CHECK(mat4.m14 == 0.0f);
        CHECK(mat4.m21 == 0.0f);
        CHECK(mat4.m22 == 0.0f);
        CHECK(mat4.m23 == 0.0f);
        CHECK(mat4.m24 == 0.0f);
        CHECK(mat4.m31 == 0.0f);
        CHECK(mat4.m32 == 0.0f);
        CHECK(mat4.m33 == 0.0f);
        CHECK(mat4.m34 == 0.0f);
        CHECK(mat4.m41 == 0.0f);
        CHECK(mat4.m42 == 0.0f);
        CHECK(mat4.m43 == 0.0f);
        CHECK(mat4.m44 == 0.0f);
    }

    SECTION("Identity") {
        SECTION("1.0f") {
            Mat4 mat4(1.0f);
            CHECK(mat4.m11 == 1.0f);
            CHECK(mat4.m12 == 0.0f);
            CHECK(mat4.m13 == 0.0f);
            CHECK(mat4.m14 == 0.0f);
            CHECK(mat4.m21 == 0.0f);
            CHECK(mat4.m22 == 1.0f);
            CHECK(mat4.m23 == 0.0f);
            CHECK(mat4.m24 == 0.0f);
            CHECK(mat4.m31 == 0.0f);
            CHECK(mat4.m32 == 0.0f);
            CHECK(mat4.m33 == 1.0f);
            CHECK(mat4.m34 == 0.0f);
            CHECK(mat4.m41 == 0.0f);
            CHECK(mat4.m42 == 0.0f);
            CHECK(mat4.m43 == 0.0f);
            CHECK(mat4.m44 == 1.0f);
        }

        SECTION("2.0f") {
            Mat4 mat4(2.0f);
            CHECK(mat4.m11 == 2.0f);
            CHECK(mat4.m12 == 0.0f);
            CHECK(mat4.m13 == 0.0f);
            CHECK(mat4.m14 == 0.0f);
            CHECK(mat4.m21 == 0.0f);
            CHECK(mat4.m22 == 2.0f);
            CHECK(mat4.m23 == 0.0f);
            CHECK(mat4.m24 == 0.0f);
            CHECK(mat4.m31 == 0.0f);
            CHECK(mat4.m32 == 0.0f);
            CHECK(mat4.m33 == 2.0f);
            CHECK(mat4.m34 == 0.0f);
            CHECK(mat4.m41 == 0.0f);
            CHECK(mat4.m42 == 0.0f);
            CHECK(mat4.m43 == 0.0f);
            CHECK(mat4.m44 == 2.0f);
        }
    }

    SECTION("Initializer list") {
        SECTION("Normal") {
            Mat4 mat4 = {
                1.0f,   2.0f,   3.0f,   4.0f,
                5.0f,   6.0f,   7.0f,   8.0f,
                9.0f,   10.0f,  11.0f,  12.0f,
                13.0f,  14.0f,  15.0f,  16.0f
            };

            CHECK(mat4.m11 == 1.0f);
            CHECK(mat4.m12 == 2.0f);
            CHECK(mat4.m13 == 3.0f);
            CHECK(mat4.m14 == 4.0f);
            CHECK(mat4.m21 == 5.0f);
            CHECK(mat4.m22 == 6.0f);
            CHECK(mat4.m23 == 7.0f);
            CHECK(mat4.m24 == 8.0f);
            CHECK(mat4.m31 == 9.0f);
            CHECK(mat4.m32 == 10.0f);
            CHECK(mat4.m33 == 11.0f);
            CHECK(mat4.m34 == 12.0f);
            CHECK(mat4.m41 == 13.0f);
            CHECK(mat4.m42 == 14.0f);
            CHECK(mat4.m43 == 15.0f);
            CHECK(mat4.m44 == 16.0f);
        }

        SECTION("Throws") {
            SECTION("Too small") {
                auto lambdaHack = [&]() {
                    Mat4 mat4 = {
                        1.0f,   2.0f,   3.0f,   4.0f,
                        5.0f,   6.0f,   7.0f,   8.0f,
                        9.0f,   10.0f,  11.0f,  12.0f,
                        13.0f,  14.0f,  15.0f
                    };
                };
                REQUIRE_THROWS_AS(lambdaHack(), std::invalid_argument);
            }

            SECTION("Too big") {
                auto lambdaHack = [&]() {
                    Mat4 mat4 = {
                        1.0f,   2.0f,   3.0f,   4.0f,
                        5.0f,   6.0f,   7.0f,   8.0f,
                        9.0f,   10.0f,  11.0f,  12.0f,
                        13.0f,  14.0f,  15.0f,  16.0f, 17.0f
                    };
                };
                REQUIRE_THROWS_AS(lambdaHack(), std::invalid_argument);
            }
        }
    }
}

TEST_CASE("Comparison operators", "[mat4][operators]") {
    Mat4 a = {
        1.0f,   2.0f,   3.0f,   4.0f,
        5.0f,   6.0f,   7.0f,   8.0f,
        9.0f,   10.0f,  11.0f,  12.0f,
        13.0f,  14.0f,  15.0f,  16.0f
    };

    Mat4 b(1.0f);

    Mat4 c = {
        1.0f,   2.0f,   3.0f,   4.0f,
        5.0f,   6.0f,   7.0f,   8.0f,
        9.0f,   10.0f,  11.0f,  12.0f,
        13.0f,  14.0f,  15.0f,  16.0f
    }; 

    Mat4 d(1.0f);

    SECTION("a == c") {
        REQUIRE(a == c);
        REQUIRE_FALSE(a != c);
    }

    SECTION("b == d") {
        REQUIRE(b == d);
        REQUIRE_FALSE(b != d);
    }

    SECTION("b != a") {
        REQUIRE(b != a);
        REQUIRE_FALSE(b == a);
    }

    SECTION("d != c") {
        REQUIRE(d != c);
        REQUIRE_FALSE(d == c);
    }
}
