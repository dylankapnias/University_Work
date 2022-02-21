/****************************************************************************************************
 *  @file inc/FaultsNMS.h
 *  @brief The header file for the FaultsNMS class.
 ***************************************************************************************************/

#ifndef FAULTSNMS_H
#define FAULTSNMS_H

#include <vector>

#include "NMS.h"
/****************************************************************************************************
 *  @class FaultsNMS
 *  @brief Concrete Mediator for the Mediator Design Pattern.
 ***************************************************************************************************/
class FaultsNMS : public NMS
{
    private:
        std::vector<Engineer*> engineers;
    public:
        /**
         *  @fn FaultsNMS()
         *  @brief The constructor for the class.
         */
        FaultsNMS();

        /**
         *  @fn ~FaultsNMS()
         *  @brief The destructor for the class.
         */
        ~FaultsNMS();

        void print();

        virtual void notify(Engineer* e) override;
        virtual void createEngineer(Engineer* e) override;
};

#endif  //FAULTSNMS_H
