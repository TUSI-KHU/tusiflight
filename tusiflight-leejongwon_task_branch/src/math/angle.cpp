#include "angle.h"
#include <assert.h>

Angle3D::Angle3D(void) { zero(); }

Angle3D::Angle3D(float Roll, float Pitch, float Yaw)
{
    roll = Roll;
    pitch = Pitch;
    yaw = Yaw;
}

void Angle3D::zero()
{
    roll = pitch = yaw = 0.0f;
}

bool Angle3D::isZero(float tolerance = EPSILON) const
{
    return (roll > -tolerance && roll < tolerance &&
            pitch > -tolerance && pitch < tolerance &&
            yaw > -tolerance && yaw < tolerance);
}

float &Angle3D::operator[](int i)
{
    assert((i >= 0) && (i < 3));
    return ((float *)this)[i];
}

float Angle3D::operator[](int i) const
{
    assert((i >= 0) && (i < 3));
    return ((float *)this)[i];
}

bool Angle3D::operator==(const Angle3D &source) const
{
    return (abs(source.roll - roll) <= EPSILON &&
            abs(source.pitch - pitch) <= EPSILON &&
            abs(source.yaw - yaw) <= EPSILON);
}

bool Angle3D::operator!=(const Angle3D &source) const
{
    return (abs(source.roll - roll) > EPSILON ||
            abs(source.pitch - pitch) > EPSILON ||
            abs(source.yaw - yaw) > EPSILON);
}

Angle3D &Angle3D::operator=(const Angle3D &other)
{
    roll = other.roll;
    pitch = other.pitch;
    yaw = other.yaw;
    return *this;
}

Angle3D Angle3D::operator+(const Angle3D &a) const
{
    Angle3D res;
    res.roll = roll + a.roll;
    res.pitch = pitch + a.pitch;
    res.yaw = yaw + a.yaw;
    return res;
}

Angle3D Angle3D::operator-(void) const
{
    Angle3D res;
    res.roll = -roll;
    res.pitch = -pitch;
    res.yaw = -yaw;

    return res;
}

Angle3D Angle3D::operator-(const Angle3D &a) const
{
    Angle3D res;
    res.roll = roll - a.roll;
    res.pitch = pitch - a.pitch;
    res.yaw = yaw - a.yaw;
    return res;
}

Angle3D Angle3D::operator*(float fl) const
{
    Angle3D res;
    res.roll = roll * fl;
    res.pitch = pitch * fl;
    res.yaw = yaw * fl;
    return res;
}

Angle3D Angle3D::operator/(float fl) const
{
    assert(fl != 0.0f);
    Angle3D res;
    res.roll = roll / fl;
    res.pitch = pitch / fl;
    res.yaw = yaw / fl;
    return res;
}

Angle3D &Angle3D::operator+=(const Angle3D &a)
{
    roll += a.roll;
    pitch += a.pitch;
    yaw += a.yaw;
    return *this;
}

Angle3D &Angle3D::operator-=(const Angle3D &a)
{
    roll -= a.roll;
    pitch -= a.pitch;
    yaw -= a.yaw;
    return *this;
}

Angle3D &Angle3D::operator*=(float fl)
{
    roll *= fl;
    pitch *= fl;
    yaw *= fl;
    return *this;
}

Angle3D &Angle3D::operator/=(float fl)
{
    assert(fl != 0.0f);
    float oofl = 1.0f / fl;
    roll *= oofl;
    pitch *= oofl;
    yaw *= oofl;
    return *this;
}

float Angle3D::length(void) const
{
    float root = 0.0f;
    float sqsr = roll * roll + pitch * pitch + yaw * yaw;
    root = sqrt(sqsr);
    return root;
}

float Angle3D::lengthSqrared() const
{
    return roll * roll + pitch * pitch + yaw * yaw;
}

Angle3D Angle3D::normalize() const
{
    float r = fmodf((fmodf(roll, 180.f) + 360.f), 360.f);
    if (r > 180.f)
        r -= 180.f;

    float p = fmodf((fmodf(pitch, 180.f) + 360.f), 360.f);
    if (p > 180.f)
        p -= 180.f;

    float y = fmodf((fmodf(yaw, 180.f) + 360.f), 360.f);
    if (y > 180.f)
        y -= 180.f;

    return Angle3D(r, p, y);
}

void Angle3D::normalizeInPlace()
{
    roll = fmodf((fmodf(roll, 180) + 360), 360);
    if (roll > 180)
        roll -= 180;

    pitch = fmodf((fmodf(pitch, 180) + 360), 360);
    if (pitch > 180)
        pitch -= 180;

    yaw = fmodf((fmodf(yaw, 180) + 360), 360);
    if (yaw > 180)
        yaw -= 180;
}

float *Angle3D::base()
{
    return (float *)this;
}

float const *Angle3D::base() const
{
    return (float const *)this;
}
