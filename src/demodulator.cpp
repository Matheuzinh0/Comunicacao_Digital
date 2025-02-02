#include "demodulator.h"
#include <cmath>
#include <algorithm>

const int BIT_DURATION = 100; // Duração de cada bit em amostras

std::vector<int> Demodulator::demodulateASK(const std::vector<double>& signal) {
    std::vector<int> bits;
    for (size_t i = 0; i < signal.size(); i += BIT_DURATION) {
        double avg = 0.0;
        for (int j = 0; j < BIT_DURATION; ++j) {
            avg += signal[i + j];
        }
        avg /= BIT_DURATION;
        bits.push_back(avg > 0.5 ? 1 : 0);
    }
    return bits;
}

std::vector<int> Demodulator::demodulateFSK(const std::vector<double>& signal) {
    std::vector<int> bits;
    for (size_t i = 0; i < signal.size(); i += BIT_DURATION) {
        double sum1 = 0.0, sum2 = 0.0;
        for (int j = 0; j < BIT_DURATION; ++j) {
            sum1 += signal[i + j] * sin(2 * M_PI * j / BIT_DURATION);
            sum2 += signal[i + j] * sin(4 * M_PI * j / BIT_DURATION);
        }
        bits.push_back(sum2 > sum1 ? 1 : 0);
    }
    return bits;
}

std::vector<int> Demodulator::demodulatePSK(const std::vector<double>& signal) {
    std::vector<int> bits;
    for (size_t i = 0; i < signal.size(); i += BIT_DURATION) {
        double sum = 0.0;
        for (int j = 0; j < BIT_DURATION; ++j) {
            sum += signal[i + j] * sin(2 * M_PI * j / BIT_DURATION);
        }
        bits.push_back(sum > 0 ? 1 : 0);
    }
    return bits;
}
