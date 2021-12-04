// 1) Convert the code below to find and print out valid 9x9 grids

// If you just randomly put values 1-9 into each of the 81 squares,
// there would be 1.96627e77 POSSIBILITES to try!

// There are 6,670,903,752,021,072,936,960 SOLUTIONS so as long 
// each output is a valid grid then you have done your job

// 2) Find the solution to this specific 9x9 Sudoku puzzle:
//                 8 7 6 9 0 0 0 0 0
//				   0 1 0 0 0 6 0 0 0
//				   0 4 0 3 0 5 8 0 0
//				   4 0 0 0 0 0 2 1 0
//				   0 9 0 5 0 0 0 0 0
//				   0 5 0 0 4 0 3 0 6
//				   0 2 9 0 0 0 0 0 8
//				   0 0 4 6 9 0 1 7 3
//				   0 0 0 0 0 1 0 0 4

#include <iostream>
#include <vector>

int count = 0;

void PrintNineByNineGrid(const std::vector<int>& grid)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << grid[(i * 3 * 3) + j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool IsLegalRowColumnWhatever(const std::vector<int>& vector)
{
	std::vector<int> occurrences(vector.size() + 1);

	try
	{
		for (const int& i : vector)
		{
			++occurrences.at(i);
		}
	}

	catch (const std::exception&)
	{
		return false;
	}

	for (std::size_t i = 1; i < occurrences.size(); ++i)
	{
		if (occurrences[i] > 1)
		{
			return false;
		}
	}

	return true;
}

bool IsNineByNineSudokuLegal(const std::vector<int>& grid)
{
	int rows[] = { 0, 9, 18, 27, 36, 45, 54, 63, 72 };
	for (const int& i : rows)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 2], grid[i + 3], grid[i + 4], grid[i + 5], grid[i + 6], grid[i + 7], grid[i + 8] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	int columns[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	for (const int& i : columns)
	{
		std::vector<int> v{ grid[i], grid[i + 9], grid[i + 18], grid[i + 27], grid[i + 36], grid[i + 45], grid[i + 54], grid[i + 63], grid[i + 72] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	int squares[] = { 0, 3, 6, 27, 30, 33, 54, 57, 60};
	for (const int& i : squares)
	{
		std::vector<int> v{ grid[i], grid[i + 1], grid[i + 2], grid[i + 9], grid[i + 10], grid[i + 11], grid[i + 18], grid[i + 19], grid[i + 20] };
		if (IsLegalRowColumnWhatever(v) == false)
		{
			return false;
		}
	}

	return true;
}

void GenerateValidNineByNineGrids(std::vector<int>& grid, int index)
{
	// Variable j to judge initial number is 0 or 1~9
	int j = 0;
	if (index == 81)
	{
		PrintNineByNineGrid(grid);
		// Show 5 records, Press enter show next 5 records
		if (count == 5)
		{
			system("PAUSE");
			count = 0;
		}
		count++;
	}
	else
	{
		//Catch the original value
		int temp = grid[index];
		for (int i = 1; i <= 9; ++i)
		{
			//if this index's value is unable to be motified
			if (grid[index] != 0 && j == 0)
			{
				if (IsNineByNineSudokuLegal(grid) == true)
				{
					GenerateValidNineByNineGrids(grid, index + 1);
					// This break statment is used to skip to the previous index if the value of the
					// next index is not true.
					break;
				}

			}

			grid[index] = i;
			j = 1;
			if (IsNineByNineSudokuLegal(grid) == true)
			{
				GenerateValidNineByNineGrids(grid, index + 1);
			}
		}
		grid[index] = temp;
	}
}

void GenerateAllValidNineByNineGrids()
{
	std::cout << "------1. Find the solution to the specific 9 x 9 Sudoku puzzle------" << std::endl;
	std::vector<int> grid1{8, 7, 6, 9, 0, 0, 0, 0, 0, 
						  0, 1, 0, 0, 0, 6, 0, 0, 0,
						  0, 4, 0, 3, 0, 5, 8, 0, 0,
						  4, 0, 0, 0, 0, 0, 2, 1, 0,
						  0, 9, 0, 5, 0, 0, 0, 0, 0,
						  0, 5, 0, 0, 4, 0, 3, 0, 6,
						  0, 2, 9, 0, 0, 0, 0, 0, 8,
						  0, 0, 4, 6, 9, 0, 1, 7, 3, 
						  0, 0, 0, 0, 0, 1, 0, 0, 4};
	GenerateValidNineByNineGrids(grid1, 0);

	std::cout << "==================================================================" << std::endl << std::endl;
	std::cout << "------2. Output some of the possible 9 x 9 solutions------" << std::endl;
	std::vector<int> grid2(81, 0);
	GenerateValidNineByNineGrids(grid2, 0);
}

int main()
{
	GenerateAllValidNineByNineGrids();
	system("PAUSE");
	return 0;
}