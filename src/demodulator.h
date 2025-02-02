#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include <vector>

class Demodulator {
public:
    static std::vector<int> demodulateASK(const std::vector<double>& signal);
    static std::vector<int> demodulateFSK(const std::vector<double>& signal);
    static std::vector<int> demodulatePSK(const std::vector<double>& signal);
};

#endif
