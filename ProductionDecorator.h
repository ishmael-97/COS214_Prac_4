#ifndef PRODUCTIONDECORATOR_H
#define PRODUCTIONDECORATOR_H
#include "ProductionUnit.h"
// Abstract Interface for additional responsibilities
class ProductionDecorator : public ProductionUnit {
    public:
        ProductionDecorator(ProductionUnit*);
        virtual std::string getName() const override;
        virtual std::string getStatus() const override;
        virtual bool isUrgent() const override;
        virtual ~ProductionDecorator();
    protected:
        ProductionUnit* wrappped;
};
#endif
