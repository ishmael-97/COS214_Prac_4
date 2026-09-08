#ifndef PRODUCTIONDECORATOR_H
#define PRODUCTIONDECORATOR_H

#include "ProductionUnit.h"

// Abstract Interface for additional responsibilities
class ProductionDecorator : public ProductionUnit {
    public:
        ProductionDecorator(ProductionUnit*);
        virtual std::string getName();
        virtual std::string getStatus();
        virtual bool isUrgent();
        virtual ~ProductionDecorator();
    protected:
        ProductionUnit* wrappped;

};





#endif



