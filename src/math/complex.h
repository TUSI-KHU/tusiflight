#ifndef COMPLEX_H
#define COMPLEX_H
#include<math.h>

// 부동 소수점 정밀도 정할 필요 있음
class complex{
public:
    complex() : _real(0), _img(0){}
    complex(float real, float img = 0) : _real(real), _img(img){}

    complex(const complex &ref);

    float real();

    float img();

    float abs();

    int ctoi();

    float ctof();

    // 켤레 복소수
    complex conjugate();

    complex operator+(const complex &);

    complex operator-(const complex &);

    complex operator*(const complex &);

    complex operator/(const complex &);

    complex &operator=(const complex &);

    complex &operator+=(const complex &);

    complex &operator-=(const complex &);

    complex &operator*=(const complex &);

    complex &operator/=(const complex &);

    bool operator==(const complex &);

    friend complex operator+(const float, complex &);
    friend complex operator+(complex &, const float);

    friend complex operator-(const float, complex &);
    friend complex operator-(complex &, const float);

    friend complex operator*(const float, complex &);
    friend complex operator*(complex &, const float);

    friend complex operator/(const float, complex &);
    friend complex operator/(complex &, const float);

private:
    float _real;
    float _img;
};

complex operator+(const float, complex &);
complex operator+(complex &, const float);

complex operator-(const float, complex &);
complex operator-(complex &, const float);

complex operator*(const float, complex &);
complex operator*(complex &, const float );

complex operator/(const float, complex &);
complex operator/(complex &, const float);
#endif