/****************************************************************************************************
 *  @file inc/MoveFoward.h
 *  @brief The header file for the MoveFoward class.
 ***************************************************************************************************/

#ifndef MOVEFOWARD_H
#define MOVEFOWARD_H

#include "Command.h"
/****************************************************************************************************
 *  @class MoveFoward
 *  @brief The concrete command participant of the command design pattern.
 ***************************************************************************************************/
class MoveFoward : public Command
{
    public:
        /**
         *  @fn MoveFoward(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   This will be passed to the parent constructor.
         */
        MoveFoward(RemoteControlVehicle* v);

        /**
         *  @fn ~MoveFoward()
         *  @brief The destructor for the class.
         */
        ~MoveFoward();

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

#endif  //MOVEFOWARD_H
