/****************************************************************************************************
 *  @file inc/RemoteControlRocket.h
 *  @brief The header file for the RemoteControlRocket class.
 ***************************************************************************************************/

#ifndef REMOTECONTROLROCKET_H
#define REMOTECONTROLROCKET_H

#include <iostream>
/****************************************************************************************************
 *  @class RemoteControlRocket
 *  @brief The adaptee of the adapter class.
 ***************************************************************************************************/
class RemoteControlRocket
{
    public:
        /**
         *  @fn RemoteControlRocket()
         *  @brief The constructor for the class.
         */
        RemoteControlRocket();

        /**
         *  @fn ~RemoteControlRocket()
         *  @brief The destructor for the class.
         */
        ~RemoteControlRocket();

        /**
         *  @fn void takeOff()
         *  @brief The take off method.
         */
        void takeOff();
        /**
         *  @fn stopLaunch()
         *  @brief The stopLaunch method.
         */
        void stopLaunch();
        /**
         *  @fn increaseThrottle()
         *  @brief The increase throttle method.
         */
        void increaseThrottle();
        /**
         *  @fn void decreaseThrottle()
         *  @brief The decrease throttle method.
         */
        void decreaseThrottle();
};

#endif  //REMOTECONTROLROCKET_H
