#include "catch_amalgamated.hpp"
#include "Matrix.hpp"

TEST_CASE("Matrix operations", "[vector]") {

    SECTION("Matrix addition") {
        const Matrix<2, 2, int> m1 {{1, 2},
                                        {1, 2}};

        const Matrix<2, 2, int> m2 {{2, 1},
                                        {2, 1}};

        const Matrix<2, 2, int> result = m1 + m2;

        REQUIRE(result[0][0] == 3);
        REQUIRE(result[0][1] == 3);
        REQUIRE(result[1][0] == 3);
        REQUIRE(result[1][1] == 3);
    }

    SECTION("Matrix subtraction") {
        const Matrix<2, 2, int> m1 {{5, 3},
                                        {2, 4}};

        const Matrix<2, 2, int> m2 {{3, 6},
                                        {7, 2}};

        const Matrix<2, 2, int> result = m1 + m2;

        REQUIRE(result[0][0] == 8);
        REQUIRE(result[0][1] == 9);
        REQUIRE(result[1][0] == 9);
        REQUIRE(result[1][1] == 6);
    }

    SECTION("Matrix multiplication") {
        const Matrix<2, 4, int> m1 {{5, 3, 3, 4},
                                        {2, 4, 4, 3}};

        const Matrix<4, 2, int> m2 {{3, 6},
                                        {5, 2},
                                        {3, 2},
                                        {7, 1}};

        const Matrix<2, 2, int> result = m1 * m2;

        REQUIRE(result[0][0] == 67);
        REQUIRE(result[0][1] == 46);
        REQUIRE(result[1][0] == 59);
        REQUIRE(result[1][1] == 31);
    }

    SECTION("Matrix splicing") {
        Matrix<5, 5, int> original = Matrix<5, 5, int>::identity();

        // Extract every other row and column
        auto evenRows = std::views::iota(0, 5) | std::views::filter([](const int i) { return i % 2 == 0; });
        auto evenCols = std::views::iota(0, 5) | std::views::filter([](const int i) { return i % 2 == 0; });
        Matrix<3, 3, int> subMatrix1 = original.splice<3, 3>(evenRows, evenCols);

        REQUIRE(subMatrix1[0][0] == 1);
        REQUIRE(subMatrix1[0][1] == 0);
        REQUIRE(subMatrix1[0][2] == 0);
        REQUIRE(subMatrix1[1][0] == 0);
        REQUIRE(subMatrix1[1][1] == 1);
        REQUIRE(subMatrix1[1][2] == 0);
        REQUIRE(subMatrix1[2][0] == 0);
        REQUIRE(subMatrix1[2][1] == 0);
        REQUIRE(subMatrix1[2][2] == 1);
    }

    SECTION("Matrix transpose") {
        const Matrix<2, 2, int> m {{1, 2},
                                        {1, 2}};

        const Matrix<2, 2, int> result = m.transpose();

        REQUIRE(result[0][0] == 1);
        REQUIRE(result[0][1] == 1);
        REQUIRE(result[1][0] == 2);
        REQUIRE(result[1][1] == 2);
    }

    SECTION("Matrix determinant") {
        const Matrix<3, 3, int> m {{6, 1, 1},
                                        {4, -2, 5},
                                        {2, 8, 7}};

        int determinant = m.determinant();

        REQUIRE(determinant == -306);
    }

    SECTION("Matrix scalar multiplication") {
        const Matrix<4, 4, float> m {{1, 2, 3, 4},
                                        {5, 6, 7, 8},
                                        {9, 10, 11, 12},
                                        {13, 14, 15, 16}};

        const Matrix<4, 4, float> result = m * 2;

        REQUIRE(result[0][0] == 2);
        REQUIRE(result[0][1] == 4);
        REQUIRE(result[0][2] == 6);
        REQUIRE(result[0][3] == 8);
        REQUIRE(result[1][0] == 10);
        REQUIRE(result[1][1] == 12);
        REQUIRE(result[1][2] == 14);
        REQUIRE(result[1][3] == 16);
        REQUIRE(result[2][0] == 18);
        REQUIRE(result[2][1] == 20);
        REQUIRE(result[2][2] == 22);
        REQUIRE(result[2][3] == 24);
        REQUIRE(result[3][0] == 26);
        REQUIRE(result[3][1] == 28);
        REQUIRE(result[3][2] == 30);
        REQUIRE(result[3][3] == 32);
    }
}