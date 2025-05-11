#include "catch_amalgamated.hpp"

#include "../include/LinearLib/Matrix.hpp"

using namespace LinearLib;

TEST_CASE("Matrix operations", "[benchmark]") {

    // Small SIMD matrices
    Matrix<4, 4, float> m1_small_simd = Matrix<4, 4, float>::random(0.0f, 10.0f);
    Matrix<4, 4, float> m2_small_simd = Matrix<4, 4, float>::random(0.0f, 10.0f);

    // Medium SIMD matrices
    Matrix<16, 16, float> m1_medium_simd = Matrix<16, 16, float>::random(0.0f, 10.0f);
    Matrix<16, 16, float> m2_medium_simd = Matrix<16, 16, float>::random(0.0f, 10.0f);

    // Large SIMD matrices
    Matrix<64, 64, float> m1_large_simd = Matrix<64, 64, float>::random(0.0f, 10.0f);
    Matrix<64, 64, float> m2_large_simd = Matrix<64, 64, float>::random(0.0f, 10.0f);

    // Large
    Matrix<60, 60, float> m1_large = Matrix<60, 60, float>::random(0.0f, 10.0f);
    Matrix<60, 60, float> m2_large = Matrix<60, 60, float>::random(0.0f, 10.0f);

    // XL SIMD matrices
    Matrix<256, 256, float> m1_xlarge_simd = Matrix<256, 256, float>::random(0.0f, 10.0f);
    Matrix<256, 256, float> m2_xlarge_simd = Matrix<256, 256, float>::random(0.0f, 10.0f);

    SECTION("Matrix Addition Benchmark") {
        BENCHMARK("Small SIMD Fully Compatible") {
            return m1_small_simd + m2_small_simd;
        };
        BENCHMARK("Medium SIMD Fully Compatible") {
            return m1_medium_simd + m2_medium_simd;
        };
        BENCHMARK("Large SIMD Fully Compatible") {
            return m1_large_simd + m2_large_simd;
        };
        BENCHMARK("Large") {
            return m1_large + m2_large;
        };
        BENCHMARK("XL SIMD Fully Compatible") {
            return m1_xlarge_simd + m2_xlarge_simd;
        };
    }

    SECTION("Matrix Subtraction Benchmark") {
        BENCHMARK("Small SIMD Fully Compatible") {
            return m1_small_simd - m2_small_simd;
        };
        BENCHMARK("Medium SIMD Fully Compatible") {
            return m1_medium_simd - m2_medium_simd;
        };
        BENCHMARK("Large SIMD Fully Compatible") {
            return m1_large_simd - m2_large_simd;
        };
        BENCHMARK("Large") {
            return m1_large - m2_large;
        };
        BENCHMARK("XL SIMD Fully Compatible") {
            return m1_xlarge_simd - m2_xlarge_simd;
        };
    }

    SECTION("Matrix Multiplication Benchmark") {
        BENCHMARK("Small SIMD Fully Compatible") {
            return m1_small_simd & m2_small_simd;
        };
        BENCHMARK("Medium SIMD Fully Compatible") {
            return m1_medium_simd & m2_medium_simd;
        };
        BENCHMARK("Large") {
            return m1_large & m2_large;
        };
        BENCHMARK("Large SIMD Fully Compatible") {
            return m1_large_simd & m2_large_simd;
        };
        BENCHMARK("XL SIMD Fully Compatible") {
            return m1_xlarge_simd & m2_xlarge_simd;
        };
    }
}