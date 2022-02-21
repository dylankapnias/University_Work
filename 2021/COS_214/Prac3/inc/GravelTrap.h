#if !defined(GRAVELTRAP_H)
#define GRAVELTRAP_H

#include "Decorator.h"

class GravelTrap : public Decorator
{
    public:
        GravelTrap();
        ~GravelTrap();

        virtual void print() const;
};

#endif // GRAVELTRAP_H