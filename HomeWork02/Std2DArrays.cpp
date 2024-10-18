#include "Std2DArrays.h"
#include <iostream>
#include <stdexcept>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int startValue = 1;

    // SW DIAG (Southwest Diagonal) filling
    for (int col = 0; col < columns; ++col) {  // Fill the top row
        for (int startRow = 0, startCol = col; startCol >= 0; ++startRow, --startCol) {
            if (startRow < rows) {
                arr[startRow][startCol] = startValue++;
            }
        }
    }

    for (int row = 1; row < rows; ++row) {  // Fill the leftmost column
        for (int startRow = row, startCol = columns - 1; startRow < rows && startCol >= 0; ++startRow, --startCol) {
            arr[startRow][startCol] = startValue++;
        }
    }
}

void printArray(const std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
