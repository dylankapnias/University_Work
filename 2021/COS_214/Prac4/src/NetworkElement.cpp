#include "../inc/NetworkElement.h"

NetworkElement::NetworkElement() : engineers() {}

NetworkElement::~NetworkElement() {}

void NetworkElement::attach(Engineer* e) {
    if (e == NULL)
        throw std::logic_error("e must not be null.");

    bool found = false;
    for (auto engIt = engineers.begin(); engIt != engineers.end(); engIt++) {
        if (*engIt == e)
            found = true;
    }
    if (found)
        throw std::logic_error("e must not already be part of the collection.");
    
    engineers.push_back(e);

    if (e->getName().substr(0, 3) == "MSC")
        core.addEngineer(e);
}

void NetworkElement::detach(Engineer* e) {
    if (e == NULL)
        throw std::logic_error("e must not be null.");

    if (engineers.size() == 0)
        throw std::logic_error("The collection is already empty.");
    
    bool found = false;
    for (auto engIt = engineers.begin(); engIt != engineers.end() && !found; engIt++) {
        if (*engIt == e) {
            found = true;
            engineers.erase(engIt);
        }
    }
    
    if (!found)
        throw std::logic_error("e must be a part of the collection.");

    if (e->getName().substr(0, 3) == "MSC")
        core.removeEngineer();
}

void NetworkElement::notify() {
    if (engineers.size() != 0) {
        for (auto engIt = engineers.begin(); engIt != engineers.end(); engIt++) {
            std::cout << "Element is notifying eng -> " << (*engIt)->getName() << " of state change." << std::endl;
            (*engIt)->update();
        }
    }

    if (!operations.isEmpty()) {
        EngineerIterator* it = operations.createEngineerIterator();
        for (; it->hasNext(); it++) {
            std::cout << "Element is notifying eng -> " << it->current()->getName() << " of state change." << std::endl;
            it->current()->update();
        }
        delete it;
    }

    if (!core.isEmpty()) {
        EngineerIterator* it = core.createEngineerIterator();
        for (; it->hasNext(); it++) {
            std::cout << "Element is notifying eng -> " << it->current()->getName() << " of state change." << std::endl;
            it->current()->update();
        }
        delete it;
    }
}