/****************************************************************************************************
 *  @file inc/VectorOfOperations.h
 *  @brief The header file for the VectorOfOperations class.
 ***************************************************************************************************/

#ifndef VECTOROFOPERATIONS_H
#define VECTOROFOPERATIONS_H

#include <vector>

#include "EngineerCollection.h"
#include "OperationsIterator.h"
/****************************************************************************************************
 *  @class VectorOfOperations
 *  @brief The concrete aggregate of the Iterator Design Pattern.
 ***************************************************************************************************/
class VectorOfOperations : public EngineerCollection
{
    private:
        std::vector<Engineer*> list;
    public:
        /**
         *  @fn VectorOfOperations()
         *  @brief The constructor for the class.
         */
        VectorOfOperations();

        /**
         *  @fn ~VectorOfOperations()
         *  @brief The destructor for the class.
         */
        ~VectorOfOperations();

        virtual EngineerIterator* createEngineerIterator() const override;
        virtual void addEngineer(Engineer* e) override;
        virtual void removeEngineer() override;
        virtual bool isEmpty() override;
};

#endif  //VECTOROFOPERATIONS_H
