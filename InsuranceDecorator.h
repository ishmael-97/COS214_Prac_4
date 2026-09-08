#ifndef INSURANCEDECORATOR_H
#define INSURANCEDECORATOR_H

#include "ProductionDecorator.h"
class InsuranceDecorator : public ProductionDecorator {
    public:
        InsuranceDecorator(ProductionUnit* unit, double coverageAmount);
          std::string getStatus() const override;
          void execute() override;
        ~InsuranceDecorator() override {}

    private:
        double coverageAmount;
};

#endif