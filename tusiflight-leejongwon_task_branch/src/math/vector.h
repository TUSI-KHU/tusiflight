#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include "math.h"

class Vector3D
{
public:
    float x, y, z;

    Vector3D(void);
    Vector3D(float X, float Y, float Z);
    void zero();
    bool isZero(float tolerance = EPSILON) const;

    float operator[](int i) const;
    float &operator[](int i);

    bool operator==(const Vector3D &v) const;
    bool operator!=(const Vector3D &v) const;

    Vector3D &operator=(const Vector3D &other);
    Vector3D operator+(const Vector3D &v) const;
    Vector3D operator-(const Vector3D &v) const;
    Vector3D operator*(float fl) const;
    Vector3D operator*(const Vector3D &v) const;
    Vector3D operator/(float fl) const;
    Vector3D operator/(const Vector3D &v) const;

    Vector3D &operator+=(const Vector3D &v);
    Vector3D &operator+=(float fl);
    Vector3D &operator-=(const Vector3D &v);
    Vector3D &operator-=(float fl);
    Vector3D &operator*=(const Vector3D &v);
    Vector3D &operator*=(float s);
    Vector3D &operator/=(const Vector3D &v);
    Vector3D &operator/=(float s);

    float length() const;
    float lengthSqrared() const;
    float length2D() const;
    float length2DSqared() const;
    Vector3D normalize();
    void normalizeInPlace();
    float distanceTo(const Vector3D &other) const;
    float distanceToSqared(const Vector3D &other) const;
    float dotProduct(const Vector3D &other) const;
    Vector3D crossProduct(const Vector3D &other) const;

    // base address...
    float *base();
    float const *base() const;
};

#endif
