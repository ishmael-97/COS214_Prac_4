#include "PriorityDecorator.h"
#include <iostream>

PriorityDecorator::PriorityDecorator(ProductionUnit* unit) : ProductionDecorator(unit) {}

std::string PriorityDecorator::getStatus() const {
    return wrappped->getStatus();
}

bool PriorityDecorator::isUrgent() const {
    return true;
}

void PriorityDecorator::execute() {
    std::cout << "[Priority] Escalating \"" << wrappped->getName() << "\" ahead of the queue" << std::endl;
    wrappped->execute();
}