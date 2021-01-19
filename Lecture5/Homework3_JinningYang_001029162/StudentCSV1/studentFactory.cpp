#include "studentFactory.h"
#include "school.h"
namespace edu{
namespace neu{
namespace csye6205{
school *studentFactory::getObject(){
    return new school();
}
void studentFactory::freeObject(school *s){
    delete s;
}
}
}
}
