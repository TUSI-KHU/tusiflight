#ifndef MATH_ANGLE_H
#define MATH_ANGLE_H

#include "math.h"

class Angle3DByValue;
class Angle3D
{
public:
    float roll, pitch, yaw;

    Angle3D(void);
    Angle3D(float Roll, float Pitch, float Yaw);
    void zero();
    bool isZero(float tolerance) const;

    // Allow pass by value
    operator Angle3DByValue &() { return *((Angle3DByValue *)(this)); }
    operator const Angle3DByValue &() const { return *((const Angle3DByValue *)(this)); }

    float operator[](int i) const;
    float &operator[](int i);

    bool operator==(const Angle3D &a) const;
    bool operator!=(const Angle3D &a) const;

    Angle3D &operator=(const Angle3D &other);
    Angle3D operator+(const Angle3D &a) const;
    Angle3D operator-(void) const;
    Angle3D operator-(const Angle3D &a) const;
    Angle3D operator*(float fl) const;
    Angle3D operator/(float fl) const;

    Angle3D &operator+=(const Angle3D &a);
    Angle3D &operator-=(const Angle3D &a);
    Angle3D &operator*=(float s);
    Angle3D &operator/=(float s);

    float length() const;
    float lengthSqrared() const;
    Angle3D normalize() const;
    void normalizeInPlace();

    // base address...
    float *base();
    float const *base() const;
};

#endif
