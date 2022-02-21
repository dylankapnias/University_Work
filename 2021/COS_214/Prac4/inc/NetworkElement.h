/****************************************************************************************************
 *  @file inc/NetworkElement.h
 *  @brief The header file for the NetworkElement class.
 ***************************************************************************************************/

#ifndef NETWORKELEMENT_H
#define NETWORKELEMENT_H

#include <iostream>
#include <vector>
#include <stdexcept>

#include "Engineer.h"
#include "VectorOfOperations.h"
#include "ListOfCore.h"

class Engineer;
/****************************************************************************************************
 *  @class NetworkElement
 *  @brief The subject participant in the Observer Design Pattern
 ***************************************************************************************************/
class NetworkElement
{
    private:
        std::vector<Engineer*> engineers; /**< A vector containing attached engineers */
        VectorOfOperations operations;
        ListOfCore core;
    public:
        /**
         *  @fn NetworkElement()
         *  @brief The constructor for the class.
         */
        NetworkElement();

        /**
         *  @fn virutal ~NetworkElement()
         *  @brief The virtual destructor for the class.
         */
        virtual ~NetworkElement();

        /**
         *  @fn void attach(Engineer* e)
         *  @brief A function to attach an engineer.
         *  
         *  Preconditions:
         *   - e must not already be a part of the collection.
         *   - e must not be NULL.
         *  
         *  Postconditions:
         *   - The passed in engineer will be added to the engineers collection.
         *  
         *  Exceptions:
         *   - If e is part of the collection throw an std::logic_error exception "e must not already be part of the collection."
         *   - If e is null throw an std::logic_error exception "e must not be null."
         *  
         *  @param[in]  e   The engineer to attach.
         *  
         *  @see Engineer.h
         */
        void attach(Engineer* e);

        /**
         *  @fn detach()
         *  @brief A function to detach an engineer.
         *  
         *  Preconditions:
         *   - The engineers collection must not be empty.
         *   - e must not be NULL.
         *   - e must be in the engineers collection.
         *  
         *  Postconditions:
         *   - The passed in engineer will be removed.
         *  
         *  Exceptions:
         *   - If the collection is empty throw an std::logic_error exception "The collection is already empty."
         *   - If e is null throw an std::logic_error exception "e must not be null."
         *   - If e is not a part of the collection throw an std::logic_error exception "e must be a part of the collection."
         *  
         *  @param[in]  e   The engineer to attach.
         *  
         *  @see Engineer.h
         */
        void detach(Engineer* e);

        /**
         *  @fn notify()
         *  @brief A function to notify all engineers.
         *  
         *  @see Engineer.h
         */
        void notify();
};

#endif  //NETWORKELEMENT_H
