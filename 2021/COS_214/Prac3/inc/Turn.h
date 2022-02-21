#if !defined(TURN_H)
#define TURN_H

#include "Section.h"

class Turn : public Section
{
    private:
        int deg;
    
    public:
        Turn(int);
        ~Turn();

        virtual void print() const override;
};

#endif // TURN_H
