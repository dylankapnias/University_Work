#include <iostream>

#include "../inc/BTS.h"
#include "../inc/MSC.h"
#include "../inc/BSC.h"
#include "../inc/RadioEngineer.h"
#include "../inc/PowerEngineer.h"
#include "../inc/TransmissionEngineer.h"
#include "../inc/CSCoreEngineer.h"
#include "../inc/FaultsNMS.h"

void Task2_2() {
    std::cout << "============ Task2_2 ============" << std::endl;

    BTS* el = new BTS("BTS01");
    RadioEngineer* re = new RadioEngineer();
    PowerEngineer* pe = new PowerEngineer();
    TransmissionEngineer* te = new TransmissionEngineer();

    el->attach(re);
    re->obsReg(el);
    el->attach(pe);
    pe->obsReg(el);
    el->attach(te);
    te->obsReg(el);

    el->setAlarm("critical");
    el->notify();

    el->setAlarm("clear");
    el->notify();

    el->detach(re);
    el->detach(pe);
    el->detach(te);

    delete el;
    delete re;
    delete pe;
    delete te;

    std::cout << std::endl;
}

void Task3_3() {
    std::cout << "============ Task3_3 ============" << std::endl;

    MSC* el = new MSC("MSC01");
    CSCoreEngineer* ce = new CSCoreEngineer();

    el->attach(ce);
    ce->obsReg(el);

    el->setAlarm("critical");
    el->notify();

    el->setAlarm("clear");
    el->notify();

    el->detach(ce);

    delete el;
    delete ce;

    std::cout << std::endl;
}

void Task4_2() {
    std::cout << "============ Task4_2 ============" << std::endl;

    BSC* el = new BSC("BSC01");
    RadioEngineer* re = new RadioEngineer();
    FaultsNMS* nms = new FaultsNMS();

    el->attach(re);
    re->obsReg(el);
    nms->createEngineer(re);

    el->setAlarm("critical");
    el->notify();
    re->setStatus("busy");

    delete el;
    delete re;
    delete nms;
}

// int main() {
//     Task2_2();

//     Task3_3();

//     Task4_2();

//     return 0;
// }