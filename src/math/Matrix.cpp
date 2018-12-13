
#include <math/Matrix.h>
#include <math.h>
#include <iostream>

namespace math {
    Matrix::Matrix(int rows, int columns, float initValue): rows{rows}, columns{columns} {
        data.resize(rows, std::vector<float>(columns, 0));
        int j = 0;
        for(int i = 0; i < rows; i++) {
            data[i][j] = initValue;
            j++;
        }
    }

    void Matrix::translate(Vector &other) {
        for(int i = 0; i < other.data.size(); i++) {
            data[i][columns-1] += other.data[i];
        }
    }

    void Matrix::scale(Vector other) {
        Vector test{data[0][columns-1], data[1][columns-1]};

        test.invert();
        translate(test);

        int j = 0;
        for(int i = 0; i < rows; i++) {
            data[i][j] += other.data[i];
            j++;
        }

        test.invert();
        translate(test);
    }


    void Matrix::rotate(float angle) {
        Vector test{data[0][columns-1], data[1][columns-1]};
        test.invert();
        translate(test);

        std::cout << toString() << std::endl;

        if(this->rows != 3 || this->columns != 3) {
            throw std::runtime_error("Invalid matrix rotation");
        }

        angle = (angle * M_PI) / 180;
        float a = cos(angle);

        data[0][0] += cos(angle);
        data[0][1] += -sin(angle);
        data[1][0] += sin(angle);
        data[1][1] += cos(angle);

        std::cout << toString() << std::endl;

        test.invert();
        translate(test);
        std::cout << toString() << std::endl;

    }

    void Matrix::invert() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                data[i][j] = -data[i][j];
            }
        }
    }

    Matrix Matrix::operator+(const Matrix &other) const {
        if(columns != other.rows || rows != other.rows) {
            throw std::runtime_error("Invalid matrix addition");
        }

        Matrix newMatrix{rows, columns, 0};
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                newMatrix.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        newMatrix.toString();

        return newMatrix;
    }

    Matrix Matrix::operator-(const Matrix &other) const {
        if(columns != other.rows || rows != other.rows) {
            throw std::runtime_error("Invalid matrix subtraction");
        }

        Matrix newMatrix{rows, columns, 0};
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                newMatrix.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return newMatrix;
    }

    std::string Matrix::toString() const {
        std::string result = "";
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                result.append(std::to_string(data[i][j]));
                result.append(", ");
            }
            result.append("\n");
        }
        return result;
    }


    Matrix Matrix::operator*(const Matrix &other) const {
        if(columns != other.rows) {
            throw std::runtime_error("Invalid matrix multiplication");
        }

        Matrix newMatrix{rows, other.columns, 0};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < other.columns; j++) {
                for(int k = 0; k < columns; k++) {
                    newMatrix.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return newMatrix;
    }

    Matrix Matrix::operator*=(const Matrix &other) {
        if(columns != other.rows) {
            throw std::runtime_error("Invalid matrix multiplication");
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < other.columns; j++) {
                for(int k = 0; k < columns; k++) {
                    data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return *this;
    }

}