#include <catch2/catch.hpp>
#include <raylib/vec3.hpp>
#include <sstream>

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

TEST_CASE("Vec3 comparison operators", "[vec3][operators][math]") {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(-10.0f, 10.0f, 11.0f);
    Vec3 c(1.0f, 2.0f, 3.0f);

    SECTION("Equality") {
        CHECK_FALSE(a == b);
        CHECK(a == c);
    }

    SECTION("Inequality") {
        CHECK_FALSE(a != c);
        CHECK(a != b);
    }
}

TEST_CASE("Vec3 stream insertion operator", "[vec3][operators][math]") {
    using Catch::Matchers::Equals;

    Vec3 a(1.0f, 2.0f, 3.0f);
    REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));

    Vec3 b(-10.0f, 10.0f, 11.0f);
    REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));

    std::stringstream stream;
    
    SECTION("A") {
        stream << a;
        REQUIRE_THAT(stream.str(), Equals("(1.000, 2.000, 3.000)"));
    }

    SECTION("B") {
        stream << b;
        REQUIRE_THAT(stream.str(), Equals("(-10.000, 10.000, 11.000)"));
    }
}

TEST_CASE("Vec3 assignment operators", "[vec3][operators][math]") {
    Vec3 a(1.0f, 2.0f, 3.0f);
    REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));

    Vec3 b(-10.0f, 10.0f, 11.0f);
    REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));

    float scalar = 5.0f;

    SECTION("Normal assignment") {
        a = b;
        REQUIRE(a == Vec3(-10.0f, 10.0f, 11.0f));
        REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));
    };

    SECTION("Addition assignment") {
        a += b;
        CHECK(a.x == Approx(-9.0f));
        CHECK(a.y == Approx(12.0f));
        CHECK(a.z == Approx(14.0f));
        REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));
    }

    SECTION("Subtraction assignment") {
        a -= b;
        CHECK(a.x == Approx(11.0f));
        CHECK(a.y == Approx(-8.0f));
        CHECK(a.z == Approx(-8.0f));
        REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));
    }

    SECTION("Scalar multiplication assignment") {
        a *= scalar;
        CHECK(a.x == Approx(5.0f));
        CHECK(a.y == Approx(10.0f));
        CHECK(a.z == Approx(15.0f));
        REQUIRE(scalar == 5.0f);
    }

    SECTION("Scalar division assignment") {
        a /= scalar;
        CHECK(a.x == Approx(0.2f));
        CHECK(a.y == Approx(0.4f));
        CHECK(a.z == Approx(0.6f));
        REQUIRE(scalar == 5.0f);
    }
}

TEST_CASE("Vec3 unary operators", "[vec3][operators][math]") {
    Vec3 a(1.0f, 2.0f, -3.0f);
    REQUIRE(a == Vec3(1.0f, 2.0f, -3.0f));

    SECTION("Unary plus") {
        CHECK(a == +a);
    }

    SECTION("Unary minus (Negation)") {
        CHECK(-a == Vec3(-1.0f, -2.0f, 3.0f));
    }
}

TEST_CASE("Vec3 binary operators", "[vec3][operators][math]") {
    Vec3 a(1.0f, 2.0f, 3.0f);
    REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));

    Vec3 b(-10.0f, 10.0f, 11.0f);
    REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));

    float scalar = 5.0f;

    SECTION("Addition") {
        Vec3 result = a + b;
        CHECK(result.x == Approx(-9.0f));
        CHECK(result.y == Approx(12.0f));
        CHECK(result.z == Approx(14.0f));
        REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));
        REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));
    }

    SECTION("Subtraction") {
        Vec3 result = a - b;
        CHECK(result.x == Approx(11.0f));
        CHECK(result.y == Approx(-8.0f));
        CHECK(result.z == Approx(-8.0f));
        REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));
        REQUIRE(b == Vec3(-10.0f, 10.0f, 11.0f));
    }

    SECTION("Scalar multiplication") {
        Vec3 result0 = scalar * a;
        Vec3 result1 = a * scalar;
        REQUIRE(result0 == result1);
        CHECK(result0.x == Approx(5.0f));
        CHECK(result0.y == Approx(10.0f));
        CHECK(result0.z == Approx(15.0f));
        REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));
        REQUIRE(scalar == 5.0f);
    }

    SECTION("Scalar division") {
        Vec3 result = a / scalar;
        CHECK(result.x == Approx(0.2f));
        CHECK(result.y == Approx(0.4f));
        CHECK(result.z == Approx(0.6f));
        REQUIRE(a == Vec3(1.0f, 2.0f, 3.0f));
        REQUIRE(scalar == 5.0f);
    }
}

