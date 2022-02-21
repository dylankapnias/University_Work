/****************************************************************************************************
 *  @file inc/RemoteControlCar.h
 *  @brief The header file for the RemoteControlCar class.
 ***************************************************************************************************/

#ifndef REMOTECONTROLCAR_H
#define REMOTECONTROLCAR_H

#include "RemoteControlVehicle.h"
#include "Speed.h"
/****************************************************************************************************
 *  @class RemoteControlCar
 *  @brief The concrete receiver for the command design pattern.
 ***************************************************************************************************/
class RemoteControlCar : public RemoteControlVehicle
{
    private:
        RemoteControlVehicle* next;
    public:
        /**
         *  @fn RemoteControlCar()
         *  @brief The constructor for the class.
         */
        RemoteControlCar();

        /**
         *  @fn ~RemoteControlCar()
         *  @brief The destructor for the class.
         */
        ~RemoteControlCar();

        /**
         *  @fn void setNext(RemoteControlVehicle* v)
         *  @brief Set the Next object
         * 
         *  @param[in]  v   The private variable next will be set to this. 
         */
        void setNext(RemoteControlVehicle* v);

        virtual void changeSpeed();

        /**
         *  @fn virtual void on()
         *  @brief A pure virtual on method which takes no parameters.
         */
        virtual void on();

        /**
         *  @fn virtual void off()
         *  @brief A pure virtual off method which takes no parameters.
         */
        virtual void off();

        /**
         *  @fn virtual void foward()
         *  @brief A pure virtual forward method which takes no parameters.
         */
        virtual void foward();

        /**
         *  @fn virtual void backward()
         *  @brief A pure virtual backward method which takes no parameters.
         */
        virtual void backward();

        /**
         *  @fn virtual void handleRequest(std::string s)
         *  @brief The virtual handleRequest for the chain of responsibility.
         *  
         *  @param[in]  s   The type of command to attempt to execute.
         */
        virtual void handleRequest(std::string s);
};

#endif  //REMOTECONTROLCAR_H
