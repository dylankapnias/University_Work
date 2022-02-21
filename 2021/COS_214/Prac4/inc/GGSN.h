/****************************************************************************************************
 *  @file inc/GGSN.h
 *  @brief The header file for the GGSN class (Inherits from NetworkElement).
 *  @see NetworkElement.h
 ***************************************************************************************************/

#ifndef GGSN_H
#define GGSN_H

#include <set>

#include "NetworkElement.h"
/****************************************************************************************************
 *  @class GGSN
 *  @brief Gateway GPRS Support Node. Concrete Subject in the Observer Design Pattern.
 ***************************************************************************************************/
class GGSN : public NetworkElement
{
    private:
        const std::set<std::string> ALARM_STATES;
        std::string name; /**< A string to store the name */
        std::string alarmState; /**< A string to store the alarm state */
    public:
        /**
         *  @fn GGSN(std::string n)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  n   The passed in value for the name variable.
         */
        GGSN(std::string n);

        /**
         *  @fn ~GGSN()
         *  @brief The destructor for the class.
         */
        virtual ~GGSN();

        /**
         *  @fn std::string getName()
         *  @brief A getter for the variable name.
         */
        std::string getName();

        /**
         *  @fn void setName()
         *  @brief A setter for the variable name.
         *  
         *  @param[in]  n   The parameter that the private variable name will be set to.
         */
        void setName(std::string n);


        /**
         *  @fn std::string getAlarm()
         *  @brief A getter for the variable state.
         */
        std::string getAlarm();

        /**
         *  @fn void setAlarm(std::string s)
         *  @brief A setter for the variable alarmState.
         *  
         *  Preconditions:
         *   - s must be in the set {"critical", "major", "minor", "clear"}
         *  
         *  Postconditions:
         *   - The private variable alarmState will be set to s.
         *  
         *  Exceptions:
         *   - If s is not in the above described set throw an std::invalid_argument exception "s must be in the set {"critical", "major", "minor", "clear"}."
         *  
         *  @param[in]  s   The parameter that the private variable alarmState will be set to. 
         */
        void setAlarm(std::string s);
};

#endif  //GGSN_H
