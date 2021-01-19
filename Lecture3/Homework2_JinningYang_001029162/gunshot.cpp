#include"gunshot.h"

namespace edu{
namespace neu{
namespace csye6205{
    gunshot::gunshot(){};
    gunshot::gunshot(string name,double size,double caliber){
        this->name=name;
        this->size=size;
        this->caliber=caliber;
    }
    gunshot::~gunshot(){};

    void gunshot::explode(){
        cout << "\n\t Gunshot.demo()..." << endl;
        gunshot gun("ShuttleBullets",12.34,35.55);
        cout << gun<< endl;
        cout << "\n\t Gunshot.demo()...done!!!" << endl;
    }

    ostream &operator<<( ostream &output, const gunshot &S )
{
     output << S.name << " size: " << S.size<<" caliber: "<<S.caliber;
     return output;
}
}
}
}
