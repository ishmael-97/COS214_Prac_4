#include "InsuranceDecorator.h"
#include <iostream>

InsuranceDecorator::InsuranceDecorator(ProductionUnit* unit, double coverageAmount): ProductionDecorator(unit), coverageAmount(coverageAmount) {}

std::string InsuranceDecorator::getStatus() const {
return wrappped->getStatus() + " [Insured: R" + std::to_string(coverageAmount) + "]";
}

void InsuranceDecorator::execute() {
    std::cout << "[Insurance] Verifying R" << coverageAmount  << " coverage for \"" << wrappped->getName() << "\"" << std::endl;
    wrappped->execute();
}