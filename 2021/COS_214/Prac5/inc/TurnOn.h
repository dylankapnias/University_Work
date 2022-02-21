/****************************************************************************************************
 *  @file inc/TurnOn.h
 *  @brief The header file for the TurnOn class.
 ***************************************************************************************************/

#ifndef TURNON_H
#define TURNON_H

#include "Command.h"
/****************************************************************************************************
 *  @class TurnOn
 *  @brief The concrete command participant of the command design pattern.
 ***************************************************************************************************/
class TurnOn : public Command
{
    public:
        /**
         *  @fn TurnOn(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   This will be passed to the parent constructor.
         */
        TurnOn(RemoteControlVehicle* v);

        /**
         *  @fn ~TurnOn()
         *  @brief The destructor for the class.
         */
        ~TurnOn();

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

#endif  //TURNON_H
