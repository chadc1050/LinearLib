#include "catch_amalgamated.hpp"
#include "Matrix.hpp"

TEST_CASE("Matrix operations", "[vector]") {

    SECTION("Matrix addition") {
        const Matrix<2, 2, int> m1 {{1, 2},
                                        {1, 2}};

        const Matrix<2, 2, int> m2 {{2, 1},
                                        {2, 1}};

        const Matrix<2, 2, int> result = m1 + m2;

        REQUIRE(result.data[0][0] == 3);
        REQUIRE(result.data[0][1] == 3);
        REQUIRE(result.data[1][0] == 3);
        REQUIRE(result.data[1][1] == 3);
    }

    SECTION("Matrix subtraction") {
        const Matrix<2, 2, int> m1 {{5, 3},
                                        {2, 4}};

        const Matrix<2, 2, int> m2 {{3, 6},
                                        {7, 2}};

        const Matrix<2, 2, int> result = m1 + m2;

        REQUIRE(result.data[0][0] == 8);
        REQUIRE(result.data[0][1] == 9);
        REQUIRE(result.data[1][0] == 9);
        REQUIRE(result.data[1][1] == 6);
    }

    SECTION("Matrix multiplication") {
        const Matrix<2, 4, int> m1 {{5, 3, 3, 4},
                                        {2, 4, 4, 3}};

        const Matrix<4, 2, int> m2 {{3, 6},
                                        {5, 2},
                                        {3, 2},
                                        {7, 1}};

        const Matrix<2, 2, int> result = m1 * m2;

        REQUIRE(result.data[0][0] == 67);
        REQUIRE(result.data[0][1] == 46);
        REQUIRE(result.data[1][0] == 59);
        REQUIRE(result.data[1][1] == 31);
    }
}