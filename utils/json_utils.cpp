#include "json_utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h> // Necessário para forçar UTF-8 no Windows

std::string getFileContent(const std::string &index)
{
    return getFileContent(index, "pt-BR");
}

std::string getFileContent(const std::string &index, const std::string &culture)
{
    std::string paths[] = {"dialog/index.json"};
    std::ifstream file;

    // Tentar abrir o JSON em um dos caminhos definidos com modo binário para evitar problemas de BOM
    for (const std::string &path : paths)
    {
        file.open(path, std::ios::binary);
        if (file)
            break;
    }

    if (!file)
    {
        std::cerr << "Erro: Arquivo JSON não encontrado." << std::endl;
        return index;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string json = buffer.str();
    file.close();

    // Remover BOM (caso o arquivo tenha sido salvo com BOM)
    if (json.size() >= 3 && (unsigned char)json[0] == 0xEF && (unsigned char)json[1] == 0xBB && (unsigned char)json[2] == 0xBF)
    {
        json.erase(0, 3);
    }

    // Procurar a chave do índice no JSON
    size_t indexPos = json.find("\"" + index + "\"");
    if (indexPos == std::string::npos)
        return index;

    // Procurar o idioma dentro da chave encontrada
    size_t langPos = json.find("\"" + culture + "\"", indexPos);
    if (langPos == std::string::npos)
        return index;

    // Extrair o texto
    size_t start = json.find(":", langPos);
    size_t end = json.find(",", start);
    if (end == std::string::npos)
        end = json.find("}", start);

    if (start == std::string::npos || end == std::string::npos)
        return index;

    std::string text = json.substr(start + 2, end - start - 3);
    return text.empty() ? index : text;
}
