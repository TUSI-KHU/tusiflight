#include "vector.h"
#include <assert.h>

Vector3D::Vector3D(void) { zero(); }

Vector3D::Vector3D(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

void Vector3D::zero()
{
    x = y = z = 0.0f;
}

bool Vector3D::isZero(float tolerance = EPSILON) const
{
    return (x > -tolerance && x < tolerance &&
            y > -tolerance && y < tolerance &&
            z > -tolerance && z < tolerance);
}

float &Vector3D::operator[](int i)
{
    assert((i >= 0) && (i < 3));
    return ((float *)this)[i];
}

float Vector3D::operator[](int i) const
{
    assert((i >= 0) && (i < 3));
    return ((float *)this)[i];
}

bool Vector3D::operator==(const Vector3D &source) const
{
    return (abs(source.x - x) <= EPSILON &&
            abs(source.y - y) <= EPSILON &&
            abs(source.z - z) <= EPSILON);
}

bool Vector3D::operator!=(const Vector3D &source) const
{
    return (abs(source.x - x) > EPSILON ||
            abs(source.y - y) > EPSILON ||
            abs(source.z - z) > EPSILON);
}

Vector3D &Vector3D::operator=(const Vector3D &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    Vector3D res;
    res.x = x + v.x;
    res.y = y + v.y;
    res.z = z + v.z;
    return res;
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    Vector3D res;
    res.x = x - v.x;
    res.y = y - v.y;
    res.z = z - v.z;
    return res;
}

Vector3D Vector3D::operator*(float fl) const
{
    Vector3D res;
    res.x = x * fl;
    res.y = y * fl;
    res.z = z * fl;
    return res;
}

Vector3D Vector3D::operator*(const Vector3D &v) const
{
    Vector3D res;
    res.x = x * v.x;
    res.y = y * v.y;
    res.z = z * v.z;
    return res;
}

Vector3D Vector3D::operator/(float fl) const
{
    assert(fl != 0.0f);
    Vector3D res;
    res.x = x / fl;
    res.y = y / fl;
    res.z = z / fl;
    return res;
}

Vector3D Vector3D::operator/(const Vector3D &v) const
{
    Vector3D res;
    res.x = x / v.x;
    res.y = y / v.y;
    res.z = z / v.z;
    return res;
}

Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D &Vector3D::operator+=(float fl)
{
    x += fl;
    y += fl;
    z += fl;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3D &Vector3D::operator-=(float fl)
{
    x -= fl;
    y -= fl;
    z -= fl;
    return *this;
}

Vector3D &Vector3D::operator*=(float fl)
{
    x *= fl;
    y *= fl;
    z *= fl;
    return *this;
}

Vector3D &Vector3D::operator*=(const Vector3D &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vector3D &Vector3D::operator/=(float fl)
{
    assert(fl != 0.0f);
    float oofl = 1.0f / fl;
    x *= oofl;
    y *= oofl;
    z *= oofl;
    return *this;
}

Vector3D &Vector3D::operator/=(const Vector3D &v)
{
    assert(v.x != 0.0f && v.y != 0.0f && v.z != 0.0f);
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

float Vector3D::length(void) const
{
    float root = 0.0f;
    float sqsr = x * x + y * y + z * z;
    root = sqrt(sqsr);
    return root;
}

float Vector3D::lengthSqrared() const
{
    return x * x + y * y + z * z;
}

float Vector3D::length2D(void) const
{
    float root = 0.0f;
    float sqst = x * x + y * y;
    root = sqrt(sqst);
    return root;
}

float Vector3D::length2DSqared(void) const
{
    return (x * x + y * y);
}

Vector3D Vector3D::normalize()
{
    Vector3D vector;
    float length = this->length();

    if (length != 0)
    {
        vector.x = x / length;
        vector.y = y / length;
        vector.z = z / length;
    }
    else
    {
        vector.x = vector.y = 0.0f;
        vector.z = 1.0f;
    }

    return vector;
}

float Vector3D::normalizeInPlace()
{
    Vector3D &v = *this;

    float iradius = 1.f / (this->length() + 1.192092896e-07F); // FLT_EPSILON

    v.x *= iradius;
    v.y *= iradius;
    v.z *= iradius;
}

float Vector3D::distanceTo(const Vector3D &other) const
{
    Vector3D delta;

    delta.x = x - other.x;
    delta.y = y - other.y;
    delta.z = z - other.z;

    return delta.length();
}

float Vector3D::distanceToSqared(const Vector3D &other) const
{
    Vector3D delta;

    delta.x = x - other.x;
    delta.y = y - other.y;
    delta.z = z - other.z;

    return delta.lengthSqrared();
}

float Vector3D::dotProduct(const Vector3D &other) const
{
    const Vector3D &a = *this;
    return (a.x * other.x + a.y * other.y + a.z * other.z);
}

Vector3D Vector3D::crossProduct(const Vector3D &other) const
{
    return Vector3D(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float *Vector3D::base()
{
    return (float *)this;
}

float const *Vector3D::base() const
{
    return (float const *)this;
}
