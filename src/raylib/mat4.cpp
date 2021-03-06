#include <raylib/mat4.hpp>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cmath>

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


#define VEC4DOT(a0, a1, a2, a3, b0, b1, b2, b3) ((a0 * b0) + (a1 * b1) + (a2 * b2) + (a3 * b3))

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
        float r11 = VEC4DOT(m11, m12, m13, m14, b.m11, b.m21, b.m31, b.m41);
        float r12 = VEC4DOT(m11, m12, m13, m14, b.m12, b.m22, b.m32, b.m42);
        float r13 = VEC4DOT(m11, m12, m13, m14, b.m13, b.m23, b.m33, b.m43);
        float r14 = VEC4DOT(m11, m12, m13, m14, b.m14, b.m24, b.m34, b.m44);
        float r21 = VEC4DOT(m21, m22, m23, m24, b.m11, b.m21, b.m31, b.m41);
        float r22 = VEC4DOT(m21, m22, m23, m24, b.m12, b.m22, b.m32, b.m42);
        float r23 = VEC4DOT(m21, m22, m23, m24, b.m13, b.m23, b.m33, b.m43);
        float r24 = VEC4DOT(m21, m22, m23, m24, b.m14, b.m24, b.m34, b.m44);
        float r31 = VEC4DOT(m31, m32, m33, m34, b.m11, b.m21, b.m31, b.m41);
        float r32 = VEC4DOT(m31, m32, m33, m34, b.m12, b.m22, b.m32, b.m42);
        float r33 = VEC4DOT(m31, m32, m33, m34, b.m13, b.m23, b.m33, b.m43);
        float r34 = VEC4DOT(m31, m32, m33, m34, b.m14, b.m24, b.m34, b.m44);
        float r41 = VEC4DOT(m41, m42, m43, m44, b.m11, b.m21, b.m31, b.m41);
        float r42 = VEC4DOT(m41, m42, m43, m44, b.m12, b.m22, b.m32, b.m42);
        float r43 = VEC4DOT(m41, m42, m43, m44, b.m13, b.m23, b.m33, b.m43);
        float r44 = VEC4DOT(m41, m42, m43, m44, b.m14, b.m24, b.m34, b.m44);
        m11 = r11; m12 = r12; m13 = r13; m14 = r14;
        m21 = r21; m22 = r22; m23 = r23; m24 = r24;
        m31 = r31; m32 = r32; m33 = r33; m34 = r34;
        m41 = r41; m42 = r42; m43 = r43; m44 = r44;
        return *this;
    }

    Mat4 operator*(Mat4 a, Mat4 b) {
        a *= b;
        return a;
    }

    Vec3 operator*(Mat4 a, Vec3 b) {
        /*
         * a = this
         * b = vector4
         *
         *                    bX
         *                    bY
         *                    bZ
         *                    bW
         *
         *  a11 a12 a13 a14   
         *  a21 a22 a23 a24
         *  a31 a32 a33 a34
         *  a41 a42 a43 a44
         */
        Vec3 vec;
        vec.x = VEC4DOT(a.m11, a.m12, a.m13, a.m14, b.x, b.y, b.z, 1.0f);
        vec.y = VEC4DOT(a.m21, a.m22, a.m23, a.m24, b.x, b.y, b.z, 1.0f);
        vec.z = VEC4DOT(a.m31, a.m32, a.m33, a.m34, b.x, b.y, b.z, 1.0f);
        return vec;
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

    Mat4 Mat4::transpose() const {
        Mat4 result = {
            m11, m21, m31, m41,
            m12, m22, m32, m42,
            m13, m23, m33, m43,
            m14, m24, m34, m44
        };
        return result;
    }

    Vec3 Mat4::getTranslation() const {
        return Vec3(m14, m24, m34);
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

    Mat4 Mat4::translate(Vec3 translation) {
        Mat4 result(1.0f);
        result.m14 = translation.x;
        result.m24 = translation.y;
        result.m34 = translation.z;
        return result;
    }

    Mat4 Mat4::rotateX(float theta) {
        Mat4 rotation(1.0f);
        rotation.m22 = std::cos(theta);
        rotation.m23 = std::sin(theta);
        rotation.m32 = -std::sin(theta);
        rotation.m33 = std::cos(theta);
        return rotation;
    }

    Mat4 Mat4::rotateY(float theta) {
        Mat4 rotation(1.0f);
        rotation.m11 = std::cos(theta);
        rotation.m13 = -std::sin(theta);
        rotation.m31 = std::sin(theta);
        rotation.m33 = std::cos(theta);
        return rotation;
    }

    Mat4 Mat4::rotateZ(float theta) {
        Mat4 rotation(1.0f);
        rotation.m11 = std::cos(theta);
        rotation.m12 = std::sin(theta);
        rotation.m21 = -std::sin(theta);
        rotation.m22 = std::cos(theta);
        return rotation;
    }

    Mat4 Mat4::rotate(Vec3 axis, float angle) {
        // TODO: Write tests.
        float cos = std::cos(angle);
        float oneMinusCos = 1.0f - cos;
        float sin = std::sin(angle);
        Mat4 rotation(1.0f);
        rotation.m11 = axis.x * axis.x * oneMinusCos + cos;
        rotation.m12 = axis.x * axis.y * oneMinusCos + axis.z * sin;
        rotation.m13 = axis.x * axis.z * oneMinusCos - axis.y * sin;
        rotation.m21 = axis.x * axis.y * oneMinusCos - axis.z * sin;
        rotation.m22 = axis.y * axis.y * oneMinusCos + cos;
        rotation.m23 = axis.y * axis.z * oneMinusCos + axis.x * sin;
        rotation.m31 = axis.x * axis.z * oneMinusCos + axis.y * sin;
        rotation.m32 = axis.y * axis.z * oneMinusCos - axis.x * sin;
        rotation.m33 = axis.z * axis.z * oneMinusCos + cos;
        return rotation;
    }

    Mat4 Mat4::rotation(float x, float y, float z) {
        return rotateX(x) * rotateY(y) * rotateZ(z);
    }
}
