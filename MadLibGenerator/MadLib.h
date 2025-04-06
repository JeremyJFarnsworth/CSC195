#ifndef MADLIB_H
#define MADLIB_H

#include <string>

class MadLib {
private:
    int number;
    std::string pluralNoun;
    std::string noun;

public:
    MadLib(int num, const std::string& plural, const std::string& single);

    void generateMadLib();
};

#endif
