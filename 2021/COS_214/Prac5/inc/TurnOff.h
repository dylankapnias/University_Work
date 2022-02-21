/****************************************************************************************************
 *  @file inc/TurnOff.h
 *  @brief The header file for the TurnOff class.
 ***************************************************************************************************/

#ifndef TURNOFF_H
#define TURNOFF_H

#include "Command.h"
/****************************************************************************************************
 *  @class TurnOff
 *  @brief The concrete command participant of the command design pattern.
 ***************************************************************************************************/
class TurnOff : public Command
{
    public:
        /**
         *  @fn TurnOff(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   This will be passed to the parent constructor.
         */
        TurnOff(RemoteControlVehicle* v);

        /**
         *  @fn ~TurnOff()
         *  @brief The destructor for the class.
         */
        ~TurnOff();

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

#endif  //TURNOFF_H
