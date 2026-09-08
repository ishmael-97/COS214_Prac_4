#include "Scripted.h"
#include "Shooting.h"
#include "Shot.h"
#include <iostream>

std::string Scripted::getName() const { return "Scripted"; }
bool Scripted::isUrgent() const { return false; }

void Scripted::advance(Shot* shot) {
   //filming begins
    shot->setState(new Shooting());
}

void Scripted::reject(Shot* shot) {
    
    std::cout << "\"" << shot->getName() << "\" is only scripted; there is nothing to reject yet." << std::endl;
}