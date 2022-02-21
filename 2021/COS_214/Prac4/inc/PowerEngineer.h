/****************************************************************************************************
 *  @file inc/PowerEngineer.h
 *  @brief The header file for the PowerEngineer class (Inherits from Engineer).
 *  
 *  @see Engineer.h
 ***************************************************************************************************/

#ifndef POWERENGINEER_H
#define POWERENGINEER_H

#include "BTS.h"
#include "FaultsNMS.h"
/****************************************************************************************************
 *  @class PowerEngineer
 *  @brief Concrete Observer in the Observer Design Pattern.
 ***************************************************************************************************/
class PowerEngineer : public Engineer
{
    private:
        std::string alarmStatus;
        BTS* _networkElement;
        FaultsNMS* manage;
        std::string status;
    public:
        /**
         *  @fn PowerEngineer(std::string n)
         *  @brief The constructor for the class.
         */
        PowerEngineer();

        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class
         * 
         *  @param[in]  nms The nms to be used.
         */
        PowerEngineer(FaultsNMS* nms);

        /**
         *  @fn ~PowerEngineer()
         *  @brief The destructor for the class.
         */
        ~PowerEngineer();

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

#endif  //POWERENGINEER_H
