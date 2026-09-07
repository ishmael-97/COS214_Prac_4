#ifndef PRODUCTIONGROUP_H
#define PRODUCTIONGROUP_H

// necessary Libraries
#include <string>
#include <vector>

// common abstraction header 
#include "ProductionUnit.h"

// dependency header
#include "ProductionIterator.h"

// Abstract Class
class ProductionGroup : public ProductionUnit {
    public:
        ProductionGroup(const std::string& name);
        void add(ProductionUnit* unit);
        void remove(ProductionUnit* unit);

        std::string getName() const override;
        std::string getStatus() const override;
        bool isUrgent() const override;
        void execute() override;

        ProductionIterator* createFullIterator();
        ProductionIterator* createUrgentIterator();

        virtual ~ProductionGroup();

    protected:
        std::string name;
        std::vector<ProductionUnit*> children;
};

// concrete Composite Abstraction_
class Act : public ProductionGroup {
    public:
        Act(const std::string& name);
        ~Act() override {}
};

class Sequence : public ProductionGroup {
    public:
        Sequence(const std::string& name);
        ~Sequence() override {}
};

class Scene : public ProductionGroup {
    public:
        Scene(const std::string& name);
        ~Scene() override {}
};

#endif



