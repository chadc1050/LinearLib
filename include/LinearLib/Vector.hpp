#pragma once

#include <array>
#include <cassert>
#include <initializer_list>
#include <type_traits>

#include "Matrix.hpp"

namespace LinearLib {
    template<std::size_t N, typename T>
    requires std::is_arithmetic_v<T>
    struct Vector {

        std::array<T, N> data;

        Vector(std::initializer_list<T> init) {
            assert(init.size() == N && "Vector size must match vector dimension");
            std::copy(init.begin(), init.end(), data.begin());
        }

        // Default constructor is still needed
        Vector() = default;

        T magnitude() const {
            T res = 0;

            for (std::size_t i = 0; i < N; i++) {
                res += std::pow(data[i], 2);
            }

            return std::sqrt(res);
        }

        Matrix<1, N, T> asMatrix() {
            Matrix<1, N, T> res;

            for (std::size_t i = 0; i < N; i++) {
                res[0][i] = data[i];
            }

            return res;
        }

        std::array<T, N> getData() const {
            return data;
        }

        bool operator==(const Vector& other) const {
            for (std::size_t i = 0; i < N; i++) {
                if (data[i] != other.data[i]) {
                    return false;
                }
            }

            return true;
        }

        T& operator[](std::size_t index) {
            assert(index < N && "Index out of bounds");
            return data[index];
        }

        const T& operator[](std::size_t index) const {
            assert(index < N && "Index out of bounds");
            return data[index];
        }

        friend Vector operator+(const Vector& lhs, const Vector& rhs) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = lhs[i] + rhs[i];
            }

            return res;
        }

        friend Vector operator-(const Vector& lhs, const Vector& rhs) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = lhs[i] - rhs[i];
            }

            return res;
        }

        /**
         * Dot Product
         */
        friend T operator*(const Vector& lhs, const Vector& rhs) {
            T res = 0;

            for (std::size_t i = 0; i < N; i++) {
                res += lhs[i] * rhs[i];
            }

            return res;
        }

        /**
         * Scalar Multiplication
         */
        friend Vector operator*(const Vector& vec, const T& scalar) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = vec[i] * scalar;
            }

            return res;
        }

        Vector<3,T> operator&(const Vector<3,T>& other) const {

            Vector<3,T> res;

            res[0] = data[1] * other[2] - data[2] * other[1];
            res[1] = data[2] * other[0] - data[0] * other[2];
            res[2] = data[0] * other[1] - data[1] * other[0];

            return res;
        }
    };
}