TEST_CASE("Vec3 magnitude", "[vec3][math]") {
    Vec3 a(5.0f, 3.0f, -11.0f);
    SECTION("Square magnitude") {
        REQUIRE(a.sqrMagnitude() == Approx(155.0f));
    }

    SECTION("Magnitude") {
        REQUIRE(a.magnitude() == Approx(12.449f).epsilon(0.001f));
    }

    Vec3 b(10.0f, 2.0f, 100.0f);
    SECTION("Square magnitude") {
        REQUIRE(b.sqrMagnitude() == Approx(10104.0f));
    }

    SECTION("Magnitude") {
        REQUIRE(b.magnitude() == Approx(100.518f).margin(0.002f));
    }
}

TEST_CASE("Vec3 dot product", "[vec3][math]") {
    SECTION("Simple vectors") {
        Vec3 a(1.0f, 0.0f, 0.0f);

        SECTION("Parallel") {
            Vec3 b(10.0f, 0.0f, 0.0f);
            Vec3 c(0.2f, 0.0f, 0.0f);
            CHECK(a.dot(b) == Approx(10.0f).epsilon(0.01f));
            CHECK(a.dot(c) == Approx(0.2f).epsilon(0.01f));
            REQUIRE(a == Vec3(1.0f, 0.0f, 0.0f));
            REQUIRE(b == Vec3(10.0f, 0.0f, 0.0f));
            REQUIRE(c == Vec3(0.2f, 0.0f, 0.0f));
        }

        SECTION("Perpendicular") {
            Vec3 b(0.0f, 10.0f, 0.0f);
            Vec3 c(0.0f, 0.0f, 1240.0f);
            CHECK(a.dot(b) == Approx(0.0f).epsilon(0.01f));
            CHECK(a.dot(c) == Approx(0.0f).epsilon(0.01f));
            REQUIRE(a == Vec3(1.0f, 0.0f, 0.0f));
            REQUIRE(b == Vec3(0.0f, 10.0f, 0.0f));
            REQUIRE(c == Vec3(0.0f, 0.0f, 1240.0f));
        }

        SECTION("Mix") {
            Vec3 b(6.85f, 4.79f, 5.48f);
            CHECK(a.dot(b) == Approx(6.85f).epsilon(0.01f));
            REQUIRE(a == Vec3(1.0f, 0.0f, 0.0f));
            REQUIRE(b == Vec3(6.85f, 4.79f, 5.48f));
        }
    }

    SECTION("Interesting vectors") {
        Vec3 a(0.685f, 0.479f, 0.548f);

        SECTION("Parallel") {
            Vec3 b(6.85f, 4.79f, 5.48f);
            Vec3 c(0.0685f, 0.0479f, 0.0548f);
            CHECK(a.dot(b) == Approx(10.0f).epsilon(0.01f));
            CHECK(a.dot(c) == Approx(0.1f).epsilon(0.01f));
            REQUIRE(a == Vec3(0.685f, 0.479f, 0.548f));
            REQUIRE(b == Vec3(6.85f, 4.79f, 5.48f));
            REQUIRE(c == Vec3(0.0685f, 0.0479f, 0.0548f));
        }

        SECTION("Perpendicular") {
            Vec3 b(0.0f, 0.752f, -0.657f);
            Vec3 c(0.0f, 7.52f, -6.57f);
            CHECK(a.dot(b) == Approx(0.0f).margin(0.01f));
            CHECK(a.dot(c) == Approx(0.0f).margin(0.01f));
            REQUIRE(a == Vec3(0.685f, 0.479f, 0.548f));
            REQUIRE(b == Vec3(0.0f, 0.752f, -0.657f));
            REQUIRE(c == Vec3(0.0f, 7.52f, -6.57f));
        }

        SECTION("Mix") {
            Vec3 b(0.328f, 0.164f, 0.930f);
            Vec3 c(34.8f, 16.4f, 93.0f);
            CHECK(a.dot(b) == Approx(0.812f).epsilon(0.01f));
            CHECK(a.dot(c) == Approx(82.65f).epsilon(0.01f));
            REQUIRE(a == Vec3(0.685f, 0.479f, 0.548f));
            REQUIRE(b == Vec3(0.328f, 0.164f, 0.930f));
            REQUIRE(c == Vec3(34.8f, 16.4f, 93.0f));
        }

        SECTION("Itself") {
            CHECK(a.dot(a) == Approx(1.0f).epsilon(0.01f));
            REQUIRE(a == Vec3(0.685f, 0.479f, 0.548f));
        }
    }
}

