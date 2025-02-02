#include "modulator.h"
#include <cmath>

const double PI = 3.14159265358979323846;
const int BIT_DURATION = 100; // Duração de cada bit em amostras

std::vector<double> Modulator::modulateASK(const std::vector<int>& bits) {
    std::vector<double> signal(bits.size() * BIT_DURATION);
    for (size_t i = 0; i < bits.size(); ++i) {
        double amplitude = bits[i] == 1 ? 1.0 : 0.0;
        for (int j = 0; j < BIT_DURATION; ++j) {
            signal[i * BIT_DURATION + j] = amplitude * sin(2 * PI * j / BIT_DURATION);
        }
    }
    return signal;
}

std::vector<double> Modulator::modulateFSK(const std::vector<int>& bits) {
    std::vector<double> signal(bits.size() * BIT_DURATION);
    for (size_t i = 0; i < bits.size(); ++i) {
        double frequency = bits[i] == 1 ? 2.0 : 1.0;
        for (int j = 0; j < BIT_DURATION; ++j) {
            signal[i * BIT_DURATION + j] = sin(2 * PI * frequency * j / BIT_DURATION);
        }
    }
    return signal;
}

std::vector<double> Modulator::modulatePSK(const std::vector<int>& bits) {
    std::vector<double> signal(bits.size() * BIT_DURATION);
    for (size_t i = 0; i < bits.size(); ++i) {
        double phase = bits[i] == 1 ? 0.0 : PI;
        for (int j = 0; j < BIT_DURATION; ++j) {
            signal[i * BIT_DURATION + j] = sin(2 * PI * j / BIT_DURATION + phase);
        }
    }
    return signal;
}
