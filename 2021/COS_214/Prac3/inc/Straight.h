#if !defined(STRAIGHT_H)
#define STRAIGHT_H

#include "Section.h"

class Straight : public Section 
{
    public:
        Straight();
        ~Straight();
        virtual void print() const override;
};

#endif // STRAIGHT_H
