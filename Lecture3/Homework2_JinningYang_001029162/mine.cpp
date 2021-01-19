#include "mine.h"

namespace edu{
namespace neu{
namespace csye6205{
    mine::mine(){};
    mine::mine(string name,double size,string material){
        this->name=name;
        this->size=size;
        this->material=material;
    }
    mine::~mine(){};

    ostream &operator<<( ostream &output, const mine &M )
{
     output << M.name << " size: " << M.size<<" meterial: "<<M.material;
     return output;
}

    void mine::explode(){
        cout << "\n\t Mine.demo()..." << endl;
        mine mi("LandTiger",23.78,"Copper");
        cout << mi<< endl;
        cout << "\n\t Mine.demo()...done!!!" << endl;
    }

}
}
}
