#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int countWordsInFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open the file " << fileName << std::endl;
        return -1; // Return -1 to indicate an error
    }

    int wordCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            ++wordCount;
        }
    }

    file.close();
    return wordCount;
}

int main() {
    std::string fileName;

    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    int totalWordCount = countWordsInFile(fileName);
    if (totalWordCount >= 0) {
        std::cout << "Total word count in the file: " << totalWordCount << std::endl;
    }

    return 0;
}