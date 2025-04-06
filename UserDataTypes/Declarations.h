#pragma once

enum meatTypes
{
    Pastrami,
    Chicken,
    Pork,
    Prawns
};

class Sandwich
{
public:
    meatTypes meat;
    float weight;

    void heatSandwich();
    
private:
    bool isHot;

};
