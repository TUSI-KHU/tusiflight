#include "complex.h"

complex::complex(const complex &ref){
    _real = ref._real;
    _img = ref._img;
}

float complex::real(){
    return _real;
}

float complex::img(){
    return _img;
}

float complex::abs(){
    return sqrt((_real*_real+_img*_img));
}

int complex::complex::ctoi(){
    return int(_real);
}

float complex::ctof(){
    return _real;
}

// 켤레 복소수
complex complex::conjugate(){
    complex temp(_real, -(_img));
    return temp;
}

complex complex::operator+(const complex &ref){
    return complex(_real+ref._real, _img+ref._img);
}

complex complex::operator-(const complex &ref){
    return complex(_real-ref._real, _img-ref._img);
}

complex complex::operator*(const complex &ref){
    float real = _real*ref._real-_img*ref._img;
    float img = _real*ref._img + _img*ref._real;
    return complex(real, img);
}

complex complex::operator/(const complex &ref){
    complex temp = (*this)*complex(ref._real, -(ref._img));
    float denom = ref._real*ref._real+ref._img*ref._img;
    temp._real/=denom;
    temp._img/=denom;
    return temp;
}

complex &complex::operator=(const complex &ref){
    _real = ref._real;
    _img = ref._img;
    return *this;
}

complex &complex::operator+=(const complex &ref){
    _real+=ref._real;
    _img+=ref._img;
    return *this;
}

complex &complex::operator-=(const complex &ref){
    _real-=ref._real;
    _img-=ref._img;
    return *this;
}

complex &complex::operator*=(const complex &ref){
    *this = (*this)*(ref);  
    return *this;
}

complex &complex::operator/=(const complex &ref){
    *this = (*this)/(ref);  
    return *this;
}

bool complex::operator==(const complex &ref){
    if((_real==ref._real)&&(_img==ref._img)) return true;
    else return false;
}


complex operator+(const float refF, complex &refC){
    complex ans(refF);
    return refC+ans;
}

complex operator+(complex &refC, const float refF){
    complex ans(refF);
    return refC+ans;
}

complex operator-(const float refF, complex &refC){
    complex ans(refF);
    return refC-ans;
}

complex operator-(complex &refC, const float refF){
    complex ans(refF);
    return refC-ans;
}

complex operator*(const float refF, complex &refC){
    complex ans(refF);
    return refC*ans;
}
complex operator*(complex &refC, const float refF){
    complex ans(refF);
    return refC*ans;
}

complex operator/(const float refF, complex &refC){
    complex ans(refF);
    return refC/ans;
}

complex operator/(complex &refC, const float refF){
    complex ans(refF);
    return refC/ans; 
}
