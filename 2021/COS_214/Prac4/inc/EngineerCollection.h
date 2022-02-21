/****************************************************************************************************
 *  @file inc/EngineerCollection.h
 *  @brief The header file for the EngineerCollection class.
 ***************************************************************************************************/

#ifndef ENGINEERCOLLECTION_H
#define ENGINEERCOLLECTION_H

#include "Engineer.h"
#include "EngineerIterator.h"
/****************************************************************************************************
 *  @class EngineerCollection
 *  @brief The aggregate class of the Iterator Design Pattern.
 ***************************************************************************************************/
class EngineerCollection
{
    public:
        /**
         *  @fn EngineerCollection()
         *  @brief The constructor for the class.
         */
        EngineerCollection();

        /**
         *  @fn ~EngineerCollection()
         *  @brief The destructor for the class.
         */
        virtual ~EngineerCollection();

        virtual EngineerIterator* createEngineerIterator() const = 0;
        virtual void addEngineer(Engineer* e) = 0;
        virtual void removeEngineer() = 0;
        virtual bool isEmpty() = 0;
};

#endif  //ENGINEERCOLLECTION_H
