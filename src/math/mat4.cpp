
#include <math/mat4.h>
#include <math.h>
#include <iostream>

namespace math {
    mat4 invert(mat4 mat) {
        mat4 result{1.f};

        result.data[0][3] = -mat.data[0][3];
        result.data[1][3] = -mat.data[1][3];
        result.data[2][3] = -mat.data[2][3];

        return result;
    }

    mat4::mat4(float initValue) : rows{4}, columns{4} {
        data.resize(rows, std::vector<float>(columns, 0));
        int j = 0;
        for (int i = 0; i < rows; i++) {
            data[i][j] = initValue;
            j++;
        }
    }

    void mat4::translate(vec4 &other) {
        for (int i = 0; i < other.data.size(); i++) {
            data[i][columns - 1] += other.data[i];
        }
    }

    void mat4::scale(vec4 other) {

        mat4 to_origin = math::invert(*this);
        mat4 scale{1};

        scale.data[0][0] = other.data[0];
        scale.data[1][1] = other.data[1];
        scale.data[2][2] = other.data[2];

        mat4 return_m{1.f};

        return_m.data[0][3] = this->data[0][3];
        return_m.data[1][3] = this->data[1][3];
        return_m.data[2][3] = this->data[2][3];

        this->data = ((return_m * scale * to_origin) * *this).data;
    }


    void mat4::rotate(float angle, vec4 axis) {
        mat4 to_origin = math::invert(*this);

        mat4 rotation{1.f};

        float a1;

        mat4 r1{1.f};
        mat4 r2{1.f};
        mat4 r3{1.f};

        angle = (angle * M_PI) / 180;
        float a = cos(angle);

        if (axis.x() == 1) {
            r1.data[1][1] = cos(angle);
            r1.data[1][2] = -sin(angle);
            r1.data[2][1] = sin(angle);
            r1.data[2][2] = cos(angle);
        }
        if (axis.y() == 1) {
            r2.data[0][0] = cos(angle);
            r2.data[0][2] = sin(angle);
            r2.data[2][0] = -sin(angle);
            r2.data[2][2] = cos(angle);
        }
        if (axis.z() == 1) {
            r3.data[0][0] = cos(angle);
            r3.data[0][1] = -sin(angle);
            r3.data[1][0] = sin(angle);
            r3.data[1][1] = cos(angle);
        }

        mat4 return_m{1.f};

        return_m.data[0][3] = this->data[0][3];
        return_m.data[1][3] = this->data[1][3];
        return_m.data[2][3] = this->data[2][3];

        this->data = ((return_m * r1 * r2 * r3 * to_origin) * *this).data;
    }

    void mat4::rotate_axis(float angle, vec4 point) {
        mat4 to_origin = math::invert(*this);

//        point.x(10);
//        point.y(8);
//        point.z(6);

        mat4 rotation{1.f};
        angle = (angle * M_PI) / 180;
        float a = cos(angle);

        mat4 m1{1.f};

        //t1 = 31;

        float t1{0.f};
        if (point.x() != 0.f && point.z() != 0) {
            t1 = point.z() / point.x();
        } else {
            t1 = (90 * M_PI) / 180;
        }
        m1.data[0][0] = cos(t1);
        m1.data[0][2] = sin(t1);
        m1.data[2][0] = -sin(t1);
        m1.data[2][2] = cos(t1);

        auto t = point.multiply(m1);

        mat4 m2{1.f};

        if (point.y() != 0.f) {
            auto a1 = sqrt((point.x() * point.x()) + (point.z() * point.z()));
            auto a2 = sqrt((point.x() * point.x()) + (point.y() * point.y()) + (point.z() * point.z()));
            auto cos1 = a1 / a2;
            auto sin1 = point.y() / a2;

            m2.data[0][0] = cos1;
            m2.data[0][1] = sin1;
            m2.data[1][0] = -sin1;
            m2.data[1][1] = cos1;
        }

        rotation.data[1][1] = cos(angle);
        rotation.data[1][2] = -sin(angle);
        rotation.data[2][1] = sin(angle);
        rotation.data[2][2] = cos(angle);

        mat4 m4 = m2;
        m4.data[0][1] = -m4.data[0][1];
        m4.data[1][0] = -m4.data[1][0];

        mat4 m5 = m1;
        m5.data[0][2] = -m5.data[0][2];
        m5.data[2][0] = -m5.data[2][0];

        mat4 return_m{1.f};

        return_m.data[0][3] = this->data[0][3];
        return_m.data[1][3] = this->data[1][3];
        return_m.data[2][3] = this->data[2][3];

        this->data = ((return_m * m5 * m4 * rotation * m2 * m1 * to_origin) * *this).data;
    }

    void mat4::invert() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (data[i][j] != 0) {
                    data[i][j] = -data[i][j];
                }
            }
        }
    }

    mat4 mat4::operator+(const mat4 &other) const {
        if (columns != other.rows || rows != other.rows) {
            throw std::runtime_error("Invalid mat4 addition");
        }

        mat4 newmatrix{0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                newmatrix.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        newmatrix.toString();

        return newmatrix;
    }

    mat4 mat4::operator-(const mat4 &other) const {
        if (columns != other.rows || rows != other.rows) {
            throw std::runtime_error("Invalid mat4 subtraction");
        }

        mat4 newmatrix{0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                newmatrix.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return newmatrix;
    }

    std::string mat4::toString() const {
        std::string result = "";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.append(std::to_string(data[i][j]));
                result.append(", ");
            }
            result.append("\n");
        }
        return result;
    }


    mat4 mat4::operator*(const mat4 &other) const {
        if (columns != other.rows) {
            throw std::runtime_error("Invalid mat4 multiplication");
        }

        mat4 newmatrix{0};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    newmatrix.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return newmatrix;
    }

    mat4 mat4::operator*=(const mat4 &other) {
        if (columns != other.rows) {
            throw std::runtime_error("Invalid mat4 multiplication");
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return *this;
    }

    bool mat4::operator==(const mat4 &other) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (data[i][j] != other.data[i][j])
                    return false;
            }
        }
        return true;
    }


    bool mat4::operator!=(const mat4 &other) {
        return !(*this == other);
    }


    mat4 look_at(vec4 eye, vec4 lookat, vec4 up) {
        eye.w(1);
        lookat.w(1);
        up.w(1);

        vec4 direction = eye - lookat;

        auto right = up.cross(direction);
        up = direction.cross(right);

        up.normalize();
        right.normalize();
        direction.normalize();

        mat4 camera{1.f};

        camera.data[0][0] = right.x();
        camera.data[0][1] = right.y();
        camera.data[0][2] = right.z();

        camera.data[1][0] = up.x();
        camera.data[1][1] = up.y();
        camera.data[1][2] = up.z();

        camera.data[2][0] = direction.x();
        camera.data[2][1] = direction.y();
        camera.data[2][2] = direction.z();

        mat4 eye_m{1.f};
        eye_m.data[0][3] = -eye.x();
        eye_m.data[1][3] = -eye.y();
        eye_m.data[2][3] = -eye.z();

//        std::cout << eye_m.toString();

        return camera * eye_m;
    }
}