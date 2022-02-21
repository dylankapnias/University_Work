#if !defined(DECORATOR_H)
#define DECORATOR_H

#include "Track.h"

class Decorator : public Section
{
    private:
        Section* section;
    public:
        Decorator();
        ~Decorator();

        virtual void print() const override;
        void add(Section*);
        void remove();
};

#endif // DECORATOR_H
