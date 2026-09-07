#ifndef PRODUCTIONUNIT_H
#define PRODUCTIONUNIT_H

// necessary libraries
#include <string>

//Central Abstraction (WorkItem => ProductionUnit)
class ProductionUnit {
    public:
        virtual std::string getName() const  = 0;
        virtual std::string getStatus() const = 0;
        virtual bool isUrgent() const = 0;
        // virtual void execute() = 0; // This method is necessary for Decorator (distinguishes different behaviours of Decorators)
        virtual ~ProductionUnit() {} 

};




#endif



