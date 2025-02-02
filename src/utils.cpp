#include "utils.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdio>

std::vector<int> Utils::generateBits(int numBits) {
    std::vector<int> bits(numBits);
    for (int i = 0; i < numBits; ++i) {
        bits[i] = rand() % 2;
    }
    return bits;
}

std::vector<double> Utils::addNoise(const std::vector<double>& signal, double noiseLevel) {
    std::vector<double> noisySignal = signal;
    for (size_t i = 0; i < noisySignal.size(); ++i) {
        noisySignal[i] += ((double)rand() / RAND_MAX - 0.5) * noiseLevel;
    }
    return noisySignal;
}

void Utils::exportToCSV(const std::vector<double>& signal, const std::string& filename) {
    std::ofstream file(filename);
    for (size_t i = 0; i < signal.size(); ++i) {
        file << signal[i] << "\n";
    }
    file.close();
}

double Utils::calculateErrorRate(const std::vector<int>& original, const std::vector<int>& received) {
    int errors = 0;
    for (size_t i = 0; i < original.size(); ++i) {
        if (original[i] != received[i]) errors++;
    }
    return static_cast<double>(errors) / original.size();
}

void Utils::plotSignals(const std::vector<double>& signal1, const std::vector<double>& signal2, const std::string& title) {
    // Exporta os sinais para arquivos CSV temporários
    exportToCSV(signal1, "signal1.csv");
    exportToCSV(signal2, "signal2.csv");

    // Cria um script GNUplot
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title '%s'\n", title.c_str());
        fprintf(gnuplotPipe, "set xlabel 'Tempo'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot 'signal1.csv' with lines title 'Sinal Original', 'signal2.csv' with lines title 'Sinal com Ruído'\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);
    } else {
        std::cerr << "Erro ao abrir GNUplot.\n";
    }
}
