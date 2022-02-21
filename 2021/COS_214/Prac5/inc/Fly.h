/****************************************************************************************************
 *  @file inc/Fly.h
 *  @brief The header file for the Fly class.
 ***************************************************************************************************/

#ifndef FLY_H
#define FLY_H

#include "Command.h"
/****************************************************************************************************
 *  @class Fly
 *  @brief The concrete command participant of the chain of resposibilty design pattern.
 ***************************************************************************************************/
class Fly : public Command
{
    public:
        /**
         *  @fn Fly(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   This will be passed to the parent constructor.
         */
        Fly(RemoteControlVehicle* v);

        /**
         *  @fn ~Fly()
         *  @brief The destructor for the class.
         */
        ~Fly();

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

#endif  //FLY_H
