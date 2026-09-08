#ifndef SHOOTING_H
#define SHOOTING_H

#include "ShotState.h"

class Shooting : public ShotState {
    public:
        std::string getName() const override;
        bool isUrgent() const override;
        void advance(Shot* shot) override;
  void reject(Shot* shot) override;
};

#endif