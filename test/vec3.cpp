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

TEST_CASE("Vec3 comparison operators", "[vec3][operators]") {
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

TEST_CASE("Vec3 stream insertion operator", "[vec3][operators]") {
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

TEST_CASE("Vec3 assignment operators", "[vec3][operators]") {
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

TEST_CASE("Vec3 unary operators", "[vec3][operators]") {
    Vec3 a(1.0f, 2.0f, -3.0f);
    REQUIRE(a == Vec3(1.0f, 2.0f, -3.0f));

    SECTION("Unary plus") {
        CHECK(a == +a);
    }

    SECTION("Unary minus (Negation)") {
        CHECK(-a == Vec3(-1.0f, -2.0f, 3.0f));
    }
}

TEST_CASE("Vec3 binary operators", "[vec3][operators]") {
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
