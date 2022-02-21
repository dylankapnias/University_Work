/****************************************************************************************************
 *  @file inc/OperationsIterator.h
 *  @brief The header file for the OperationsIterator class.
 ***************************************************************************************************/

#ifndef OPERATIONSITERATOR_H
#define OPERATIONSITERATOR_H

#include <vector>

#include "EngineerIterator.h"
/****************************************************************************************************
 *  @class OperationsIterator
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class OperationsIterator : public EngineerIterator
{
    private:
        int currentPos;
        std::vector<Engineer*> itList;
    public:
        /**
         *  @fn OperationsIterator()
         *  @brief The constructor for the class.
         */
        OperationsIterator();

        /**
         *  @fn OperationsIterator()
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   The list to iterate over.
         */
        OperationsIterator(std::vector<Engineer*> v);

        /**
         *  @fn ~OperationsIterator()
         *  @brief The destructor for the class.
         */
        ~OperationsIterator();

        virtual Engineer* first() override;
        virtual Engineer* next() override;
        virtual Engineer* current() override;
        virtual bool hasNext() override;

        OperationsIterator operator++();
};

#endif  //OPERATIONSITERATOR_H
