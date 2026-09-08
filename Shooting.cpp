#include "Shooting.h"
#include "Scripted.h"
#include "Approved.h"
#include "Shot.h"
#include <iostream>

std::string Shooting::getName() const { return "Shooting"; }
bool Shooting::isUrgent() const { return true; } 

void Shooting::advance(Shot* shot) {
    // Shooting -> Approved: filming wraps and is signed off
    shot->setState(new Approved());
}

void Shooting::reject(Shot* shot) {
    // A reshoot sends the shot back to be re-planned
    std::cout << "\"" << shot->getName() << "\" needs a reshoot; sending back to Scripted." << std::endl;
    shot->setState(new Scripted());
}