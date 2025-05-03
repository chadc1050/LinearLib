#include "catch_amalgamated.hpp"
#include "Vector.hpp"

TEST_CASE("Vector operations", "[vector]") {
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
