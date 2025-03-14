#include <iostream>
#include <random>
#include <iomanip>
#include <vector>

using namespace std;

typedef std::vector<std::vector<std::vector<int>>> Int3DVector;

class RubiksCube
{
public:
	RubiksCube();
	~RubiksCube();
	void print();
	void rightAntiClock();
	void rightClock();
	void topClock();
	void topAntiClock();
	void leftClock();
	void leftAntiClock();
	void bottomClock();
	void bottomAntiClock();
	void frontClock();
	void frontAntiClock();
	void backClock();
	void backAntiClock();
	void rotate(int face, int direction);
	void printFront();
	void printBack();
	void printLeft();
	void printRight();
	void printTop();
	void printBottom();
	bool ellenoriz();
	void set(Int3DVector &arr);
	void reset();
	Int3DVector getArr() { return arr; }

private:
	Int3DVector arr;
};

RubiksCube::RubiksCube()
{
	arr = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				arr[i][j][k] = 0;
			}
		}
	}
	// f
	arr[0][1][1] = 1;
	// b
	arr[1][0][0] = 1;
	arr[1][1][0] = 1;
	arr[1][2][0] = 1;
	arr[1][0][2] = 1;
	arr[1][1][2] = 1;
	arr[1][2][2] = 1;
	// l
	arr[2][0][2] = 1;
	arr[2][2][0] = 1;
	// r
	arr[3][0][0] = 1;
	arr[3][0][2] = 1;
	arr[3][1][1] = 1;
	arr[3][2][0] = 1;
	arr[3][2][2] = 1;
	// t
	arr[4][0][0] = 1;
	arr[4][0][2] = 1;
	arr[4][2][0] = 1;
	arr[4][2][2] = 1;
	// b
	arr[5][0][2] = 1;
	arr[5][1][1] = 1;
	arr[5][2][0] = 1;
}

RubiksCube::~RubiksCube()
{
}

void RubiksCube::set(Int3DVector &arr)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				this->arr[i][j][k] = arr[i][j][k];
			}
		}
	}
}

void RubiksCube::reset()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				arr[i][j][k] = 0;
			}
		}
	}
	// f
	arr[0][1][1] = 1;
	// b
	arr[1][0][0] = 1;
	arr[1][1][0] = 1;
	arr[1][2][0] = 1;
	arr[1][0][2] = 1;
	arr[1][1][2] = 1;
	arr[1][2][2] = 1;
	// l
	arr[2][0][2] = 1;
	arr[2][2][0] = 1;
	// r
	arr[3][0][0] = 1;
	arr[3][0][2] = 1;
	arr[3][1][1] = 1;
	arr[3][2][0] = 1;
	arr[3][2][2] = 1;
	// t
	arr[4][0][0] = 1;
	arr[4][0][2] = 1;
	arr[4][2][0] = 1;
	arr[4][2][2] = 1;
	// b
	arr[5][0][2] = 1;
	arr[5][1][1] = 1;
	arr[5][2][0] = 1;
}

void RubiksCube::print()
{
	cout << "Printing " << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				cout << this->arr[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void RubiksCube::rightAntiClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[4][0][1] = arr[4][1][0];
	temp[4][1][0] = arr[4][2][1];
	temp[4][2][1] = arr[4][1][2];
	temp[4][1][2] = arr[4][0][1];

	temp[4][0][0] = arr[4][2][0];
	temp[4][2][0] = arr[4][2][2];
	temp[4][2][2] = arr[4][0][2];
	temp[4][0][2] = arr[4][0][0];

	temp[0][0][2] = arr[3][0][2];
	temp[0][1][2] = arr[3][1][2];
	temp[0][2][2] = arr[3][2][2];

	temp[3][0][2] = arr[5][0][2];
	temp[3][1][2] = arr[5][1][2];
	temp[3][2][2] = arr[5][2][2];

	temp[5][0][2] = arr[1][0][2];
	temp[5][1][2] = arr[1][1][2];
	temp[5][2][2] = arr[1][2][2];

	temp[1][0][2] = arr[0][0][2];
	temp[1][1][2] = arr[0][1][2];
	temp[1][2][2] = arr[0][2][2];
	set(temp);
}

void RubiksCube::rightClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[4][0][1] = arr[4][1][2];
	temp[4][1][0] = arr[4][0][1];
	temp[4][2][1] = arr[4][1][0];
	temp[4][1][2] = arr[4][2][1];

	temp[4][0][0] = arr[4][0][2];
	temp[4][2][0] = arr[4][0][0];
	temp[4][2][2] = arr[4][2][0];
	temp[4][0][2] = arr[4][2][2];

	temp[0][0][2] = arr[1][0][2];
	temp[0][1][2] = arr[1][1][2];
	temp[0][2][2] = arr[1][2][2];

	temp[3][0][2] = arr[0][0][2];
	temp[3][1][2] = arr[0][1][2];
	temp[3][2][2] = arr[0][2][2];

	temp[5][0][2] = arr[3][0][2];
	temp[5][1][2] = arr[3][1][2];
	temp[5][2][2] = arr[3][2][2];

	temp[1][0][2] = arr[5][0][2];
	temp[1][1][2] = arr[5][1][2];
	temp[1][2][2] = arr[5][2][2];
	set(temp);
}

