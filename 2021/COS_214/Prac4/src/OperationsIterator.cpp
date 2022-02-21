#include "../inc/OperationsIterator.h"

OperationsIterator::OperationsIterator() : currentPos(0) {}

OperationsIterator::OperationsIterator(std::vector<Engineer*> v) : itList(v), currentPos(0) {}

OperationsIterator::~OperationsIterator() {}

Engineer* OperationsIterator::first() {
    return itList[0];
}

Engineer* OperationsIterator::next() {
    if (!hasNext())
        return NULL;
    else
        return itList[currentPos + 1];
}

Engineer* OperationsIterator::current() {
    return itList[currentPos];
}

bool OperationsIterator::hasNext() {
    return !(currentPos + 1 >= itList.size());
}

OperationsIterator OperationsIterator::operator++() {
    if (itList.size() != 0)
        currentPos++;
    return *this;
}