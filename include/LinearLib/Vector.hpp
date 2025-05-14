#pragma once

#include <array>
#include <cassert>
#include <initializer_list>
#include <type_traits>

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

        // Iterator methods
        typename std::array<T, N>::iterator begin() noexcept { return data.begin(); }
        typename std::array<T, N>::const_iterator begin() const noexcept { return data.begin(); }
        typename std::array<T, N>::const_iterator cbegin() const noexcept { return data.cbegin(); }

        typename std::array<T, N>::iterator end() noexcept { return data.end(); }
        typename std::array<T, N>::const_iterator end() const noexcept { return data.end(); }
        typename std::array<T, N>::const_iterator cend() const noexcept { return data.cend(); }

        typename std::array<T, N>::reverse_iterator rbegin() noexcept { return data.rbegin(); }
        typename std::array<T, N>::const_reverse_iterator rbegin() const noexcept { return data.rbegin(); }
        typename std::array<T, N>::const_reverse_iterator crbegin() const noexcept { return data.crbegin(); }

        typename std::array<T, N>::reverse_iterator rend() noexcept { return data.rend(); }
        typename std::array<T, N>::const_reverse_iterator rend() const noexcept { return data.rend(); }
        typename std::array<T, N>::const_reverse_iterator crend() const noexcept { return data.crend(); }

        T magnitude() const {
            T res = 0;

            for (std::size_t i = 0; i < N; i++) {
                res += std::pow(data[i], 2);
            }

            return std::sqrt(res);
        }

        static Vector normalize(const Vector& vec) {
            return vec / vec.magnitude();
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

        static Vector add(const Vector& lhs, const Vector& rhs) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = lhs[i] + rhs[i];
            }

            return res;
        }

        friend Vector operator+(const Vector& lhs, const Vector& rhs) {
            return add(lhs, rhs);
        }

        Vector operator+=(const Vector& other) {
            *this = *this + other;
            return *this;
        }

        static Vector subtract(const Vector& minuend, const Vector& subtrahend) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = minuend[i] - subtrahend[i];
            }

            return res;
        }

        friend Vector operator-(const Vector& minuend, const Vector& subtrahend) {
            return subtract(minuend, subtrahend);
        }

        Vector operator-=(const Vector& other) {
            *this = *this + other;
            return *this;
        }


        static T dot(const Vector& multiplicand, const Vector& multiplier) {
            T res = 0;

            for (std::size_t i = 0; i < N; i++) {
                res += multiplicand[i] * multiplier[i];
            }

            return res;
        }

        friend T operator*(const Vector& lhs, const Vector& rhs) {
            return dot(lhs, rhs);
        }

        Vector operator*=(const Vector& other) {
            *this = *this * other;
            return *this;
        }

        static Vector divide(const Vector& dividend, const Vector& divisor) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = dividend[i] / divisor[i];
            }

            return res;
        }

        friend Vector operator/(const Vector& dividend, const Vector& divisor) {
            return divide(dividend, divisor);
        }

        Vector operator/=(const Vector& other) {
            *this = *this / other;
            return *this;
        }

        static Vector modulus(const Vector& vec, const Vector& mod) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = vec[i] % mod[i];
            }

            return res;
        }

        friend Vector operator%(const Vector& vec, const Vector& mod) {
            return modulus(vec, mod);
        }

        Vector operator%=(const Vector& other) {
            *this = *this % other;
            return *this;
        }

        static Vector multiply(const Vector& vec, const T& scalar) {
            Vector res;

            for (std::size_t i = 0; i < N; i++) {
                res[i] = vec[i] * scalar;
            }

            return res;
        }

        friend Vector operator*(const Vector& vec, const T& scalar) {
            return multiply(vec, scalar);
        }

        Vector operator*=(const T& scalar) {
            *this = *this * scalar;
            return *this;
        }

        static Vector<3,T> cross(const Vector<3,T>& lhs, const Vector<3,T>& rhs) {
            Vector<3,T> res;

            res[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
            res[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
            res[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];

            return res;
        }

        Vector<3,T> operator&(const Vector<3,T>& other) const {
            return cross(*this, other);
        }
    };
}
