/****************************************************************************************************
 *  @file inc/Command.h
 *  @brief The header file for the Command class.
 ***************************************************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include "RemoteControlVehicle.h"
class RemoteControlVehicle;
/****************************************************************************************************
 *  @class Command
 *  @brief The command participant fo the Command design pattern.
 ***************************************************************************************************/
class Command
{
    private:
        RemoteControlVehicle* receiver;
    public:
        /**
         *  @fn Command(RemoteControlVehicle* v)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   The private variable reciever will be set to this.
         */
        Command(RemoteControlVehicle* v);

        /**
         *  @fn ~Command()
         *  @brief The destructor for the class.
         */
        virtual ~Command();

        RemoteControlVehicle* getReceiver();
        
        /**
         *  @fn virtual void execute() = 0
         *  @brief A pure virtual execute method.
         */
        virtual void execute() = 0;

        /**
         *  @fn virtual void undo() = 0
         *  @brief A pure virtual undo method.
         */
        virtual void undo() = 0;
};

#endif  //COMMAND_H
