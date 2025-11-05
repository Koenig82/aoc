#include "matrixUtil.h"

/**
 * Creates a matrix of characters from a vector of strings, where each string
 * is a row in the matrix and each character in the string is a column in the
 * matrix.
 *
 * @param inputLines The vector of strings to create the matrix from.
 * @return A matrix of characters, where each row is a string from the input
 *         vector and each column is a character in the string.
 */
std::vector<std::vector<char>> MatrixUtil::createMatrix(std::vector<std::string>& inputLines) {

    std::vector<std::vector<char>> matrix(inputLines.size(), std::vector<char>());
    return matrix;
}

/**
 * Prints out a matrix of characters.
 *
 * @param matrix The matrix to print
 */
void MatrixUtil::printMatrix(std::vector<std::vector<char>>& matrix){
    (void) matrix;
    return;
}