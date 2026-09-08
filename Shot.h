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
        void execute() override;
         // Lifecycle transitions, delegated to the current ShotState
        void advance();
        void reject();
        //Called by ShotState subclasses to change this shot's current state.
        // Shot owns its state and is responsible for deleting the old one.
        void setState(ShotState* newState);
        
        virtual ~Shot();
        
    private:
        std::string name;
        ShotState* state;
};
#endif
