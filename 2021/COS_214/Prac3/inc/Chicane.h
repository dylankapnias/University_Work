#if !defined(CHICANE_H)
#define CHICANE_H

#include "Section.h"

class Chicane : public Section
{
    public:
        Chicane();
        ~Chicane();
        virtual void print() const override;
};

#endif // CHICANE_H
