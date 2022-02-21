/****************************************************************************************************
 *  @file inc/PSCoreEngineer.h
 *  @brief The header file for the PSCoreEngineer class (Inherits from Engineer).
 *  
 *  @see Engineer.h
 ***************************************************************************************************/

#ifndef PSCOREENGINEER_H
#define PSCOREENGINEER_H

#include "GGSN.h"
#include "FaultsNMS.h"
/****************************************************************************************************
 *  @class PSCoreEngineer
 *  @brief Concrete Observer in the Observer Design Pattern.
 ***************************************************************************************************/
class PSCoreEngineer : public Engineer
{
    private:
        std::string alarmStatus;
        GGSN* _networkElement;
        FaultsNMS* manage;
        std::string status;
    public:
        /**
         *  @fn PSCoreEngineer(std::string n)
         *  @brief The constructor for the class.
         */
        PSCoreEngineer();

        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class
         * 
         *  @param[in]  nms The nms to be used.
         */
        PSCoreEngineer(FaultsNMS* nms);

        /**
         *  @fn ~PSCoreEngineer()
         *  @brief The destructor for the class.
         */
        ~PSCoreEngineer();

        /**
         *  @fn virtual void update() override
         *  @brief The implementation of the pure virtual function update().
         *  
         *  @see Engineer::update()
         */
        virtual void update() override;

        /**
         *  @fn virtual void obsReg(GGSN* b)
         *  @brief A function to set the private variable _networkElement .
         *  
         *  @param[in]  b  The NetworkElement to register with.
         */
        void obsReg(GGSN* b);

        virtual void statusChanged();
        virtual std::string getStatus();
        virtual void setStatus(std::string s);
};

#endif  //PSCOREENGINEER_H
