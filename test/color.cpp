#include <catch2/catch.hpp>
#include <raylib/color.hpp>
#include <sstream>

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

TEST_CASE("Color output stream operator", "[color][operators]") {
    using Catch::Matchers::Equals;

    std::stringstream output;
    SECTION("0.0f") {
        output << Color(0.0f, 0.0f, 0.0f, 0.0f);
        REQUIRE_THAT(output.str(), Equals("(0.000, 0.000, 0.000, 0.000)"));
    }

    SECTION("1.0f") {
        output << Color(1.0f, 1.0f, 1.0f, 1.0f);
        REQUIRE_THAT(output.str(), Equals("(1.000, 1.000, 1.000, 1.000)"));
    }

    SECTION("0.5f") {
        output << Color(0.5f, 0.5f, 0.5f, 0.5f);
        REQUIRE_THAT(output.str(), Equals("(0.500, 0.500, 0.500, 0.500)"));
    }

    SECTION("Varied") {
        output << Color(0.7f, 12.05f, 0.1f, 0.0f);
        REQUIRE_THAT(output.str(), Equals("(0.700, 12.050, 0.100, 0.000)"));
    }
}

TEST_CASE("Color assignment operators", "[color][operators]") {
    Color a(1.0f, 2.0f, 3.0f, 0.1f);
    Color b(2.0f, 4.0f, 6.0f, 0.2f);
    float s = 1.5f;

    SECTION("Addition") {
        a += b;
        CHECK(a.r == Approx(3.0f));
        CHECK(a.g == Approx(6.0f));
        CHECK(a.b == Approx(9.0f));
        CHECK(a.a == Approx(0.3f));
        CHECK(b.r == 2.0f);
        CHECK(b.g == 4.0f);
        CHECK(b.b == 6.0f);
        CHECK(b.a == 0.2f);
    }

    SECTION("Subtraction") {
        a -= b;
        CHECK(a.r == Approx(-1.0f));
        CHECK(a.g == Approx(-2.0f));
        CHECK(a.b == Approx(-3.0f));
        CHECK(a.a == Approx(-0.1f));
        CHECK(b.r == 2.0f);
        CHECK(b.g == 4.0f);
        CHECK(b.b == 6.0f);
        CHECK(b.a == 0.2f);
    }

    SECTION("Color - Color multiplication") {
        a *= b;
        CHECK(a.r == Approx(2.0f));
        CHECK(a.g == Approx(8.0f));
        CHECK(a.b == Approx(18.0f));
        CHECK(a.a == Approx(0.02f));
        CHECK(b.r == 2.0f);
        CHECK(b.g == 4.0f);
        CHECK(b.b == 6.0f);
        CHECK(b.a == 0.2f);
    }

    SECTION("Color - value multiplication") {
        a *= s;
        CHECK(a.r == Approx(1.5f));
        CHECK(a.g == Approx(3.0f));
        CHECK(a.b == Approx(4.5f));
        CHECK(a.a == Approx(0.15f));
        CHECK(s == 1.5f);
    }

    SECTION("Color division") {
        a /= s;
        CHECK(a.r == Approx(0.6f).epsilon(0.125f));
        CHECK(a.g == Approx(1.3f).epsilon(0.125f));
        CHECK(a.b == Approx(2.0f).epsilon(0.125f));
        CHECK(a.a == Approx(0.06f).epsilon(0.125f));
        CHECK(s == 1.5f);
    }
}
