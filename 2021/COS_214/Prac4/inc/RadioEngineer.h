/****************************************************************************************************
 *  @file inc/RadioEngineer.h
 *  @brief The header file for the RadioEngineer class (Inherits from Engineer).
 *  
 *  @see Engineer.h
 ***************************************************************************************************/

#ifndef RADIOENGINEER_H
#define RADIOENGINEER_H

#include "BTS.h"
#include "BSC.h"
#include "FaultsNMS.h"
/****************************************************************************************************
 *  @class RadioEngineer
 *  @brief Concrete Observer in the Observer Design Pattern.
 ***************************************************************************************************/
class RadioEngineer : public Engineer
{
    private:
        std::string alarmStatus_BTS; /**< A string to store the alarm state */
        std::string alarmStatus_BSC; /**< A string to store the alarm state */
        BTS* _networkElement_BTS; /**< A reference to the NetworkElement the Engineer is registered to */
        BSC* _networkElement_BSC; /**< A reference to the NetworkElement the Engineer is registered to */
        FaultsNMS* manage;
        std::string status;
    public:
        /**
         *  @fn RadioEngineer(std::string n)
         *  @brief The constructor for the class.
         */
        RadioEngineer();

        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class
         * 
         *  @param[in]  nms The nms to be used.
         */
        RadioEngineer(FaultsNMS* nms);

        /**
         *  @fn ~RadioEngineer()
         *  @brief The destructor for the class.
         */
        ~RadioEngineer();

        /**
         *  @fn virtual void update() override
         *  @brief The implementation of the pure virtual function update().
         *  
         *  Preconditions:
         *   - _networkElement must not be NULL.
         *  
         *  Postconditions:
         *   - The referenced NetworkElement object will have it's alarmState updated.
         *  
         *  Exceptions:
         *   - If _networkElement is null throw an std::logic_error exception "_networkElement must not be null."
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

        /**
         *  @fn virtual void obsReg(BSC* b)
         *  @brief A function to set the private variable _networkElement .
         *  
         *  @param[in]  b  The NetworkElement to register with.
         */
        void obsReg(BSC* b);

        virtual void statusChanged();
        virtual std::string getStatus();
        virtual void setStatus(std::string s);
};

#endif  //RADIOENGINEER_H
