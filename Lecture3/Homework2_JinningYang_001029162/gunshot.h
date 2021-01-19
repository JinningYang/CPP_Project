#ifndef GUNSHOT_H_INCLUDED
#define GUNSHOT_H_INCLUDED

#include"explosion.h"
#include<string>
using namespace std;

namespace edu{
namespace neu{
namespace csye6205{
class gunshot:public explosion{
private:
    double caliber;
public:
    gunshot();
    gunshot(string name,double size,double caliber);
    virtual~gunshot();
    void explode();
    friend ostream &operator<<( ostream &output,
                                       const gunshot &G );
};
}
}
}


#endif // GUNSHOT_H_INCLUDED
