#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <string>

using namespace std;

class Merchandise {
    private:
        static long ID;
        const long currentID;

        string club;
        string type;
        double price;

    public:
        Merchandise(string, string, double);
        virtual ~Merchandise();
        virtual string getDescription();
        virtual Merchandise* clone() = 0;
        string getClub();
        double getPrice();
};

#endif