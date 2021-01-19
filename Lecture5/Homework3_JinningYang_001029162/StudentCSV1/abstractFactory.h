#ifndef ABSTRACTFACTORY_H_INCLUDED
#define ABSTRACTFACTORY_H_INCLUDED
#include "school.h"
namespace edu{
namespace neu{
namespace csye6205{
class abstractFactory{
public:
     abstractFactory();
     virtual ~abstractFactory();
     virtual school *getObject()=0;
     virtual void freeObject(school *s)=0;

};
}
}
}

#endif // ABSTRACTFACTORY_H_INCLUDED
