#include <iostream>
#include "Hero.hpp"
#include "Axe.hpp"
#include "Invoker.hpp"

int main(){

    // hero is born with 10 1000
    // invoker is born with 10 1000
    Invoker *carl = new Invoker(10, 1000);
    // invoker is using skill 10 1000
    // hero is copied with 10 1000
    carl->useSkill();
    // invoker copy is born with 10 1000
    Invoker *carl2 = new Invoker(*carl);
    // hero is healing 1 10 1000
    carl2->Hero :: heal(1);
    // hero is born with 50 200
    // invoker is born with 50 200
    Invoker *carl3 = new Invoker();
    // invoker is moving to 10,25 50 200
    carl3->move(10, 25);
    // invoker copied 10 1000
    *carl3 = *carl2;
    // hero is born with 200 10
    // axe is born with 200 10
    Axe *ogre = new Axe(200, 10);
    // axe is moving to 2,20 200 10
    ogre->move(2,20);
    // axe is healing 10 200 10
    ogre->heal(10);
    // hero is copied with 200 10
    // axe copy is born with 200 10
    Axe *ogre2 = new Axe(*ogre);
    // hero is born with 400 20
    // axe is born with 400 20
    // axe here with more power 400 20
    // hero is copied with 400 20
    // axe copy is born with 400 20
    Axe *ogre3 = new Axe(*ogre + *ogre);
    // axe is using skill 200 10
    ogre->useSkill();
    // axe is using skill 400 20
    ogre3->useSkill();
    // no axe 200 10
    // hero has fallen 200 10
    delete ogre;
    // no axe 400 20
    // hero has fallen 400 20
    delete ogre3;
    // no invoker 10 1000
    // hero has fallen 10 1000
    delete carl2;
}