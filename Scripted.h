#ifndef SCRIPTED_H
#define SCRIPTED_H

#include "ShotState.h"

class Scripted : public ShotState{
    public:
      std::string getName() const override;
        bool isUrgent() const override;
      void advance(Shot* shot) override;
        void reject(Shot* shot) override;
};

#endif