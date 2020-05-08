#include "File.h"


File::File(const std::string& filename)
{
	try
	{
		this->m_handler.open(filename);
	}
	catch (...)
	{
		std::cerr << "B³ad otwarcia pliku " << filename << std::endl;
	}
	
	populateRowsVector();
}

File::~File()
{
}

float File::getAvgOnCol(int col)
{
	float sum = 0.0;
	int countOfRows = 0;
	for (const auto& row : m_rows)
	{
		try
		{
			sum += row.at(col);
			++countOfRows;
		}
		catch (...)
		{
			std::cerr << "getAvgOnCol error on " << col << std::endl;
			return 0.0f;
		}
		
	}
	return float(sum/countOfRows);
}

std::pair<float, std::vector<int>> File::whichColsHaveMaxNumber(void)
{
	std::vector<int> rowsWithMaxNumber;
	float maxNumber = 0.0;
	//find max number in all columns
	for (int i = 0; i < 6; i++)
	{
		try
		{
			if (findMaxNumberInColumn(i) >= maxNumber)
			{
				maxNumber = findMaxNumberInColumn(i);
			}
		}
		catch(...)
		{

		}
	}
	// check which cols have exactly the same number inside
	for (int i = 0; i < 6; i++)
	{
		if (findMaxNumberInColumn(i) == maxNumber)
		{	
			rowsWithMaxNumber.push_back(i);
		}
	}
	auto retPair = std::make_pair(maxNumber, rowsWithMaxNumber);
	return retPair;
}

int File::countRowsWithOneNumberNotDivisibleByTen(void)
{
	int rowsCount = 0;
	float mod;
	for (const auto& row : m_rows)
	{
		for (int i = 0; i < 6; i++)
		{
			mod = std::fmod(row.at(i), 10.0f);
			if ( mod != 0.0f)
			{
				++rowsCount;
				break;
			}
		}
	}

	return rowsCount;
}

int File::countRowsWithFirstThreeNumbsAreNotDecreasing(void)
{
	int colsWithDecreasingNumbersCount = 0;
	float oldNum = 0;
	for (const auto& rows : m_rows)
	{
		oldNum = rows.at(0);
		for (int i = 1; i < 3; i++)
		{
			if (!(rows.at(i) >= oldNum))
			{
				++colsWithDecreasingNumbersCount;
				break;
			}
			oldNum = rows.at(i);
		}
	}
	return (m_rows.size() - colsWithDecreasingNumbersCount);
}

int File::countRowsWithNumbsInRange(int howMuchNumbers, float numberMin, float numberMax)
{
	int colsWithNumbersInRange = 0;
	for (const auto& row : m_rows)
	{
		int countNumsInRange = 0;
		for (int i = 0; i < 6; i++)
		{
			if ((row.at(i) >= numberMin) & (row.at(i) <= numberMax))
			{
				++countNumsInRange;
			}
		}
		if (countNumsInRange == howMuchNumbers)
		{
			++colsWithNumbersInRange;
		}
	}
	return colsWithNumbersInRange;
}

bool File::populateRowsVector(void)
{
	if (this->m_handler.good())
	{
		std::string line;
		std::string oneToArray;
		std::array<float, 6> rowArray;
		int arrayCounter = 0;
		while (std::getline(this->m_handler, line))
		{
			std::istringstream iss(line);
			arrayCounter = 0;
			rowArray.fill(0.0);
			while (std::getline(iss, oneToArray, ' ' ))
			{
				rowArray.at(arrayCounter) = std::stof(oneToArray);
				++arrayCounter;
			}
			m_rows.push_back(rowArray);
		}
	}
	else
	{
		return false;
	}
	return true;
}

float File::findMaxNumberInColumn(int col)
{
	float maxNumber = 0.0;
	for (const auto& row : m_rows)
	{
		try
		{
			if (row.at(col) > maxNumber)
			{
				maxNumber = row.at(col);
			}
		}
		catch (...)
		{
			return 0.0f;
		}
	}
	return maxNumber;
}
	