#include <iostream>
#include "modulator.h"
#include "demodulator.h"
#include "utils.h"

int main() {
    srand(time(0));

    // Gera uma sequência de bits
    std::vector<int> bits = Utils::generateBits(10);

    // Modulação ASK
    std::vector<double> askSignal = Modulator::modulateASK(bits);
    Utils::exportToCSV(askSignal, "ask_signal.csv");

    // Adiciona ruído ao sinal ASK
    std::vector<double> noisySignal = Utils::addNoise(askSignal, 0.1);
    Utils::exportToCSV(noisySignal, "noisy_ask_signal.csv");

    // Demodulação ASK
    std::vector<int> demodulatedBits = Demodulator::demodulateASK(noisySignal);

    // Análise de erro
    double errorRate = Utils::calculateErrorRate(bits, demodulatedBits);
    std::cout << "Taxa de erro: " << errorRate * 100 << "%\n";

    // Plotagem dos sinais
    Utils::plotSignals(askSignal, noisySignal, "Sinal ASK Original vs Sinal com Ruído");

    return 0;
}
