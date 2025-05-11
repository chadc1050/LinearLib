#include "catch_amalgamated.hpp"
#include "../include/LinearLib/Matrix.hpp"

using namespace LinearLib;

TEST_CASE("Matrix operations", "[matrix]") {

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

        Matrix<10, 10, float> m3 = Matrix<10, 10, float>::uniform(3);
        Matrix<10, 10, float> m4 = Matrix<10, 10, float>::uniform(5);

        m3 += m4;

        for (std::size_t i = 0; i < 10; i++) {
            for (std::size_t j = 0; j < 10; j++) {
                REQUIRE(m3[i][j] == 8);
            }
        }

        Matrix<23, 23, float> m5 = Matrix<23, 23, float>::uniform(-2);
        Matrix<23, 23, float> m6 = Matrix<23, 23, float>::uniform(20);

        m5 += m6;

        for (std::size_t i = 0; i < 23; i++) {
            for (std::size_t j = 0; j < 23; j++) {
                REQUIRE(m5[i][j] == 18);
            }
        }

        Matrix<16, 16, float> m7 = Matrix<16, 16, float>::identity() * 3;
        Matrix<16, 16, float> m8 = Matrix<16, 16, float>::identity() * 5;

        m7 += m8;

        for (std::size_t i = 0; i < 16; i++) {
            for (std::size_t j = 0; j < 16; j++) {
                if (i == j) {
                    REQUIRE(m7[i][j] == 8);
                } else {
                    REQUIRE(m7[i][j] == 0);
                }
            }
        }
    }

    SECTION("Matrix subtraction") {
        const Matrix<2, 2, int> m1 {{5, 3},
                                        {2, 4}};

        const Matrix<2, 2, int> m2 {{3, 6},
                                        {7, 2}};

        const Matrix<2, 2, int> result = m1 - m2;

        REQUIRE(result[0][0] == 2);
        REQUIRE(result[0][1] == -3);
        REQUIRE(result[1][0] == -5);
        REQUIRE(result[1][1] == 2);
    }

    SECTION("Matrix multiplication") {
        const Matrix<2, 4, int> m1 {{5, 3, 3, 4},
                                        {2, 4, 4, 3}};

        const Matrix<4, 2, int> m2 {{3, 6},
                                        {5, 2},
                                        {3, 2},
                                        {7, 1}};

        const Matrix<2, 2, int> result = m1 & m2;

        REQUIRE(result[0][0] == 67);
        REQUIRE(result[0][1] == 46);
        REQUIRE(result[1][0] == 59);
        REQUIRE(result[1][1] == 31);

        Matrix<64, 64, float> m1_large_simd = Matrix<64, 64, float>::uniform(10.0f);
        Matrix<64, 64, float> m2_large_simd = Matrix<64, 64, float>::uniform(10.0f);

        const Matrix<64, 64, float> result_simd = m1_large_simd & m2_large_simd;

        for (std::size_t i = 0; i < 64; i++) {
            for (std::size_t j = 0; j < 64; j++) {
                REQUIRE(result_simd[i][j] == 6400);
            }
        }
    }

    SECTION("Matrix division") {

        const Matrix<2, 2, int> m1 {{6, 24},
                                        {14, 4}};

        const Matrix<2, 2, int> m2 {{3, 6},
                                        {7, 4}};

        const Matrix<2, 2, int> result = m1 / m2;

        REQUIRE(result[0][0] == 2);
        REQUIRE(result[0][1] == 4);
        REQUIRE(result[1][0] == 2);
        REQUIRE(result[1][1] == 1);
    }

    SECTION("Matrix modulo") {
        const Matrix<2, 2, int> m1 {{6, 25},
                                        {13, 4}};

        const Matrix<2, 2, int> m2 {{3, 6},
                                        {7, 4}};

        const Matrix<2, 2, int> result = m1 % m2;

        REQUIRE(result[0][0] == 0);
        REQUIRE(result[0][1] == 1);
        REQUIRE(result[1][0] == 6);
        REQUIRE(result[1][1] == 0);
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
        const Matrix<3, 2, int> m {{1, 2},
                                        {4, 2},
                                        {5, 6}};

        const Matrix<2, 3, int> result = m.transpose();

        REQUIRE(result[0][0] == 1);
        REQUIRE(result[0][1] == 4);
        REQUIRE(result[0][2] == 5);
        REQUIRE(result[1][0] == 2);
        REQUIRE(result[1][1] == 2);
        REQUIRE(result[1][2] == 6);
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

    SECTION("Zeros") {
        const Matrix<4, 4, float> zeros = Matrix<4, 4, float>::zeros();

        REQUIRE(zeros[0][0] == 0);
        REQUIRE(zeros[0][1] == 0);
        REQUIRE(zeros[0][2] == 0);
        REQUIRE(zeros[0][3] == 0);
        REQUIRE(zeros[1][0] == 0);
        REQUIRE(zeros[1][1] == 0);
        REQUIRE(zeros[1][2] == 0);
    }

    SECTION("Eye") {
        const Matrix<4, 4, int> eye1 = Matrix<4, 4, int>::eye(1);

        REQUIRE(eye1[0][0] == 0);
        REQUIRE(eye1[0][1] == 1);
        REQUIRE(eye1[0][2] == 0);
        REQUIRE(eye1[0][3] == 0);
        REQUIRE(eye1[1][0] == 0);
        REQUIRE(eye1[1][1] == 0);
        REQUIRE(eye1[1][2] == 1);
        REQUIRE(eye1[1][3] == 0);
        REQUIRE(eye1[2][0] == 0);
        REQUIRE(eye1[2][1] == 0);
        REQUIRE(eye1[2][2] == 0);
        REQUIRE(eye1[2][3] == 1);
        REQUIRE(eye1[3][0] == 0);
        REQUIRE(eye1[3][1] == 0);
        REQUIRE(eye1[3][2] == 0);
        REQUIRE(eye1[3][3] == 0);

        const Matrix<4, 4, int> eye2 = Matrix<4, 4, int>::eye(-2);

        REQUIRE(eye2[0][0] == 0);
        REQUIRE(eye2[0][1] == 0);
        REQUIRE(eye2[0][2] == 0);
        REQUIRE(eye2[0][3] == 0);
        REQUIRE(eye2[1][0] == 0);
        REQUIRE(eye2[1][1] == 0);
        REQUIRE(eye2[1][2] == 0);
        REQUIRE(eye2[1][3] == 0);
        REQUIRE(eye2[2][0] == 1);
        REQUIRE(eye2[2][1] == 0);
        REQUIRE(eye2[2][2] == 0);
        REQUIRE(eye2[2][3] == 0);
        REQUIRE(eye2[3][0] == 0);
        REQUIRE(eye2[3][1] == 1);
        REQUIRE(eye2[3][2] == 0);
        REQUIRE(eye2[3][3] == 0);
    }

    SECTION("Random") {
        size_t seed = 42;
        const Matrix<2, 2, int> m1 = Matrix<2, 2, int>::random(1, 10, seed);

        REQUIRE(m1[0][0] == 8);
        REQUIRE(m1[0][1] == 7);
        REQUIRE(m1[1][0] == 8);
        REQUIRE(m1[1][1] == 2);

        const Matrix<2, 2, float> m2 = Matrix<2, 2, float>::random(0.0, 100.0, seed);
        REQUIRE(m2[0][0] == 75.515548706f);
        REQUIRE(m2[0][1] == 63.903141022f);
        REQUIRE(m2[1][0] == 75.214515686f);
        REQUIRE(m2[1][1] == 13.627268791f);
    }

    SECTION("ForEach") {
        Matrix<2, 2, int> m {{1, 2}, {3, 4} };

        m.forEach([](int& value) {
            value *= 2;
        });

        REQUIRE(m[0][0] == 2);
        REQUIRE(m[0][1] == 4);
        REQUIRE(m[1][0] == 6);
        REQUIRE(m[1][1] == 8);

        Matrix<2, 2, float> m2 = Matrix<2, 2, float>::uniform(10);

        m2.forEach([](float& value, std::size_t row, std::size_t col) {
            value = row + col;
        });

        REQUIRE(m2[0][0] == 0.0f);
        REQUIRE(m2[0][1] == 1.0f);
        REQUIRE(m2[1][0] == 1.0f);
        REQUIRE(m2[1][1] == 2.0f);
    }
}