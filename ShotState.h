#ifndef SHOTSTATE_H
#define SHOTSTATE_H

#include <string>

class Shot;

class ShotState {
    public:
        virtual std::string getName() const = 0;
        virtual bool isUrgent() const = 0;
        virtual void advance(Shot* shot) = 0;
        virtual void reject(Shot* shot) = 0;
        virtual ~ShotState() {}
};

#endif