#ifndef SHIRT_H
#define SHIRT_H

#include "Merchandise.h"
#include <string>

using namespace std;

class Shirt : public Merchandise {
    private:
        string size;

    public:
        Shirt(string, double, string);
        virtual ~Shirt();

        virtual string getDescription() override;
        Merchandise* clone();
};

#endif