#pragma once

#include <array>
#include <initializer_list>
#include <type_traits>

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

    Vector operator+(const Vector& other) const {
        Vector res;

        for (std::size_t i = 0; i < N; i++) {
            res.data[i] = data[i] + other.data[i];
        }

        return res;
    }

    Vector operator-(const Vector& other) const {
        Vector res;

        for (std::size_t i = 0; i < N; i++) {
            res.data[i] = data[i] - other.data[i];
        }

        return res;
    }

    T operator*(const Vector& other) const {
        T res = 0;

        for (std::size_t i = 0; i < N; i++) {
            res+= data[i] * other.data[i];
        }

        return res;
    }

    Vector operator&(const Vector& other) const {

        static_assert(N == 3, "Cross product is only defined for 3D vectors");

        Vector res;

        res.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
        res.data[1] = data[2] * other.data[0] - data[0] * other.data[2];
        res.data[2] = data[0] * other.data[1] - data[1] * other.data[0];

        return res;
    }
};
