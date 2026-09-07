#ifndef SHOT_H
#define SHOT_H

#include "ProductionUnit.h"

class ShotState;

class Shot : public ProductionUnit {
    public:
        Shot(const std::string& name);
        std::string getName() const override;
        std::string getStatus() const override;
        bool isUrgent() const override;
        virtual ~Shot();
        
    private:
        std::string name;
        ShotState* state;
};

#endif