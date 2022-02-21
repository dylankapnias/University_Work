/****************************************************************************************************
 *  @file inc/RemoteControlVehicle.h
 *  @brief The header file for the RemoteControlVehicle class.
 ***************************************************************************************************/

#ifndef REMOTECONTROLVEHICLE_H
#define REMOTECONTROLVEHICLE_H

#include <iostream>
/****************************************************************************************************
 *  @class RemoteControlVehicle
 *  @brief The receiver for the command design pattern, and handler for the chain of resposibility.
 ***************************************************************************************************/
class RemoteControlVehicle
{
    private:
        bool onState; /**< A boolean value representing the on/off state of the vehicle. */
    public:
        /**
         *  @fn RemoteControlVehicle()
         *  @brief A constructor that initialises the on member variable to false.
         */
        RemoteControlVehicle();

        /**
         *  @fn virtual ~RemoteControlVehicle()
         *  @brief The virtual destructor for the class.
         */
        virtual ~RemoteControlVehicle();

        /**
         *  @fn bool getState()
         *  @brief The getter for the state of the vehicle.
         */
        bool getState();

        /**
         *  @fn void setState(bool b)()
         *  @brief The setter for the state of the vehicle.
         *  
         *  @param[in]  b   The private variable onState will be set to this.
         */
        void setState(bool b);

        /**
         *  @fn virtual void on() = 0;
         *  @brief A pure virtual on method which takes no parameters.
         */
        virtual void on() = 0;

        /**
         *  @fn virtual void off() = 0;
         *  @brief A pure virtual off method which takes no parameters.
         */
        virtual void off() = 0;

        /**
         *  @fn virtual void foward() = 0;
         *  @brief A pure virtual forward method which takes no parameters.
         */
        virtual void foward() = 0;

        /**
         *  @fn virtual void backward() = 0;
         *  @brief A pure virtual backward method which takes no parameters.
         */
        virtual void backward() = 0;

        /**
         *  @fn virtual void backward();
         *  @brief A virtual method which takes no parameters.
         */
        virtual void changeSpeed();

        /**
         *  @fn virtual void backward();
         *  @brief A virtual method which takes no parameters.
         */
        virtual void changeFlight();

        /**
         *  @fn virtual void handleRequest(std::string s)
         *  @brief The virtual handleRequest for the chain of responsibility.
         *  
         *  @param[in]  s   The type of command to attempt to execute.
         */
        virtual void handleRequest(std::string s);

};

#endif  //REMOTECONTROLVEHICLE_H
