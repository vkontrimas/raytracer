#include <raylib/mat4.hpp>
#include <stdexcept>

namespace {
    float getElement(const std::initializer_list<float> &list, int index) {
        if (index < 0 || index >= list.size()) {
            throw std::out_of_range("getElement index is out of range");
        }
        return (*(list.begin() + index));
    }
}
namespace raylib {
    Mat4::Mat4(float diagonal) : m11(diagonal), m22(diagonal), m33(diagonal), m44(diagonal) {}
    Mat4::Mat4(std::initializer_list<float> list) {
        if (list.size() != 16) {
            throw std::invalid_argument("Mat4 initializer list constructor requires exactly 16 elements.");
        }

        m11 = getElement(list, 0);
        m12 = getElement(list, 1);
        m13 = getElement(list, 2);
        m14 = getElement(list, 3);
        m21 = getElement(list, 4);
        m22 = getElement(list, 5);
        m23 = getElement(list, 6);
        m24 = getElement(list, 7);
        m31 = getElement(list, 8);
        m32 = getElement(list, 9);
        m33 = getElement(list, 10);
        m34 = getElement(list, 11);
        m41 = getElement(list, 12);
        m42 = getElement(list, 13);
        m43 = getElement(list, 14);
        m44 = getElement(list, 15);
    }

    Mat4 &Mat4::operator*=(float scalar) {
        m11 *= scalar;
        m12 *= scalar;
        m13 *= scalar;
        m14 *= scalar;
        m21 *= scalar;
        m22 *= scalar;
        m23 *= scalar;
        m24 *= scalar;
        m31 *= scalar;
        m32 *= scalar;
        m33 *= scalar;
        m34 *= scalar;
        m41 *= scalar;
        m42 *= scalar;
        m43 *= scalar;
        m44 *= scalar;
        return *this;
    }

    Mat4 operator*(float scalar, Mat4 matrix) {
        matrix *= scalar;
        return matrix;
    }
    
    Mat4 operator*(Mat4 matrix, float scalar) {
        matrix *= scalar;
        return matrix;
    }

    bool operator==(Mat4 a, Mat4 b) {
        return a.m11 == b.m11 &&
               a.m12 == b.m12 &&
               a.m13 == b.m13 &&
               a.m14 == b.m14 &&
               a.m21 == b.m21 &&
               a.m22 == b.m22 &&
               a.m23 == b.m23 &&
               a.m24 == b.m24 &&
               a.m31 == b.m31 &&
               a.m32 == b.m32 &&
               a.m33 == b.m33 &&
               a.m34 == b.m34 &&
               a.m41 == b.m41 &&
               a.m42 == b.m42 &&
               a.m43 == b.m43 &&
               a.m44 == b.m44;
    }

    bool operator!=(Mat4 a, Mat4 b) {
        return !(a == b);
    }
}
