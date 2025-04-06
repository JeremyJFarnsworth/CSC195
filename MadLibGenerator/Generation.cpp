#include "MadLib.h"
#include <iostream>

MadLib::MadLib(int num, const std::string& plural, const std::string& single)
    : number(num), pluralNoun(plural), noun(single) {
}

void MadLib::generateMadLib() {
    std::cout << "Once upon a time, in a land filled with " << number
        << " mystical " << pluralNoun
        << ", a brave knight set off on an adventure to find the legendary "
        << noun << "." << std::endl;
}
