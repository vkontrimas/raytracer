#include <catch2/catch.hpp>
#include <raylib/mat4.hpp>
#include <sstream>

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

TEST_CASE("Stream insertion operator", "[mat4][operators]") {
    using Catch::Matchers::Equals;

    std::stringstream stream;

    SECTION("A") {
        Mat4 matrix = {
            1.0f,   2.0f,   3.0f,   4.0f,
            5.0f,   6.0f,   7.0f,   8.0f,
            9.0f,   10.0f,  11.0f,  12.0f,
            13.0f,  14.0f,  15.0f,  16.0f
        };

        stream << matrix;
        REQUIRE_THAT(stream.str(), 
        Equals("Mat4[m1X: 1.000, 2.000, 3.000, 4.000 | m2X: 5.000, 6.000, 7.000, 8.000 | m3X: 9.000, 10.000, 11.000, 12.000 | m4X: 13.000, 14.000, 15.000, 16.000]"));
    }

    SECTION("B") {
        Mat4 matrix = {
            2.0f,   4.0f,   6.0f,   8.0f,
            10.0f,  12.0f,  14.0f,  16.0f,
            18.0f,  20.0f,  22.0f,  24.0f,
            26.0f,  28.0f,  30.0f,  32.0f
        };

        stream << matrix;
        REQUIRE_THAT(stream.str(), 
        Equals("Mat4[m1X: 2.000, 4.000, 6.000, 8.000 | m2X: 10.000, 12.000, 14.000, 16.000 | m3X: 18.000, 20.000, 22.000, 24.000 | m4X: 26.000, 28.000, 30.000, 32.000]"));
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

TEST_CASE("Scalar multiplication", "[mat4][operators][math]") {
    Mat4 mat4 = {
        1.0f,   2.0f,   3.0f,   4.0f,
        5.0f,   6.0f,   7.0f,   8.0f,
        9.0f,   10.0f,  11.0f,  12.0f,
        13.0f,  14.0f,  15.0f,  16.0f
    };

    SECTION("*2") {
        Mat4 result = {
            2.0f,   4.0f,   6.0f,   8.0f,
            10.0f,  12.0f,  14.0f,  16.0f,
            18.0f,  20.0f,  22.0f,  24.0f,
            26.0f,  28.0f,  30.0f,  32.0f
        };


        SECTION("*=") {
            mat4 *= 2.0f;
            REQUIRE(mat4 == result);
        }

        SECTION("*") {
            Mat4 original = {
                1.0f,   2.0f,   3.0f,   4.0f,
                5.0f,   6.0f,   7.0f,   8.0f,
                9.0f,   10.0f,  11.0f,  12.0f,
                13.0f,  14.0f,  15.0f,  16.0f
            };

            Mat4 res = mat4 * 2.0f;
            REQUIRE(res == result);
            REQUIRE(mat4 == original);
        }
    }

    SECTION("*0") {
        Mat4 result;

        SECTION("*=") {
            mat4 *= 0.0f;
            REQUIRE(mat4 == result);
        }

        SECTION("*") {
            Mat4 original = {
                1.0f,   2.0f,   3.0f,   4.0f,
                5.0f,   6.0f,   7.0f,   8.0f,
                9.0f,   10.0f,  11.0f,  12.0f,
                13.0f,  14.0f,  15.0f,  16.0f
            };

            Mat4 res = mat4 * 0.0f;
            REQUIRE(res == result);
            REQUIRE(mat4 == original);
        }
    }
}

TEST_CASE("Matrix multiplication", "[mat4][operators][math]") {
    SECTION("Regular") {
        Mat4 a = {
            1.0f,   2.0f,   3.0f,   4.0f,
            5.0f,   6.0f,   7.0f,   8.0f,
            9.0f,   10.0f,  11.0f,  12.0f,
            13.0f,  14.0f,  15.0f,  16.0f
        };

        Mat4 b = {
            2.0f,   4.0f,   6.0f,   8.0f,
            10.0f,  12.0f,  14.0f,  16.0f,
            18.0f,  20.0f,  22.0f,  24.0f,
            26.0f,  28.0f,  30.0f,  32.0f
        };

        Mat4 result = {
            180.0f,  200.0f,  220.0f,   240.0f,
            404.0f,  456.0f,  508.0f,   560.0f,
            628.0f,  712.0f,  796.0f,   880.0f,
            852.0f,  968.0f,  1084.0f,  1200.0f
        };

        SECTION("*=") {
            a *= b;
            REQUIRE(a == result);
        }

        SECTION("*") {
            Mat4 r = a * b;
            REQUIRE(r == result);
        }
    }

    SECTION("By identity") {
        Mat4 identity(1.0f);

        Mat4 a = {
            1.0f,   2.0f,   3.0f,   4.0f,
            5.0f,   6.0f,   7.0f,   8.0f,
            9.0f,   10.0f,  11.0f,  12.0f,
            13.0f,  14.0f,  15.0f,  16.0f
        };

        Mat4 result = {
            1.0f,   2.0f,   3.0f,   4.0f,
            5.0f,   6.0f,   7.0f,   8.0f,
            9.0f,   10.0f,  11.0f,  12.0f,
            13.0f,  14.0f,  15.0f,  16.0f
        };

        REQUIRE((a * identity) == result);
    }
}

TEST_CASE("Matrix transpose", "[mat4][math]") {
    SECTION("Regular") {
        Mat4 a = {
            1.0f,   2.0f,   3.0f,   4.0f,
            5.0f,   6.0f,   7.0f,   8.0f,
            9.0f,   10.0f,  11.0f,  12.0f,
            13.0f,  14.0f,  15.0f,  16.0f
        };

        Mat4 aT = {
            1.0f,  5.0f,  9.0f,   13.0f,
            2.0f,  6.0f,  10.0f,  14.0f,
            3.0f,  7.0f,  11.0f,  15.0f,
            4.0f,  8.0f,  12.0f,  16.0f
        };

        REQUIRE(a.transpose() == aT);
    }

    SECTION("Identity") {
        Mat4 identity(1.0f);
        REQUIRE(identity.transpose() == identity);
    }
}
