#include "../inc/VectorOfOperations.h"

VectorOfOperations::VectorOfOperations() {}

VectorOfOperations::~VectorOfOperations() {}

EngineerIterator* VectorOfOperations::createEngineerIterator() const {
    return new OperationsIterator(list);
}

void VectorOfOperations::addEngineer(Engineer* e) {
    list.push_back(e);
}

void VectorOfOperations::removeEngineer() {
    if (!isEmpty())
        list.pop_back();
}

bool VectorOfOperations::isEmpty() {
    if (list.size() == 0)
        return true;
    else
        return false;
}
