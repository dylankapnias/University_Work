/****************************************************************************************************
 *  @file inc/NMS.h
 *  @brief The header file for the NMS class.
 ***************************************************************************************************/

#ifndef NMS_H
#define NMS_H

#include "Engineer.h"
/****************************************************************************************************
 *  @class NMS
 *  @brief Mediator participant of the Mediator Design Pattern.
 ***************************************************************************************************/
class NMS
{
    public:
        /**
         *  @fn NMS()
         *  @brief The constructor for the class.
         */
        NMS();

        /**
         *  @fn ~NMS()
         *  @brief The destructor for the class.
         */
        virtual ~NMS();

        virtual void notify(Engineer* e) = 0;
        virtual void createEngineer(Engineer* e) = 0;
};

#endif  //NMS_H
