#include <raylib/mat4.hpp>
#include <stdexcept>
#include <sstream>
#include <iomanip>

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


#define VEC4DOT(a0, a1, a2, a3, b0, b1, b2, b3) (a0 * b0 + a1 * b1 + a2 * b2 + a3 * b3)

    Mat4 &Mat4::operator*=(Mat4 b) {
        /*
         * a = this
         * b = other
         *
         *                    b11 b12 b13 b14
         *                    b21 b22 b23 b24
         *                    b31 b32 b33 b34
         *                    b41 b42 b43 b44
         *
         *  a11 a12 a13 a14   
         *  a21 a22 a23 a24
         *  a31 a32 a33 a34
         *  a41 a42 a43 a44
         */
        // NOTE: Slower than ideal.
        m11 = VEC4DOT(m11, m12, m13, m13, b.m11, b.m21, b.m31, b.m41);
        m12 = VEC4DOT(m11, m12, m13, m13, b.m12, b.m22, b.m32, b.m42);
        m13 = VEC4DOT(m11, m12, m13, m13, b.m13, b.m23, b.m33, b.m43);
        m14 = VEC4DOT(m11, m12, m13, m13, b.m14, b.m24, b.m34, b.m44);
        m21 = VEC4DOT(m21, m22, m23, m23, b.m11, b.m21, b.m31, b.m41);
        m22 = VEC4DOT(m21, m22, m23, m23, b.m12, b.m22, b.m32, b.m42);
        m23 = VEC4DOT(m21, m22, m23, m23, b.m13, b.m23, b.m33, b.m43);
        m24 = VEC4DOT(m21, m22, m23, m23, b.m14, b.m24, b.m34, b.m44);
        m31 = VEC4DOT(m31, m32, m33, m33, b.m11, b.m21, b.m31, b.m41);
        m32 = VEC4DOT(m31, m32, m33, m33, b.m12, b.m22, b.m32, b.m42);
        m33 = VEC4DOT(m31, m32, m33, m33, b.m13, b.m23, b.m33, b.m43);
        m34 = VEC4DOT(m31, m32, m33, m33, b.m14, b.m24, b.m34, b.m44);
        m41 = VEC4DOT(m41, m42, m43, m43, b.m11, b.m21, b.m31, b.m41);
        m42 = VEC4DOT(m41, m42, m43, m43, b.m12, b.m22, b.m32, b.m42);
        m43 = VEC4DOT(m41, m42, m43, m43, b.m13, b.m23, b.m33, b.m43);
        m44 = VEC4DOT(m41, m42, m43, m43, b.m14, b.m24, b.m34, b.m44);
        return *this;
    }

    Mat4 operator*(Mat4 a, Mat4 b) {
        a *= b;
        return a;
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

    std::ostream &operator<<(std::ostream &stream, Mat4 matrix) {
        std::stringstream string_stream;
        string_stream << std::showpoint << std::fixed << std::setprecision(3) << 
            "Mat4[m1X: " << matrix.m11 << ", " << matrix.m12 << ", " << matrix.m13 << ", " << matrix.m14 <<
            " | m2X: " << matrix.m21 << ", " << matrix.m22 << ", " << matrix.m23 << ", " << matrix.m24 <<
            " | m3X: " << matrix.m31 << ", " << matrix.m32 << ", " << matrix.m33 << ", " << matrix.m34 <<
            " | m4X: " << matrix.m41 << ", " << matrix.m42 << ", " << matrix.m43 << ", " << matrix.m44 << "]";
        stream << string_stream.str();
        return stream;
    }
}
