#include "Approved.h"
#include "Shooting.h"
#include "Shot.h"
#include <iostream>

std::string Approved::getName() const { return "Approved"; }
bool Approved::isUrgent() const { return false; }

void Approved::advance(Shot* shot) {
    // There is no stage beyond Approved state
    std::cout << "\"" << shot->getName() << "\" is already approved; there is no further stage to advance to." << std::endl;
}

void Approved::reject(Shot* shot) {
    // A late note can still reopen an approved shot for a reshoot
    std::cout << "\"" << shot->getName() << "\" is being reopened for a reshoot after approval." << std::endl;
    shot->setState(new Shooting());
}