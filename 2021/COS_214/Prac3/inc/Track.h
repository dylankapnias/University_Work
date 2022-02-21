#if !defined(TRACK_H)
#define TRACK_H

#include "Straight.h"
#include "Chicane.h"
#include "Turn.h"
#include <vector>

class Track : public Section
{
    private:
        std::vector<Section*> sections;
        bool crash;
    public:
        Track();
        ~Track();

        virtual void print() const override;
        virtual void add(Section*);
        virtual void remove();

        bool hasCrash();
        void setCrash(bool);
};

#endif // TRACK_H
