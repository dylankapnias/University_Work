/****************************************************************************************************
 *  @file inc/CSCoreEngineer.h
 *  @brief The header file for the CSCoreEngineer class (Inherits from Engineer).
 *  
 *  @see Engineer.h
 ***************************************************************************************************/

#ifndef CSCOREENGINEER_H
#define CSCOREENGINEER_H

#include "MSC.h"
#include "FaultsNMS.h"
/****************************************************************************************************
 *  @class CSCoreEngineer
 *  @brief Concrete Observer in the Observer Design Pattern.
 ***************************************************************************************************/
class CSCoreEngineer : public Engineer
{
    private:
        std::string alarmStatus;
        MSC* _networkElement;
        FaultsNMS* manage;
        std::string status;
    public:
        /**
         *  @fn CSCoreEngineer(std::string n)
         *  @brief The constructor for the class.
         */
        CSCoreEngineer();

        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class
         * 
         *  @param[in]  nms The nms to be used.
         */
        CSCoreEngineer(FaultsNMS* nms);

        /**
         *  @fn ~CSCoreEngineer()
         *  @brief The destructor for the class.
         */
        ~CSCoreEngineer();

        /**
         *  @fn virtual void update() override
         *  @brief The implementation of the pure virtual function update().
         *  
         *  @see Engineer::update()
         */
        virtual void update() override;

        /**
         *  @fn virtual void obsReg(MSC* b)
         *  @brief A function to set the private variable _networkElement .
         *  
         *  @param[in]  b  The NetworkElement to register with.
         */
        void obsReg(MSC* b);

        virtual void statusChanged();
        virtual std::string getStatus();
        virtual void setStatus(std::string s);
};

#endif  //CSCOREENGINEER_H
