//
// Created by vincent on 11/15/18.
//

#ifndef RDALGEBRA2_MATRIX_H
#define RDALGEBRA2_MATRIX_H

template <typename T, int R, int C>
class Matrix {
//public:
//    Matrix<T, R, C> operator+(const Matrix<T, R, C> &other) const {
//        Matrix<T, R, C> target
//        return target += other;
//    }
//
//    Matrix<T, R, C> operator+=(const Matrix<T, R, C> &other) const {
//        add(this, other);
//        return *this;
//    }
//
//    Matrix<T, R, C> operator-=(const Matrix<T, R, C> &other) const {
//        subtract(this, other);
//        return *this;
//    }
//
//    Matrix<T, R, C> operator*=(const Matrix<T, R, C> &other) const {
//        multiply(this, other);
//        return *this;
//    }
//
//    Matrix<T, R, C> operator/=(const Matrix<T, R, C> &other) const {
//        multiply(this, other);
//        return *this;
//    };

private:
//    T[R][C] items;

    int rows;
    int columns;
};

template <typename T, int R, int C>
Matrix<T, R, R> multiply(Matrix<T, R, C> &target, const Matrix<T, C, R> &multiplier) {
    Matrix<T, R, R> result;

    return result;
}

template <typename T, int R, int C>
Matrix<T, R, C> add(Matrix<T, R, C> &target, const Matrix<T, R, C> &addition) {
    Matrix<T, R, C> result;

    return result;
}

template <typename T, int R, int C>
Matrix<T, R, C> substract(Matrix<T, R, C> &target, const Matrix<T, R, C> &subtraction) {
    Matrix<T, R, C> result;

    return result;
}

template <typename T, int R, int C>
Matrix<T, R, C> divide(Matrix<T, R, C> &target, const Matrix<T, R, C> &divider) {
    Matrix<T, R, C> result;

    return result;
}

#endif //RDALGEBRA2_MATRIX_H
