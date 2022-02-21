#if !defined(BARRIER_H)
#define BARRIER_H

#include "Decorator.h"

class Barrier : public Decorator
{
    public:
        Barrier();
        ~Barrier();

        virtual void print() const;
};

#endif // BARRIER_H
