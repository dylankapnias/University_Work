/****************************************************************************************************
 *  @file inc/EngineerIterator.h
 *  @brief The header file for the EngineerIterator class.
 ***************************************************************************************************/

#ifndef ENGINEERITERATOR_H
#define ENGINEERITERATOR_H

#include "Engineer.h"
/****************************************************************************************************
 *  @class EngineerIterator
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class EngineerIterator
{
    public:
        /**
         *  @fn EngineerIterator()
         *  @brief The constructor for the class.
         */
        EngineerIterator();

        /**
         *  @fn ~EngineerIterator()
         *  @brief The destructor for the class.
         */
        ~EngineerIterator();

        virtual Engineer* first() = 0;
        virtual Engineer* next() = 0;
        virtual Engineer* current() = 0;
        virtual bool hasNext() = 0;
};

#endif  //ENGINEERITERATOR_H
