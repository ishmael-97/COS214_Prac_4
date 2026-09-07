#ifndef APPROVED_H
#define APPROVED_H

#include "ShotState.h"

// filmed and signed off
class Approved : public ShotState {
    public:
      std::string getName() const override;
        bool isUrgent() const override;
        void advance(Shot* shot) override;
        void reject(Shot* shot) override;
};
#endif