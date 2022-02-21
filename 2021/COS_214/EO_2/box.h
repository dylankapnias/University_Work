#ifndef BOX_H
#define BOX_H

#include "GraphicDecorator.h"
#include <string>

class Box : public GraphicDecorator 
{
    private:
        std::string _box;

    public:
        Box(Graphic*, std::string);
        virtual void print() override;
        Box();
};

#endif