void RubiksCube::topClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[0][0][1] = arr[0][1][2];
	temp[0][1][0] = arr[0][0][1];
	temp[0][2][1] = arr[0][1][0];
	temp[0][1][2] = arr[0][2][1];

	temp[0][0][0] = arr[0][0][2];
	temp[0][2][0] = arr[0][0][0];
	temp[0][2][2] = arr[0][2][0];
	temp[0][0][2] = arr[0][2][2];

	temp[2][0][0] = arr[1][0][0];
	temp[2][1][0] = arr[1][1][0];
	temp[2][2][0] = arr[1][2][0];

	temp[3][0][0] = arr[2][0][0];
	temp[3][1][0] = arr[2][1][0];
	temp[3][2][0] = arr[2][2][0];

	temp[4][0][0] = arr[3][0][0];
	temp[4][1][0] = arr[3][1][0];
	temp[4][2][0] = arr[3][2][0];

	temp[1][0][0] = arr[4][0][0];
	temp[1][1][0] = arr[4][1][0];
	temp[1][2][0] = arr[4][2][0];
	set(temp);
}

void RubiksCube::topAntiClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[0][0][1] = arr[0][1][0];
	temp[0][1][0] = arr[0][2][1];
	temp[0][2][1] = arr[0][1][2];
	temp[0][1][2] = arr[0][0][1];

	temp[0][0][0] = arr[0][2][0];
	temp[0][2][0] = arr[0][2][2];
	temp[0][2][2] = arr[0][0][2];
	temp[0][0][2] = arr[0][0][0];

	temp[2][0][0] = arr[3][0][0];
	temp[2][1][0] = arr[3][1][0];
	temp[2][2][0] = arr[3][2][0];

	temp[3][0][0] = arr[4][0][0];
	temp[3][1][0] = arr[4][1][0];
	temp[3][2][0] = arr[4][2][0];

	temp[4][0][0] = arr[1][0][0];
	temp[4][1][0] = arr[1][1][0];
	temp[4][2][0] = arr[1][2][0];

	temp[1][0][0] = arr[2][0][0];
	temp[1][1][0] = arr[2][1][0];
	temp[1][2][0] = arr[2][2][0];
	set(temp);
}

void RubiksCube::leftClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[2][0][1] = arr[2][1][0];
	temp[2][1][0] = arr[2][2][1];
	temp[2][2][1] = arr[2][1][2];
	temp[2][1][2] = arr[2][0][1];

	temp[2][0][0] = arr[2][2][0];
	temp[2][2][0] = arr[2][2][2];
	temp[2][2][2] = arr[2][0][2];
	temp[2][0][2] = arr[2][0][0];

	temp[0][0][0] = arr[3][0][0];
	temp[0][1][0] = arr[3][1][0];
	temp[0][2][0] = arr[3][2][0];

	temp[3][0][0] = arr[5][0][0];
	temp[3][1][0] = arr[5][1][0];
	temp[3][2][0] = arr[5][2][0];

	temp[5][0][0] = arr[1][0][0];
	temp[5][1][0] = arr[1][1][0];
	temp[5][2][0] = arr[1][2][0];

	temp[1][0][0] = arr[0][0][0];
	temp[1][1][0] = arr[0][1][0];
	temp[1][2][0] = arr[0][2][0];
	set(temp);
}

void RubiksCube::leftAntiClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[2][0][1] = arr[2][1][2];
	temp[2][1][0] = arr[2][0][1];
	temp[2][2][1] = arr[2][1][0];
	temp[2][1][2] = arr[2][2][1];

	temp[2][0][0] = arr[2][0][2];
	temp[2][2][0] = arr[2][0][0];
	temp[2][2][2] = arr[2][2][0];
	temp[2][0][2] = arr[2][2][2];

	temp[0][0][0] = arr[1][0][0];
	temp[0][1][0] = arr[1][1][0];
	temp[0][2][0] = arr[1][2][0];

	temp[3][0][0] = arr[0][0][0];
	temp[3][1][0] = arr[0][1][0];
	temp[3][2][0] = arr[0][2][0];

	temp[5][0][0] = arr[3][0][0];
	temp[5][1][0] = arr[3][1][0];
	temp[5][2][0] = arr[3][2][0];

	temp[1][0][0] = arr[5][0][0];
	temp[1][1][0] = arr[5][1][0];
	temp[1][2][0] = arr[5][2][0];
	set(temp);
}

