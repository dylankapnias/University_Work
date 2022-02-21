/****************************************************************************************************
 *  @file inc/TransmissionEngineer.h
 *  @brief The header file for the TransmissionEngineer class (Inherits from Engineer).
 *  
 *  @see Engineer.h
 ***************************************************************************************************/

#ifndef TRANSMISSIONENGINEER_H
#define TRANSMISSIONENGINEER_H

#include "BTS.h"
#include "FaultsNMS.h"
/****************************************************************************************************
 *  @class TransmissionEngineer
 *  @brief Concrete Observer in the Observer Design Pattern.
 ***************************************************************************************************/
class TransmissionEngineer : public Engineer
{
    private:
        std::string alarmStatus;
        BTS* _networkElement;
        FaultsNMS* manage;
        std::string status;
    public:
        /**
         *  @fn TransmissionEngineer(std::string n)
         *  @brief The constructor for the class.
         */
        TransmissionEngineer();

        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class
         * 
         *  @param[in]  nms The nms to be used.
         */
        TransmissionEngineer(FaultsNMS* nms);

        /**
         *  @fn ~TransmissionEngineer()g
         *  @brief The destructor for the class.
         */
        ~TransmissionEngineer();

        /**
         *  @fn virtual void update() override
         *  @brief The implementation of the pure virtual function update().
         *  
         *  @see Engineer::update()
         */
        virtual void update() override;

        /**
         *  @fn virtual void obsReg(BTS* b)
         *  @brief A function to set the private variable _networkElement .
         *  
         *  @param[in]  b  The NetworkElement to register with.
         */
        void obsReg(BTS* b);

        virtual void statusChanged();
        virtual std::string getStatus();
        virtual void setStatus(std::string s);
};

#endif  //TRANSMISSIONENGINEER_H
