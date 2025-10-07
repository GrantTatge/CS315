//
// Created by Ali Kooshesh on 9/27/25.
//

#include "Scanner.hpp"

#include <utility>
#include <iostream>
#include <fstream>

#include "utils.hpp"

Scanner::Scanner(std::filesystem::path inputPath) {
    inputPath_ = std::move(inputPath);
}

error_type Scanner::tokenize(std::vector<std::string> &words, const std::filesystem::path &outputFile) {
    namespace fs = std::filesystem;
    fs::path dir = outputFile.parent_path();
    std::string base = outputFile.stem().string();
    fs::path inputFile = dir/ (base + ".txt");

    std::ifstream inputFileStream;
    inputFileStream.open(inputFile.string());
    if (inputFileStream.is_open() == false) {
        return UNABLE_TO_OPEN_FILE_FOR_WRITING;
    }
    while (!inputFileStream.eof()) {
        auto currWord = readWord(inputFileStream);
        if (!currWord.empty()) {
            words.push_back(currWord);
        }
    }
    inputFileStream.close();

    return NO_ERROR;
}

error_type Scanner::tokenize(std::vector<std::string>& words) {
    return tokenize(words, inputPath_);
}

std::string Scanner::readWord(std::istream &in) {
    auto curr = in.get();
    std::string out;

    while (!isalpha(curr) && curr != EOF) {
        curr = in.get();
    }

    while (isalpha(curr) || curr == '\'') {
        out += tolower(curr);
        curr = in.get();
    }

    return out;
}
