#if !defined(STARTLINE_H)
#define STARTLINE_H

#include "Decorator.h"

class Startline : public Decorator
{
    public:
        Startline();
        ~Startline();

        virtual void print() const;
};

#endif // STARTLINE_H
