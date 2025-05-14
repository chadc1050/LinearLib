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
}