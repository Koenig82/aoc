#pragma once

#include <vector>
#include <string>
#include <iostream>

class MatrixUtil {
   public:
   static std::vector<std::vector<char>> createMatrix(std::vector<std::string>& inputLines);
   static void printMatrix(std::vector<std::vector<char>>& matrix); 
};