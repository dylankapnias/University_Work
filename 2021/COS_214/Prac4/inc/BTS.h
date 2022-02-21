/****************************************************************************************************
 *  @file inc/BTS.h
 *  @brief The header file for the BTS class (Inherits from NetworkElement).
 *  @see NetworkElement.h
 ***************************************************************************************************/

#ifndef BTS_H
#define BTS_H

#include <set>

#include "NetworkElement.h"
/****************************************************************************************************
 *  @class BTS
 *  @brief Base Transceiver Station. Concrete Subject in the Observer Design Pattern.
 ***************************************************************************************************/
class BTS : public NetworkElement
{
    private:
        const std::set<std::string> ALARM_STATES;
        std::string name; /**< A string to store the name */
        std::string alarmState; /**< A string to store the alarm state */
    public:
        /**
         *  @fn BTS(std::string n)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  n   The passed in value for the name variable.
         */
        BTS(std::string n);

        /**
         *  @fn ~BTS()
         *  @brief The destructor for the class.
         */
        virtual ~BTS();

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

#endif  //BTS_H
