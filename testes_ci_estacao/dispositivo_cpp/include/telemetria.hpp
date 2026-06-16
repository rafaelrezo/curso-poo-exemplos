#ifndef TELEMETRIA_HPP
#define TELEMETRIA_HPP

#include <iomanip>
#include <sstream>
#include <string>

struct LeituraSensor {
    std::string tag;
    double valor;
    std::string unidade;
    std::string timestamp;
    std::string status;
};

inline std::string formatarJsonLeitura(const LeituraSensor& leitura) {
    std::ostringstream saida;
    saida << std::fixed << std::setprecision(2);
    saida << "{\"tag\":\"" << leitura.tag << "\",";
    saida << "\"valor\":" << leitura.valor << ",";
    saida << "\"unidade\":\"" << leitura.unidade << "\",";
    saida << "\"timestamp\":\"" << leitura.timestamp << "\",";
    saida << "\"status\":\"" << leitura.status << "\"}";
    return saida.str();
}

#endif

