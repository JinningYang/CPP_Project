#ifndef CALCDOUB_H_INCLUDED
#define CALCDOUB_H_INCLUDED

#include "calc.h"
#include <string>
using namespace std;

namespace edu{
namespace neu{
namespace csye6205{
class calcDoub : public calc {
private:
    string Operator = "+";
    double a;
    double b;
    double result;
    void assign(double a,double b);
public:
    calcDoub();
    virtual ~calcDoub();

    virtual void calculate(double a, double b) override;

    void demo(double a,double b);

    double add(double a,double b);

    double sub(double a,double b);

    double mult(double a,double b);

    double div(double a,double b);
};
}
}
}

#endif // CALCDOUB_H_INCLUDED
