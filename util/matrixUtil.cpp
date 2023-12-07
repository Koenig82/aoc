#include "matrixutil.h"

std::vector<std::vector<char>> MatrixUtil::createMatrix(std::vector<std::string>& inputLines) {
    std::vector<std::vector<char>> matrix(inputLines.size(), std::vector<char>());

    for (int y = 0; y < inputLines.size(); ++y) {
        const std::string& line = inputLines[y];
        matrix[y].reserve(line.size());
        for (int x = 0; x < line.size(); ++x) {
            matrix[y].push_back(line[x]);
        }
    }

    return matrix;
}

void MatrixUtil::printMatrix(std::vector<std::vector<char>>& matrix){
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}