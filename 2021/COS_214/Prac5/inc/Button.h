/****************************************************************************************************
 *  @file inc/Button.h
 *  @brief The header file for the Button class.
 ***************************************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#include "Command.h"
/****************************************************************************************************
 *  @class Button
 *  @brief The invoker participant of the Command design pattern
 ***************************************************************************************************/
class Button
{
    private:
        Command* command;
    public:
        /**
         *  @fn Button(Command* c)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  c   The private variable command will be set to this.
         */
        Button(Command* c);

        /**
         *  @fn ~Button()
         *  @brief The destructor for the class.
         */
        ~Button();

        /**
         *  @fn void press()
         *  @brief Will exxecute the command.
         * 
         */
        void press();
};

#endif  //BUTTON_H
