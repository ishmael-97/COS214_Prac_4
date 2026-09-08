#ifndef PRIORITYDECORATOR_H
#define PRIORITYDECORATOR_H

#include "ProductionDecorator.h"

class PriorityDecorator : public ProductionDecorator {
    public:
         PriorityDecorator(ProductionUnit* unit);
        std::string getStatus() const override;
        bool isUrgent() const override;
        void execute() override;
        ~PriorityDecorator() override {}
};

#endif