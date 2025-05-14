#include "catch_amalgamated.hpp"

#include "../include/LinearLib/Matrix.hpp"

using namespace LinearLib;

TEST_CASE("Matrix operations", "[benchmark]") {

    // Small matrices
    Matrix<4, 4, float> m1_small = Matrix<4, 4, float>::random(0.0f, 10.0f);
    Matrix<4, 4, float> m2_small = Matrix<4, 4, float>::random(0.0f, 10.0f);

    // Medium matrices
    Matrix<16, 16, float> m1_medium = Matrix<16, 16, float>::random(0.0f, 10.0f);
    Matrix<16, 16, float> m2_medium = Matrix<16, 16, float>::random(0.0f, 10.0f);

    // Large matrices
    Matrix<64, 64, float> m1_large = Matrix<64, 64, float>::random(0.0f, 10.0f);
    Matrix<64, 64, float> m2_large = Matrix<64, 64, float>::random(0.0f, 10.0f);

    // XL matrices
    Matrix<256, 256, float> m1_xlarge = Matrix<256, 256, float>::random(0.0f, 10.0f);
    Matrix<256, 256, float> m2_xlarge = Matrix<256, 256, float>::random(0.0f, 10.0f);

    SECTION("Matrix Addition Benchmark") {
        BENCHMARK("Small Fully Compatible") {
            return m1_small + m2_small;
        };
        BENCHMARK("Medium Fully Compatible") {
            return m1_medium + m2_medium;
        };
        BENCHMARK("Large Fully Compatible") {
            return m1_large + m2_large;
        };
        BENCHMARK("Large") {
            return m1_large + m2_large;
        };
        BENCHMARK("XL Fully Compatible") {
            return m1_xlarge + m2_xlarge;
        };
    }

    SECTION("Matrix Subtraction Benchmark") {
        BENCHMARK("Small Fully Compatible") {
            return m1_small - m2_small;
        };
        BENCHMARK("Medium Fully Compatible") {
            return m1_medium - m2_medium;
        };
        BENCHMARK("Large Fully Compatible") {
            return m1_large - m2_large;
        };
        BENCHMARK("Large") {
            return m1_large - m2_large;
        };
        BENCHMARK("XL Fully Compatible") {
            return m1_xlarge - m2_xlarge;
        };
    }

    SECTION("Matrix Multiplication Benchmark") {
        BENCHMARK("Small Fully Compatible") {
            return m1_small & m2_small;
        };
        BENCHMARK("Medium Fully Compatible") {
            return m1_medium & m2_medium;
        };
        BENCHMARK("Large") {
            return m1_large & m2_large;
        };
        BENCHMARK("Large Fully Compatible") {
            return m1_large & m2_large;
        };
        BENCHMARK("XL Fully Compatible") {
            return m1_xlarge & m2_xlarge;
        };
    }
}