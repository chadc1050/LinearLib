#pragma once

#include <array>

template<std::size_t R, std::size_t C, std::size_t Z, typename T>
requires std::is_arithmetic_v<T> && (R > 0) && (C > 0) && (Z > 0)
struct Tensor {
    std::array<std::array<std::array<T, R>, C>, Z> data;

    Tensor() = default;

    static Tensor identity() {
        Tensor res;

        for (std::size_t i = 0; i < R; i++) {
            for (std::size_t j = 0; j < C; j++) {
                for (std::size_t k = 0; k < Z; k++) {
                    if (k == i && i == j) {
                        res.data[i][j][k] = T{1};
                    } else {
                        res.data[i][j][k] = T{0};
                    }
                }
            }
        }

        return res;
    }

    static Tensor zeros() {
        return uniform(0);
    }

    static Tensor ones() {
        return uniform(1);
    }

    static Tensor uniform(const T& val) {
        Tensor res;

        for (std::size_t i = 0; i < R; i++) {
            for (std::size_t j = 0; j < C; j++) {
                for (std::size_t k = 0; k < Z; k++) {
                    res.data[i][j][k] = val;
                }
            }
        }

        return res;
    }

    bool operator==(const Tensor& other) const {
        for (std::size_t i = 0; i < R; i++) {
            for (std::size_t j = 0; j < C; j++) {
                for (std::size_t k = 0; k < Z; k++) {
                    if (data[i][j][k] != other.data[i][j][k]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
