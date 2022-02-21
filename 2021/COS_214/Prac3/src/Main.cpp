#include "../inc/Track.h"
#include "../inc/Barrier.h"
#include "../inc/GravelTrap.h"
#include "../inc/Pitstop.h"
#include "../inc/Startline.h"
#include "../inc/FlagObserver.h"

const unsigned int NUM_SECTIONS = 10;

int main(int argc, char **argv) {    
    Track* track = new Track();

    Decorator* a = new Startline();    
    a->add(new Straight);
    track->add(a);

    a = new Barrier();
    a->add(new Turn(0));
    track->add(a);

    track->add(new Straight());
    track->add(new Straight());

    a = new GravelTrap();
    a->add(new Turn(0));
    track->add(a);

    a = new Barrier();
    a->add(new Chicane());
    track->add(a);

    a = new Barrier();
    a->add(new Turn(0));
    track->add(a);

    a = new Pitstop();
    a->add(new Straight());
    track->add(a);

    track->add(new Straight());

    a = new GravelTrap();
    a->add(new Turn(0));
    track->add(a);

    track->print();

    FlagObserver* obs = new FlagObserver(track);
    track->attach(obs);

    track->setCrash(true);
    track->notify();
    obs->print();

    track->setCrash(false);
    track->notify();
    obs->print();

    track->detach(obs);

    for (int i = 0; i < NUM_SECTIONS; i++) {
        track->remove();
    }

    delete track;
    delete obs;

    a = nullptr;
    delete a;
    
    return 0;
}