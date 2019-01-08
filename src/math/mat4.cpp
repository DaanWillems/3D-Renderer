
#include <math/mat4.h>
#include <math.h>
#include <iostream>

namespace math {
    mat4::mat4(float initValue): rows{4}, columns{4} {
        data.resize(rows, std::vector<float>(columns, 0));
        int j = 0;
        for(int i = 0; i < rows; i++) {
            data[i][j] = initValue;
            j++;
        }
    }

    void mat4::translate(vector &other) {
        for(int i = 0; i < other.data.size(); i++) {
            data[i][columns-1] += other.data[i];
        }
    }

    void mat4::scale(vector other) {
        vector test{data[0][columns-1], data[1][columns-1]};

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


    void mat4::rotate(float angle) {
        vector test{data[0][columns-1], data[1][columns-1]};
        test.invert();
        translate(test);

        std::cout << toString() << std::endl;

        if(this->rows != 3 || this->columns != 3) {
            throw std::runtime_error("Invalid mat4 rotation");
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

    void mat4::invert() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                data[i][j] = -data[i][j];
            }
        }
    }

    mat4 mat4::operator+(const mat4 &other) const {
        if(columns != other.rows || rows != other.rows) {
            throw std::runtime_error("Invalid mat4 addition");
        }

        mat4 newmatrix{0};
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                newmatrix.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        newmatrix.toString();

        return newmatrix;
    }

    mat4 mat4::operator-(const mat4 &other) const {
        if(columns != other.rows || rows != other.rows) {
            throw std::runtime_error("Invalid mat4 subtraction");
        }

        mat4 newmatrix{0};
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                newmatrix.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return newmatrix;
    }

    std::string mat4::toString() const {
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


    mat4 mat4::operator*(const mat4 &other) const {
        if(columns != other.rows) {
            throw std::runtime_error("Invalid mat4 multiplication");
        }

        mat4 newmatrix{0};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < other.columns; j++) {
                for(int k = 0; k < columns; k++) {
                    newmatrix.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return newmatrix;
    }

    mat4 mat4::operator*=(const mat4 &other) {
        if(columns != other.rows) {
            throw std::runtime_error("Invalid mat4 multiplication");
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