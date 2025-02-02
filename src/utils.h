#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

class Utils {
public:
    static std::vector<int> generateBits(int numBits);
    static std::vector<double> addNoise(const std::vector<double>& signal, double noiseLevel);
    static void exportToCSV(const std::vector<double>& signal, const std::string& filename);
    static double calculateErrorRate(const std::vector<int>& original, const std::vector<int>& received);
    static void plotSignals(const std::vector<double>& signal1, const std::vector<double>& signal2, const std::string& title);
};

#endif
