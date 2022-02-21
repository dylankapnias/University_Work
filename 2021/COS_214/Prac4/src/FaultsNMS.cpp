#include "../inc/FaultsNMS.h"

FaultsNMS::FaultsNMS() {}

FaultsNMS::~FaultsNMS() {}

void FaultsNMS::notify(Engineer* e) {
    std::cout << e->getName() << " changed status to " << e->getStatus() << " notifying the others!" << std::endl;
    for (auto it = engineers.begin(); it != engineers.end(); it++)
        (*it)->update();
}

void FaultsNMS::print() {
    std::cout << "Hello" << std::endl;
}

void FaultsNMS::createEngineer(Engineer* e) {
    engineers.push_back(e);
}

