/****************************************************************************************************
 *  @file inc/CoreIterator.h
 *  @brief The header file for the CoreIterator class.
 ***************************************************************************************************/

#ifndef COREITERATOR_H
#define COREITERATOR_H

#include "EngineerIterator.h"
/****************************************************************************************************
 *  @class CoreIterator
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class CoreIterator : public EngineerIterator
{
    private:
        Engineer* firstEngineer;
        Engineer* currentEngineer;
    public:
        /**
         *  @fn CoreIterator()
         *  @brief The constructor for the class.
         */
        CoreIterator();

        /**
         *  @fn CoreIterator()
         *  @brief The constructor for the class.
         *  
         *  @param[in]  h   Head
         *  @param[in]  c   Current
         */
        CoreIterator(Engineer* h, Engineer* c);

        /**
         *  @fn ~CoreIterator()
         *  @brief The destructor for the class.
         */
        ~CoreIterator();

        virtual Engineer* first() override;
        virtual Engineer* next() override;
        virtual Engineer* current() override;
        virtual bool hasNext() override;

        CoreIterator operator++();
};

#endif  //COREITERATOR_H
