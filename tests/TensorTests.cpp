#include "catch_amalgamated.hpp"

#include "../include/LinearLib/Tensor.hpp"

using namespace LinearLib;

TEST_CASE("Tensor operations", "[tensor]") {

    SECTION("Tensor addition") {
        Tensor<3, 4, 5, int> t1 = Tensor<3, 4, 5, int>::uniform(3);
        Tensor<3, 4, 5, int> t2 = Tensor<3, 4, 5, int>::uniform(5);

        Tensor<3, 4, 5, int> result = t1 + t2;

        REQUIRE(result == Tensor<3, 4, 5, int>::uniform(8));
    }

    SECTION("Iterator") {
        Tensor<3, 4, 5, int> t = Tensor<3, 4, 5, int>::uniform(3);

        int counter = 0;
        for (Matrix<3, 4, int>& _ : t) {
            counter++;
        }

        REQUIRE(counter == 5);

        counter = 0;
        for (Matrix<3, 4, int>& m : t) {
            for (Vector<4, int>& _ : m) {
                counter++;
            }
        }

        REQUIRE(counter == 15);

        counter = 0;
        for (Matrix<3, 4, int>& m : t) {
            for (Vector<4, int>& v : m) {
                for (int _ : v) {
                    counter++;
                }
            }
        }

        REQUIRE(counter == 60);
    }
}