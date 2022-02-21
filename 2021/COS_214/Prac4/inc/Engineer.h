/****************************************************************************************************
 *  @file inc/Engineer.h
 *  @brief The header file for the Engineer class.
 ***************************************************************************************************/

#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>
#include <iostream>

class NMS;
/****************************************************************************************************
 *  @class Engineer
 *  @brief Observer Interface in the Observer Design Pattern.
 ***************************************************************************************************/
class Engineer
{
    private:
        std::string name; /**< The name variable */
        Engineer* nextEngineer; /**< Pointer to the next Eng in the list */
        NMS* manage;
        std::string status;
    public:
        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  n   The private variable name will be set to this.
         */
        Engineer(std::string n);

        /**
         *  @fn Engineer(std::string n)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  n   The private variable name will be set to this.
         *  @param[in]  nms The nms to be used.
         */
        Engineer(std::string n, NMS* nms);

        /**
         *  @fn virtual ~Engineer()
         *  @brief The virutal destructor for the class.
         */
        virtual ~Engineer();

        /**
         *  @fn std::string getName()
         *  @brief A getter for the private variable name.
         *  
         *  @return A string containing the contents of the name variable.
         */
        std::string getName();

        //std::string getStatus();

        //void setStatus(std::string s);

        Engineer* getNext();

        void setNext(Engineer* e);

        /**
         *  @fn virtual void update() = 0
         *  @brief A pure virtual function to update the engineer.
         */
        virtual void update() = 0;

        virtual void statusChanged() = 0;
        virtual std::string getStatus();
        virtual void setStatus(std::string s);
};

#endif  //ENGINEER_H
