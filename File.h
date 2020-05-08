#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <tuple>
class File
{
public:
	File(const std::string& filename);
	~File();

	float getAvgOnCol(int col);
	std::pair<float, std::vector<int>> whichColsHaveMaxNumber(void);
	int countRowsWithOneNumberNotDivisibleByTen(void);
	int countRowsWithFirstThreeNumbsAreNotDecreasing(void);
	int countRowsWithNumbsInRange(int howMuchNumbers, float numberMin, float numberMax);

	

private:
	std::ifstream m_handler;
	std::vector<std::array<float, 6>> m_rows;
	bool populateRowsVector(void);
	float findMaxNumberInColumn(int col);
	
	
};

