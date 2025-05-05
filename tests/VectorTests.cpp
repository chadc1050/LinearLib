#include "catch_amalgamated.hpp"
#include "../include/LinearLib/Vector.hpp"

using namespace LinearLib;

TEST_CASE("Vector operations", "[vector]") {

    SECTION("Vector magnitude") {
        Vector<2, int> v {3, 4};

        int result = v.magnitude();

        REQUIRE(result == 5);
    }

    SECTION("As Matrix") {
        Vector<3, int> v {1, 2, 3};

        Matrix<1, 3, int> m = v.asMatrix();

        REQUIRE(m[0][0] == 1);
        REQUIRE(m[0][1] == 2);
        REQUIRE(m[0][2] == 3);
    }

    SECTION("Vector addition") {

        Vector<3, int> v1 {1, 2, 3};
        Vector<3, int> v2 {4, 5, 6};

        Vector<3, int> result = v1 + v2;

        REQUIRE(result[0] == 5);
        REQUIRE(result[1] == 7);
        REQUIRE(result[2] == 9);
    }

    SECTION("Vector subtraction") {

        Vector<3, int> v1 {4, 5, 6};
        Vector<3, int> v2 {1, 2, 3};

        Vector<3, int> result = v1 - v2;

        REQUIRE(result[0] == 3);
        REQUIRE(result[1] == 3);
        REQUIRE(result[2] == 3);
    }

    SECTION("Vector scalar multiplication") {
        Vector<3, bool> v1 {true, false, true};

        Vector<3, bool> res = v1 * false;

        REQUIRE(res[0] == false);
        REQUIRE(res[1] == false);
        REQUIRE(res[2] == false);

        Vector<4, float> v2 {1.0f, 2.0f, 3.0f, 4.0f};

        Vector<4, float> res2 = v2 * 2.0f;

        REQUIRE(res2[0] == 2.0f);
        REQUIRE(res2[1] == 4.0f);
        REQUIRE(res2[2] == 6.0f);
        REQUIRE(res2[3] == 8.0f);
    }

    SECTION("Dot product") {
        Vector<3, int> v1 {1, 2, 3};
        Vector<3, int> v2 {4, 5, 6};

        int result = v1 * v2;

        REQUIRE(result == 32);  // 1*4 + 2*5 + 3*6 = 32
    }

    SECTION("Cross product") {
        Vector<3, int> v1 {3, 0, 2};
        Vector<3, int> v2 {-1, 4, 2};

        Vector<3, int> result = v1 & v2;

        REQUIRE(result[0] == -8);
        REQUIRE(result[1] == -8);
        REQUIRE(result[2] == 12);
    }
}
