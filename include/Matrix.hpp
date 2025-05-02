#pragma once

#include <array>
#include <initializer_list>
#include <type_traits>

template<std::size_t R, std::size_t C, typename T>
requires std::is_arithmetic_v<T>
struct Matrix {
    std::array<std::array<T, C>, R> data;

    Matrix(std::initializer_list<std::initializer_list<T>> init) {
        assert(init.size() == R && "Initializer list size must match vector dimension");
        auto row = init.begin();
        for (std::size_t i = 0; i < R && row != init.end(); i++, ++row) {
            assert(row->size() == C && "Number of columns must match matrix dimensions");
            std::copy(row->begin(), row->end(), data[i].begin());
        }
    }

    // Default constructor is still needed
    Matrix() = default;

    Matrix operator+(const Matrix& other) const {
        Matrix res;

        for (std::size_t i = 0; i < R; i++) {
            for (std::size_t j = 0; j < C; j++) {
                res.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return res;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix res;

        for (std::size_t i = 0; i < R; i++) {
            for (std::size_t j = 0; j < C; j++) {
                res.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return res;
    }

    template<std::size_t I>
    Matrix<R, I, T> operator*(const Matrix<C, I, T>& other) const {
        Matrix<R, I, T> res;

        for (std::size_t i = 0; i < R; i++) {
            for (std::size_t j = 0; j < I; j++) {
                T sum = T{};
                for (std::size_t k = 0; k < C; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                res.data[i][j] = sum;
            }
        }

        return res;
    }
};
