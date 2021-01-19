#include "calc.h"

namespace edu{
namespace neu{
namespace csye6205{
    calc::calc(){
    }

    calc::~calc(){
    }

    void calc::calculate(double a, double b){
        std::cout<<"a+b = "<< add(a, b) << ", a-b = " << sub(a, b) << ", a*b = " << mult(a, b) << ", a/b = " << div(a, b)<<std::endl;
    }

    double calc::add(double a,double b){
        return 0.0;
    }

    double calc::sub(double a,double b){
        return 0.0;
    }

    double calc::mult(double a,double b){
        return 0.0;
    }

    double calc::div(double a,double b){
        return 0.0;
    }
}
}
}
