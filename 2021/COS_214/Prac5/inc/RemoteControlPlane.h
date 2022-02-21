/****************************************************************************************************
 *  @file inc/RemoteControlPlane.h
 *  @brief The header file for the RemoteControlPlane class.
 ***************************************************************************************************/

#ifndef REMOTECONTROLPLANE_H
#define REMOTECONTROLPLANE_H

#include "RemoteControlVehicle.h"
#include "Fly.h"
/****************************************************************************************************
 *  @class RemoteControlPlane
 *  @brief The concrete receiver for the command design pattern.
 ***************************************************************************************************/
class RemoteControlPlane : public RemoteControlVehicle
{
    private:
        RemoteControlVehicle* next;
    public:
        /**
         *  @fn RemoteControlPlane()
         *  @brief The constructor for the class.
         */
        RemoteControlPlane();

        /**
         *  @fn ~RemoteControlPlane()
         *  @brief The destructor for the class.
         */
        ~RemoteControlPlane();

        virtual void changeFlight();

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

#endif  //REMOTECONTROLPLANE_H
