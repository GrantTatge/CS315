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

error_type Scanner::tokenize(std::vector<std::string> &words, const std::filesystem::path &inputFile) {
    // Reads each potential token in inputFile into words
    // A token is a word composed entirely of lowercase letters
    std::ifstream inputFileStream;
    inputFileStream.open(inputFile.string());
    if (inputFileStream.is_open() == false) {
        return UNABLE_TO_OPEN_FILE_FOR_WRITING;
    }

    while (!inputFileStream.eof()) {
        auto currWord = readWord(inputFileStream);
        if (!currWord.empty()) {
            // !currWord.empty() prevents empty strings from being added to words
            words.push_back(currWord);
        }
    }
    inputFileStream.close();

    return NO_ERROR;
}

error_type Scanner::tokenize(std::vector<std::string>& words) {
    // Since the input in main.cpp is a .tokens file, a corresponding .txt file must be constructed
    // Calling this version of tokenize is assuming that inputPath_ must be accessed
    namespace fs = std::filesystem;
    fs::path dir = inputPath_.parent_path();
    std::string base = inputPath_.stem().string();
    fs::path inputFile = dir/ (base + ".txt");
    return tokenize(words, inputFile);
}

std::string Scanner::readWord(std::istream &in) {
    // Constructs a return string from an input file
    // Since the method is static and in is always the same input, readWord handles "moving" through the
    // input file.
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
