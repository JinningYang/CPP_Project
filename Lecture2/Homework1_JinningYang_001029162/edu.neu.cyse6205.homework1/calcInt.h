#ifndef CALCINT_H_INCLUDED
#define CALCINT_H_INCLUDED

#include <iostream>
#include <string>
#include "calc.h"

using namespace std;


namespace edu {
namespace neu {
namespace csye6205 {

class calcInt : public calc {
private:
    string Operator="+";
    int a;
    int b;
    int result;
    void assign(double a,double b);
public:
    calcInt();
    virtual ~calcInt();

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

#endif // CALCINT_H_INCLUDED
