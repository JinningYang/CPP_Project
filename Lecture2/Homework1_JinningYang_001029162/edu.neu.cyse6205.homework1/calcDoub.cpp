#include "calcDoub.h"

namespace edu{
namespace neu{
namespace csye6205{
    calcDoub::calcDoub(){}
    calcDoub::~calcDoub(){}
    void calcDoub::assign(double a,double b) {
        this->a=a;
        this->b=b;
    }
    double calcDoub::add(double a,double b) {
        this->Operator=" + ";
        this->assign(a,b);
        this->result=this->a+this->b;
        return result;
    }

    double calcDoub::sub(double a,double b) {
        this->Operator=" - ";
        this->assign(a,b);
        this->result=this->a-this->b;
        return result;
    }

    double calcDoub::mult(double a,double b) {
        this->Operator=" * ";
        this->assign(a,b);
        this->result=this->a*this->b;
        return result;
    }

    double calcDoub::div(double a,double b) {
        this->Operator=" / ";
        this->assign(a,b);
        this->result=this->a/this->b;
        return result;
    }

    void calcDoub::calculate(double a, double b){
        std::cout<<"a+b = "<< add(a, b) << ", a-b = " << sub(a, b) << ", a*b = " << mult(a, b) << ", a/b = " << div(a, b)<<std::endl;
    }

    void calcDoub::demo(double a,double b){
        calcDoub cb;
        cb.calculate(a,b);
        //cb.calcDoub();
        //cb_ptr=&cb;
        //cb_ptr->calcDoub();

    }
}
}
}
