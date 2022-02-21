/****************************************************************************************************
 *  @file inc/ListOfCore.h
 *  @brief The header file for the ListOfCore class.
 ***************************************************************************************************/

#ifndef LISTOFCORE_H
#define LISTOFCORE_H

#include "EngineerCollection.h"
#include "CoreIterator.h"
/****************************************************************************************************
 *  @class ListOfCore
 *  @brief The concrete aggregate of the Iterator Design Pattern.
 ***************************************************************************************************/
class ListOfCore : public EngineerCollection
{
    protected:
        Engineer* startingPoint;
    public:
        /**
         *  @fn ListOfCore()
         *  @brief The constructor for the class.
         */
        ListOfCore();

        /**
         *  @fn ~ListOfCore()
         *  @brief The destructor for the class.
         */
        ~ListOfCore();

        virtual EngineerIterator* createEngineerIterator() const override;
        virtual void addEngineer(Engineer* e) override;
        virtual void removeEngineer() override;
        virtual bool isEmpty() override;
};

#endif  //LISTOFCORE_H
