#if !defined(SECTION_H)
#define SECTION_H

#include <iostream>
#include <vector>
#include "string.h"
#include "Observer.h"

class Section
{
    private:
        std::vector<Observer*> observerList;
    public:
        Section();
        virtual ~Section();
        
        virtual void print() const = 0;
        virtual void add(Section*);
        virtual void remove();

        void attach(Observer*);
        void detach(Observer*);
        void notify();
};

#endif // SECTION_H
