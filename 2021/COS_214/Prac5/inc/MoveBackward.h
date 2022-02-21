/****************************************************************************************************
 *  @file inc/MoveBackward.h
 *  @brief The header file for the MoveBackward class.
 ***************************************************************************************************/

#ifndef MOVEBACKWARD_H
#define MOVEBACKWARD_H

#include "Command.h"
/****************************************************************************************************
 *  @class MoveBackward
 *  @brief The concrete command participant of the command design pattern.
 ***************************************************************************************************/
class MoveBackward : public Command
{
    public:
        /**
         *  @fn MoveBackward(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   This will be passed to the parent constructor.
         */
        MoveBackward(RemoteControlVehicle* v);

        /**
         *  @fn ~MoveBackward()
         *  @brief The destructor for the class.
         */
        ~MoveBackward();

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

#endif  //MOVEBACKWARD_H
