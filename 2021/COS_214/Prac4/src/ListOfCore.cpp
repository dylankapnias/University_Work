#include "../inc/ListOfCore.h"

ListOfCore::ListOfCore() {}

ListOfCore::~ListOfCore() {}

EngineerIterator* ListOfCore::createEngineerIterator() const {
    return new CoreIterator(startingPoint, startingPoint);
}

void ListOfCore::addEngineer(Engineer* e) {
    if (isEmpty()) {
        e->setNext(NULL);
    } else {
        e->setNext(startingPoint);
    }
    startingPoint = e;
}

void ListOfCore::removeEngineer() {
    if (isEmpty())
        return;
    else if (startingPoint->getNext() == startingPoint) {
        startingPoint = 0;
    } else {
        EngineerIterator* it = createEngineerIterator();
        for (; it->next()->getNext() != NULL; it++);
        it->next()->setNext(NULL);
        startingPoint = startingPoint->getNext();
    }
}

bool ListOfCore::isEmpty() {
    return startingPoint == 0;
}