TEST_CASE("Vec3 cross product", "[vec3][math]") {
    SECTION("Cardinal axes") {
        Vec3 x(1.0f, 0.0f, 0.0f);
        Vec3 y(0.0f, 1.0f, 0.0f);
        Vec3 z(0.0f, 0.0f, 1.0f);

        SECTION("X x Y") {
            REQUIRE(x.cross(y) == z);
            REQUIRE(x == Vec3(1.0f, 0.0f, 0.0f));
            REQUIRE(y == Vec3(0.0f, 1.0f, 0.0f));
        }

        SECTION("Y x Z") {
            REQUIRE(y.cross(z) == x);
            REQUIRE(y == Vec3(0.0f, 1.0f, 0.0f));
            REQUIRE(z == Vec3(0.0f, 0.0f, 1.0f));
        }

        SECTION("Z x X") {
            REQUIRE(z.cross(x) == y);
            REQUIRE(z == Vec3(0.0f, 0.0f, 1.0f));
            REQUIRE(y == Vec3(0.0f, 1.0f, 0.0f));
        }
    }

    SECTION("Interesting vectors") {
        Vec3 a(0.227f, 0.593f, 0.772f);
        Vec3 b(0.139f, 0.839f, 0.524f);
        Vec3 cross = a.cross(b);
        CHECK(cross.x == Approx(-0.336f).epsilon(0.01f));
        CHECK(cross.y == Approx(-0.01164f).epsilon(0.01f));
        CHECK(cross.z == Approx(0.108f).epsilon(0.01f));
        REQUIRE(a == Vec3(0.227f, 0.593f, 0.772f));
        REQUIRE(b == Vec3(0.139f, 0.839f, 0.524f));
    }
}

TEST_CASE("Vec3 normalization", "[vec3][math]") {
    SECTION("Long vector") {
        Vec3 a(100.0f);
        Vec3 normalized = a.normalized();
        CHECK(normalized.x == Approx(0.577350f).epsilon(0.001f));
        CHECK(normalized.y == Approx(0.577350f).epsilon(0.001f));
        CHECK(normalized.z == Approx(0.577350f).epsilon(0.001f));
        CHECK(normalized.magnitude() == Approx(1.0f).epsilon(0.01f));
    }

    SECTION("Longer vector") {
        Vec3 a(1211.0f, 241.0f, 24.0f);
        Vec3 normalized = a.normalized();
        CHECK(normalized.x == Approx(0.980581f).epsilon(0.001f));
        CHECK(normalized.y == Approx(0.195144f).epsilon(0.001f));
        CHECK(normalized.z == Approx(0.019433f).epsilon(0.001f));
        CHECK(normalized.magnitude() == Approx(1.0f).epsilon(0.01f));
    }

    SECTION("Short vector") {
        Vec3 a(0.248f, 0.853f, 0.124f);
        Vec3 normalized = a.normalized();
        CHECK(normalized.x == Approx(0.276497f).epsilon(0.001f));
        CHECK(normalized.y == Approx(0.951018f).epsilon(0.001f));
        CHECK(normalized.z == Approx(0.138248f).epsilon(0.001f));
        CHECK(normalized.magnitude() == Approx(1.0f).epsilon(0.01f));
    }
}
