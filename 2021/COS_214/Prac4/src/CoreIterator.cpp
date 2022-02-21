#include "../inc/CoreIterator.h"

CoreIterator::CoreIterator() {}

CoreIterator::CoreIterator(Engineer* h, Engineer* c) : firstEngineer(h), currentEngineer(c) {}

CoreIterator::~CoreIterator() {}

Engineer* CoreIterator::first() {
    return firstEngineer;
}

Engineer* CoreIterator::next() {
    return currentEngineer->getNext();
}

Engineer* CoreIterator::current() {
    return currentEngineer;
}

bool CoreIterator::hasNext() {
    if (currentEngineer->getNext() == NULL)
        return false;
    else
        return true;
}

CoreIterator CoreIterator::operator++() {
    if (this != NULL)
        this->currentEngineer = this->currentEngineer->getNext();
    return *this;
}