void RubiksCube::bottomClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[5][0][1] = arr[5][1][0];
	temp[5][1][0] = arr[5][2][1];
	temp[5][2][1] = arr[5][1][2];
	temp[5][1][2] = arr[5][0][1];

	temp[5][0][0] = arr[5][2][0];
	temp[5][2][0] = arr[5][2][2];
	temp[5][2][2] = arr[5][0][2];
	temp[5][0][2] = arr[5][0][0];

	temp[2][0][2] = arr[3][0][2];
	temp[2][1][2] = arr[3][1][2];
	temp[2][2][2] = arr[3][2][2];

	temp[3][0][2] = arr[4][0][2];
	temp[3][1][2] = arr[4][1][2];
	temp[3][2][2] = arr[4][2][2];

	temp[4][0][2] = arr[1][0][2];
	temp[4][1][2] = arr[1][1][2];
	temp[4][2][2] = arr[1][2][2];

	temp[1][0][2] = arr[2][0][2];
	temp[1][1][2] = arr[2][1][2];
	temp[1][2][2] = arr[2][2][2];
	set(temp);
}

void RubiksCube::bottomAntiClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[5][0][1] = arr[5][1][2];
	temp[5][1][0] = arr[5][0][1];
	temp[5][2][1] = arr[5][1][0];
	temp[5][1][2] = arr[5][2][1];

	temp[5][0][0] = arr[5][0][2];
	temp[5][2][0] = arr[5][0][0];
	temp[5][2][2] = arr[5][2][0];
	temp[5][0][2] = arr[5][2][2];

	temp[2][0][2] = arr[1][0][2];
	temp[2][1][2] = arr[1][1][2];
	temp[2][2][2] = arr[1][2][2];

	temp[3][0][2] = arr[2][0][2];
	temp[3][1][2] = arr[2][1][2];
	temp[3][2][2] = arr[2][2][2];

	temp[4][0][2] = arr[3][0][2];
	temp[4][1][2] = arr[3][1][2];
	temp[4][2][2] = arr[3][2][2];

	temp[1][0][2] = arr[4][0][2];
	temp[1][1][2] = arr[4][1][2];
	temp[1][2][2] = arr[4][2][2];
	set(temp);
}

void RubiksCube::frontClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[1][0][1] = arr[1][1][2];
	temp[1][1][0] = arr[1][0][1];
	temp[1][2][1] = arr[1][1][0];
	temp[1][1][2] = arr[1][2][1];

	temp[1][0][0] = arr[1][0][2];
	temp[1][2][0] = arr[1][0][0];
	temp[1][2][2] = arr[1][2][0];
	temp[1][0][2] = arr[1][2][2];

	temp[0][0][2] = arr[2][0][2];
	temp[0][1][2] = arr[2][1][2];
	temp[0][2][2] = arr[2][2][2];

	temp[4][0][2] = arr[0][0][2];
	temp[4][1][2] = arr[0][1][2];
	temp[4][2][2] = arr[0][2][2];

	temp[5][0][2] = arr[4][0][2];
	temp[5][1][2] = arr[4][1][2];
	temp[5][2][2] = arr[4][2][2];

	temp[2][0][2] = arr[5][0][2];
	temp[2][1][2] = arr[5][1][2];
	temp[2][2][2] = arr[5][2][2];
	set(temp);
}

void RubiksCube::frontAntiClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[1][0][1] = arr[1][1][0];
	temp[1][1][0] = arr[1][2][1];
	temp[1][2][1] = arr[1][1][2];
	temp[1][1][2] = arr[1][0][1];

	temp[1][0][0] = arr[1][2][0];
	temp[1][2][0] = arr[1][2][2];
	temp[1][2][2] = arr[1][0][2];
	temp[1][0][2] = arr[1][0][0];

	temp[5][0][2] = arr[2][0][2];
	temp[5][1][2] = arr[2][1][2];
	temp[5][2][2] = arr[2][2][2];

	temp[2][0][2] = arr[0][0][2];
	temp[2][1][2] = arr[0][1][2];
	temp[2][2][2] = arr[0][2][2];

	temp[0][0][2] = arr[4][0][2];
	temp[0][1][2] = arr[4][1][2];
	temp[0][2][2] = arr[4][2][2];

	temp[4][0][2] = arr[5][0][2];
	temp[4][1][2] = arr[5][1][2];
	temp[4][2][2] = arr[5][2][2];
	set(temp);
}

