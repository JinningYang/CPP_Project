#include "explosionModel.h"
#include "grenade.h"
#include "mine.h"
#include "gunshot.h"
#include "vector"
namespace edu{
namespace neu{
namespace csye6205{
    explosionModel::explosionModel(){
    }
    explosionModel::~explosionModel(){
        for (auto &e : explosions) {
            delete e;
        }
    }
    void explosionModel::load(){
        this->explosions.emplace_back(new gunshot());
        this->explosions.emplace_back(new mine());
        this->explosions.emplace_back(new grenade());
    }

    void explosionModel::add(explosion *e){
        this->explosions.emplace_back(e);
    }
    void explosionModel::explodeAll(){
        for(explosion *exp : explosions){
            exp->explode();
        }
    }

    void explosionModel::demo(){
        explosionModel obj;
        obj.load();
        obj.explodeAll();

    }

    //void load(){
        //this->explosions.emplace_back(new GunShot());

    //}
}
}
}
