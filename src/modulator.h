#ifndef MODULATOR_H
#define MODULATOR_H

#include <vector>

class Modulator {
public:
    static std::vector<double> modulateASK(const std::vector<int>& bits);
    static std::vector<double> modulateFSK(const std::vector<int>& bits);
    static std::vector<double> modulatePSK(const std::vector<int>& bits);
};

#endif
