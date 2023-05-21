#include "complex_num.h"

complex_num::complex_num(double r, double i){
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real =  real + w.real;
    z.imaginary =  imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real =  real - w.real;
    z.imaginary =  imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.real =  (real*w.real) - (imaginary*w.imaginary);
    z.imaginary =  (real*w.imaginary) +(imaginary*w.real);
    return z;
}
// z/w = (a+ib)/(c+id) = ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
complex_num complex_num::operator /(complex_num w){
    complex_num z;
    z.real = ((real*w.real)+ (imaginary*w.imaginary))/((w.imaginary*w.imaginary)+(w.real*w.real));
    z.imaginary = ((imaginary*w.real)-(real*w.imaginary))/((w.imaginary*w.imaginary)+(w.real*w.real));

    return z;
}

void complex_num::print(std::ostream &os){
    if(imaginary >= 0.0)
        os << real << " + " << imaginary << "i";
    else
        os << real << " - " << imaginary * -1 << "i";
    os << std::flush;
}