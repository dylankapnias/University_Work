#if !defined(OBSERVER_H)
#define OBSERVER_H

class Observer
{
    public:
        Observer();
        virtual ~Observer();

        virtual void update() = 0;
        virtual void print() = 0;
};

#endif // OBSERVER_H
