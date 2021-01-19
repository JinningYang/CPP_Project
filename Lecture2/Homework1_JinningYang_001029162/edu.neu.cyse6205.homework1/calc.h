#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <iostream>
#include <string>

namespace edu {
namespace neu {
namespace csye6205 {
class calc {
public:
    double add(double a,double b);
    double sub(double a,double b);
    double mult(double a,double b);
    double div(double a,double b);
    calc();
    virtual ~calc();
    virtual void calculate(double a, double b);
};
}
}
}

#endif // CALC_H_INCLUDED
