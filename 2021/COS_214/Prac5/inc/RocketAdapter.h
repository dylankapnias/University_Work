/****************************************************************************************************
 *  @file inc/RocketAdapter.h
 *  @brief The header file for the RocketAdapter class.
 ***************************************************************************************************/

#ifndef ROCKETADAPTER_H
#define ROCKETADAPTER_H

#include "RemoteControlRocket.h"
#include "RemoteControlVehicle.h"
/****************************************************************************************************
 *  @class RocketAdapter
 *  @brief The adapter participant of the Adapter design pattern.
 ***************************************************************************************************/
class RocketAdapter : public RemoteControlVehicle
{
    private:
        RemoteControlRocket* adaptee;
    public:
        /**
         *  @fn RocketAdapter(RemoteControlRocket* r)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  r   The private variable adaptee will be set to this.
         */
        RocketAdapter(RemoteControlRocket* r);

        /**
         *  @fn ~RocketAdapter()
         *  @brief The destructor for the class.
         */
        ~RocketAdapter();

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

};

#endif  //ROCKETADAPTER_H
