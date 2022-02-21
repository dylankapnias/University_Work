#include <iostream>

#include "../inc/RemoteControlCar.h"
#include "../inc/RemoteControlPlane.h"
#include "../inc/RocketAdapter.h"
#include "../inc/Button.h"
#include "../inc/TurnOn.h"
#include "../inc/TurnOff.h"
#include "../inc/MoveFoward.h"
#include "../inc/MoveBackward.h"
#include "../inc/Fly.h"
#include "../inc/Speed.h"

void Task5() {
    std::cout << "==========Start of Task 5==========" << std::endl;

    RemoteControlCar* car = new RemoteControlCar();
    RemoteControlPlane* plane = new RemoteControlPlane();
    RemoteControlRocket* rocket = new RemoteControlRocket();

    RocketAdapter* adapter = new RocketAdapter(rocket); // Adapter for the rocket to work with the commands and buttons.

    TurnOn* carOn = new TurnOn(car);
    TurnOff* carOff = new TurnOff(car);
    MoveFoward* carFoward = new MoveFoward(car);
    MoveBackward* carBackward = new MoveBackward(car);

    TurnOn* planeOn = new TurnOn(plane);
    TurnOff* planeOff = new TurnOff(plane);
    MoveFoward* planeFoward = new MoveFoward(plane);
    MoveBackward* planeBackward = new MoveBackward(plane);

    // The adapter is used instead of the actual rocket.
    TurnOn* rocketOn = new TurnOn(adapter);
    TurnOff* rocketOff = new TurnOff(adapter);
    MoveFoward* rocketFoward = new MoveFoward(adapter);
    MoveBackward* rocketBackward = new MoveBackward(adapter);

    Button* carPowerOn = new Button(carOn);
    Button* carPowerOff = new Button(carOff);
    Button* carMoveFoward = new Button(carFoward);
    Button* carMoveBackward = new Button(carBackward);
    
    Button* planePowerOn = new Button(planeOn);
    Button* planePowerOff = new Button(planeOff);
    Button* planeMoveFoward = new Button(planeFoward);
    Button* planeMoveBackward = new Button(planeBackward);
    
    Button* rocketPowerOn = new Button(rocketOn);
    Button* rocketPowerOff = new Button(rocketOff);
    Button* rocketMoveFoward = new Button(rocketFoward);
    Button* rocketMoveBackward = new Button(rocketBackward);

    int vehicleChoice;
    int commandChoice;

    while (true) {
        std::cout << "Which RC do you want to control?" << std::endl;
        std::cout << "\t1. Car\n\t2. Plane\n\t3. Rocket\n\t4. Exit" << std::endl;
        std::cout << "Please enter the appropriate number: ";
        std::cin >> vehicleChoice;
        std::cout << std::endl;

        if (vehicleChoice == 4)
            break;

        switch (vehicleChoice)
        {
        case 1:
            std::cout << "What would you like to do with the car?" << std::endl;
            std::cout << "\t1. On\n\t2. Off\n\t3. Foward\n\t4. Backwards" << std::endl;
            std::cout << "Please enter the appropriate number: ";
            std::cin >> commandChoice;
            std::cout << std::endl;

            switch (commandChoice)
            {
                case 1:
                    carPowerOn->press();
                    std::cout << std::endl;
                    break;

                case 2:
                    carPowerOff->press();
                    std::cout << std::endl;
                    break;

                case 3:
                    carMoveFoward->press();
                    std::cout << std::endl;
                    break;

                case 4:
                    carMoveBackward->press();
                    std::cout << std::endl;
                    break;

                default:
                    break;
            }
            break;
        
        case 2:
            std::cout << "What would you like to do with the plane?" << std::endl;
            std::cout << "\t1. On\n\t2. Off\n\t3. Foward\n\t4. Backwards" << std::endl;
            std::cout << "Please enter the appropriate number: ";
            std::cin >> commandChoice;
            std::cout << std::endl;

            switch (commandChoice)
            {
                case 1:
                    planePowerOn->press();
                    std::cout << std::endl;
                    break;

                case 2:
                    planePowerOff->press();
                    std::cout << std::endl;
                    break;

                case 3:
                    planeMoveFoward->press();
                    std::cout << std::endl;
                    break;

                case 4:
                    planeMoveBackward->press();
                    std::cout << std::endl;
                    break;

                default:
                    break;
            }
            break;

        case 3:
            std::cout << "Due to the build of the rocket and adapter will be used." << std::endl;
            std::cout << "What would you like to do with the rocket?" << std::endl;
            std::cout << "\t1. Take Off\n\t2. Stop Launch\n\t3. Increase Throttle\n\t4. Decrease Throttle" << std::endl;
            std::cout << "Please enter the appropriate number: ";
            std::cin >> commandChoice;
            std::cout << std::endl;

            switch (commandChoice)
            {
                case 1:
                    rocketPowerOn->press();
                    std::cout << std::endl;
                    break;

                case 2:
                    rocketPowerOff->press();
                    std::cout << std::endl;
                    break;

                case 3:
                    rocketMoveFoward->press();
                    std::cout << std::endl;
                    break;

                case 4:
                    rocketMoveBackward->press();
                    std::cout << std::endl;
                    break;

                default:
                    break;
            }
            break;
        
        default:
            break;
        }
    }

    delete carPowerOn;
    delete carPowerOff;
    delete carMoveFoward;
    delete carMoveBackward;

    delete planePowerOn;
    delete planePowerOff;
    delete planeMoveFoward;
    delete planeMoveBackward;

    delete rocketPowerOn;
    delete rocketPowerOff;
    delete rocketMoveFoward;
    delete rocketMoveBackward;
    
    delete car;
    delete plane;
    delete rocket;
    delete adapter;

    delete carOn;
    delete carOff;
    delete carFoward;
    delete carBackward;
    
    delete planeOn;
    delete planeOff;
    delete planeFoward;
    delete planeBackward;

    delete rocketOn;
    delete rocketOff;
    delete rocketFoward;
    delete rocketBackward;
}

void Task8() {
    std::cout << "==========Start of Task 8==========" << std::endl;

    RemoteControlCar* chain = new RemoteControlCar();
    RemoteControlPlane* link1 = new RemoteControlPlane();
    chain->setNext(link1);

    TurnOn* carOn = new TurnOn(chain);
    TurnOff* carOff = new TurnOff(chain);

    TurnOn* planeOn = new TurnOn(link1);
    TurnOff* planeOff = new TurnOff(link1);

    Button* carPowerOn = new Button(carOn);
    Button* carPowerOff = new Button(carOff);

    Button* planePowerOn = new Button(planeOn);
    Button* planePowerOff = new Button(planeOff);

    carPowerOn->press();
    planePowerOn->press();

    chain->handleRequest("speed");
    chain->handleRequest("fly");
    chain->handleRequest("test");

    delete chain;
    delete link1;

    delete carPowerOn;
    delete carPowerOff;

    delete planePowerOn;
    delete planePowerOff;

    delete carOn;
    delete carOff;

    delete planeOn;
    delete planeOff;
}

int main() {
    Task5();

    Task8();

    return 0;
}