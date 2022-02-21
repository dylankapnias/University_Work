/****************************************************************************************************
 *  @file inc/Speed.h
 *  @brief The header file for the Speed class.
 ***************************************************************************************************/

#ifndef SPEED_H
#define SPEED_H

#include "Command.h"
/****************************************************************************************************
 *  @class Speed
 *  @brief The concrete command participant of the chain of resposibilty design pattern.
 ***************************************************************************************************/
class Speed : public Command
{
    public:
        /**
         *  @fn Fly(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   This will be passed to the parent constructor.
         */
        Speed(RemoteControlVehicle* v);

        /**
         *  @fn ~Speed()
         *  @brief The destructor for the class.
         */
        ~Speed();

        /**
         *  @fn virtual void execute() override
         *  @brief The overriding of the virtual function execute.
         */
        virtual void execute() override;

        /**
         *  @fn virtual void undo() override
         *  @brief The overriding of the virtual function undo.
         */
        virtual void undo() override;
};

#endif  //SPEED_H
