#include <iostream>
using namespace std;

void printSpiral(int size)
{

	// Create row and col
	// to traverse rows and columns
	int row = 0, col = 0;

	int boundary = size - 1;
	int sizeLeft = size - 1;
	int flag = 1;

	// Variable to determine the movement
	// r = right, l = left, d = down, u = upper
	char move = 'r';

	// Array for matrix
	int matrix[size][size] = {0};

	for (int i = 1; i < size * size + 1; i++)
	{

		// Assign the value
		matrix[row][col] = i;

		// switch-case to determine the next index
		switch (move)
		{

			// If right, go right
			case 'r':
				col += 1;
				break;
	
			// if left, go left
			case 'l':
				col -= 1;
				break;
	
			// if up, go up
			case 'u':
				row -= 1;
				break;
	
			// if down, go down
			case 'd':
				row += 1;
				break;
		}

		// Check if the matrix
		// has reached array boundary
		if (i == boundary)
		{

			// Add the left size for the next boundary
			boundary += sizeLeft;

			// If 2 rotations has been made,
			// decrease the size left by 1
			if (flag != 2)
			{

				flag = 2;
			}
			else
			{

				flag = 1;
				sizeLeft -= 1;
			}

			// switch-case to rotate the movement
			switch (move)
			{

				// if right, rotate to down
				case 'r':
					move = 'd';
					break;
	
				// if down, rotate to left
				case 'd':
					move = 'l';
					break;
	
				// if left, rotate to up
				case 'l':
					move = 'u';
					break;
	
				// if up, rotate to right
				case 'u':
					move = 'r';
					break;
			}
		}
	}
    int sum =0;
	// Print the matrix
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
            if(row==col or (row+col==size-1)) sum+=matrix[row][col];
			
		}

		cout << endl;
	}
    cout<<sum;
}

// Driver Code
int main()
{

	int digs[10] = {4,3,3,5,4,4,3,5,5,4};
    int sum =0;
    for(int i=1;i<=600;i++){
        int x = i;
        while(x>0){
            sum+=digs[x%10];
            x/=10;
        }
    }
    cout<<sum;
	return 0;
}

// This code is contributed by 29AjayKumar
