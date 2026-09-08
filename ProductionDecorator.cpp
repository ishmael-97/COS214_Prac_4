#include "ProductionDecorator.h"


ProductionDecorator::ProductionDecorator(ProductionUnit* unit) : wrappped(unit) {}

std::string ProductionDecorator::getName() const {
    return wrappped->getName();
}

std::string ProductionDecorator::getStatus() const {
    return wrappped->getStatus();
}

bool ProductionDecorator::isUrgent() const {
    return wrappped->isUrgent();
}

ProductionDecorator::~ProductionDecorator() {
    delete wrappped;
}