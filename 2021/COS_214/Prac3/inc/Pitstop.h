#if !defined(PITSTOP_H)
#define PITSTOP_H

#include "Decorator.h"

class Pitstop : public Decorator
{
    public:
        Pitstop();
        ~Pitstop();

        virtual void print() const;
};

#endif // PITSTOP_H
