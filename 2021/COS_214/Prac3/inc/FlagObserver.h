#if !defined(FLAGOBSERVER_H)
#define FLAGOBSERVER_H

#include "Observer.h"
#include "Track.h"

class FlagObserver : public Observer
{
    private:
        Track* raceTrack;
        bool waving;
    public:
        FlagObserver(Track*);
        ~FlagObserver();
        
        virtual void update();
        virtual void print();
};  

#endif // FLAGOBSERVER_H
