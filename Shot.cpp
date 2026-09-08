#include "Shot.h"
#include "Scripted.h"
#include <iostream>

// Every shot begins life freshly scripted
Shot::Shot(const std::string& name) : name(name), state(new Scripted()) {}

std::string Shot::getName() const { return name; }

std::string Shot::getStatus() const {
    return name + " [" + state->getName() + "]";
}

bool Shot::isUrgent() const {
    return state->isUrgent();
}

void Shot::execute() {
    std::cout << "Filming shot \"" << name << "\" (" << state->getName() << ")" << std::endl;
    std::cout << "Logging shot \"" << name << "\" in the production diary" << std::endl;
}

void Shot::advance() {
    state->advance(this);
}

void Shot::reject() {
    state->reject(this);
}

void Shot::setState(ShotState* newState) {
    delete state;
    state = newState;
}

// Owns its state, so it must delete it
Shot::~Shot() {
    delete state;
}