void RubiksCube::backClock()
{
	Int3DVector temp;
	temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = this->arr[i][j][k];
			}
		}
	}

	temp[3][0][1] = this->arr[3][1][0];
	temp[3][1][0] = this->arr[3][2][1];
	temp[3][2][1] = this->arr[3][1][2];
	temp[3][1][2] = this->arr[3][0][1];
	temp[3][0][0] = this->arr[3][2][0];
	temp[3][2][0] = this->arr[3][2][2];
	temp[3][2][2] = this->arr[3][0][2];
	temp[3][0][2] = this->arr[3][0][0];

	temp[5][0][0] = this->arr[2][0][0];
	temp[5][1][0] = this->arr[2][1][0];
	temp[5][2][0] = this->arr[2][2][0];

	temp[2][0][0] = this->arr[0][0][0];
	temp[2][1][0] = this->arr[0][1][0];
	temp[2][2][0] = this->arr[0][2][0];

	temp[0][0][0] = this->arr[4][0][0];
	temp[0][1][0] = this->arr[4][1][0];
	temp[0][2][0] = this->arr[4][2][0];

	temp[4][0][0] = this->arr[5][0][0];
	temp[4][1][0] = this->arr[5][1][0];
	temp[4][2][0] = this->arr[5][2][0];
	set(temp);
}

void RubiksCube::backAntiClock()
{
	Int3DVector temp = vector<vector<vector<int>>>(6, vector<vector<int>>(3, vector<int>(3)));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = arr[i][j][k];
			}
		}
	}

	temp[3][0][1] = arr[3][1][2];
	temp[3][1][0] = arr[3][0][1];
	temp[3][2][1] = arr[3][1][0];
	temp[3][1][2] = arr[3][2][1];

	temp[3][0][0] = arr[3][0][2];
	temp[3][2][0] = arr[3][0][0];
	temp[3][2][2] = arr[3][2][0];
	temp[3][0][2] = arr[3][2][2];

	temp[0][0][0] = arr[2][0][0];
	temp[0][1][0] = arr[2][1][0];
	temp[0][2][0] = arr[2][2][0];

	temp[4][0][0] = arr[0][0][0];
	temp[4][1][0] = arr[0][1][0];
	temp[4][2][0] = arr[0][2][0];

	temp[5][0][0] = arr[4][0][0];
	temp[5][1][0] = arr[4][1][0];
	temp[5][2][0] = arr[4][2][0];

	temp[2][0][0] = arr[5][0][0];
	temp[2][1][0] = arr[5][1][0];
	temp[2][2][0] = arr[5][2][0];
	set(temp);
}

void RubiksCube::rotate(int face, int direction)
{
	switch (face)
	{
	case 1:
		if (direction == 1)
		{
			topClock();
		}
		else
		{
			topAntiClock();
		}
		break;
	case 2:
		if (direction == 1)
		{
			bottomClock();
		}
		else
		{
			bottomAntiClock();
		}
		break;
	case 3:
		if (direction == 1)
		{
			frontClock();
		}
		else
		{
			frontAntiClock();
		}
		break;
	case 4:
		if (direction == 1)
		{
			backClock();
		}
		else
		{
			backAntiClock();
		}
		break;
	case 5:
		if (direction == 1)
		{
			leftClock();
		}
		else
		{
			leftAntiClock();
		}
		break;
	case 6:
		if (direction == 1)
		{
			rightClock();
		}
		else
		{
			rightAntiClock();
		}
		break;
	}
}

void RubiksCube::printFront()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[1][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void RubiksCube::printBack()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[3][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void RubiksCube::printLeft()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[2][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void RubiksCube::printRight()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[4][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void RubiksCube::printTop()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[0][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void RubiksCube::printBottom()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[5][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool RubiksCube::ellenoriz()
{
	int db = 0;
	for (int i = 0; i < 6; i++)
	{
		int osszeg = 0;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				osszeg += arr[i][j][k];
			}
		}
		if (osszeg == 4)
		{
			db++;
		}
	}
	return (db == 3);
}
int main()
{
	mt19937 rng;
	rng.seed(random_device{}());
	uniform_int_distribution<int> dist(0, 5);
	uniform_int_distribution<int> dist2(0, 1);
	int face, direction;
	double iteraciok = 10000000;
	int k = 10;
	cout << "k= " << k << endl;
	int db = 0;
	RubiksCube kocka;
	for (int i = 0; i < iteraciok; i++)
	{
		kocka.reset();
		for (int j = 0; j < k; j++)
		{
			face = dist(rng);
			direction = dist2(rng);
			kocka.rotate(face, direction);
		}
		if (kocka.ellenoriz())
		{
			db++;
		}
	}
	double eredmeny = (double)db;
	double it = iteraciok;
	eredmeny /= it;
	cout << fixed << setprecision(4);
	cout << eredmeny << endl;
	return 0;
}