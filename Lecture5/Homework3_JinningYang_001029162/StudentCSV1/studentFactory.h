#ifndef STUDENTFACTORY_H_INCLUDED
#define STUDENTFACTORY_H_INCLUDED
#include "abstractFactory.h"
namespace edu{
namespace neu{
namespace csye6205{
class studentFactory:public abstractFactory{
public:
    virtual school* getObject();
    virtual void freeObject(school *s);
};
}
}
}

#endif // STUDENTFACTORY_H_INCLUDED
