#include "calcInt.h"

namespace edu{
namespace neu{
namespace csye6205{
    calcInt::calcInt(){}
    calcInt::~calcInt(){}
    void calcInt::assign(double a,double b) {
        this->a=(int)a;
        this->b=(int)b;
    }
    double calcInt::add(double a,double b) {
        this->Operator=" + ";
        this->assign(a,b);
        this->result=this->a+this->b;
        return result;
    }

    double calcInt::sub(double a,double b) {
        this->Operator=" - ";
        this->assign(a,b);
        this->result=this->a-this->b;
        return result;
    }

    double calcInt::mult(double a,double b) {
        this->Operator=" * ";
        this->assign(a,b);
        this->result=this->a*this->b;
        return result;
    }

    double calcInt::div(double a,double b) {
        this->Operator=" / ";
        this->assign(a,b);
        this->result=this->a/this->b;
        return result;
    }
    void calcInt::calculate(double a, double b){
        std::cout<<"a+b = "<< add(a, b) << ", a-b = " << sub(a, b) << ", a*b = " << mult(a, b) << ", a/b = " << div(a, b)<<std::endl;
    }

    void calcInt::demo(double a,double b){
        calc c,*c_ptr;
        //c.calc();
        c_ptr=&c;
        //c_ptr->calc();

        calcInt ci,*ci_ptr;
        //ci.calcInt();
        ci_ptr=&ci;
        ci.calculate(a,b);
        //ci_ptr->calcInt();

    }

}
}
}
