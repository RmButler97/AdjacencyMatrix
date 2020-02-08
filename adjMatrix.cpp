// Ryan Butler
// This program will create an adjacency matrix from given array-pointer representation

#include <iostream>
using namespace std;

int main()
{
	// Declare variables
    // Number of nodes and rows
	int n, r;
    // Rows and columns of adjacency matrix
	int row, col, next;
    // Degree of nodes
	int degree;
    // Array-pointer representation stored in array
	int ap[20][2];
    // Adjacency matrix
	int am[20][20];
    // Array to hold isolated nodes if any exist
	int iso[20];
	
	
	// Get user input
	cout << "Input number of nodes: ";
	cin >> n;
	cout << "Input number of rows in matrix: ";
	cin >> r;
	cout << "Enter array-pointer representation of the graph:" << endl;
	for (int a = 0; a < r; a++)
	{
		for (int b = 0; b < 2; b++)
		{
			cin >> ap[a][b];
		}
	}
	
	// Traverse array-pointer graph to find adjacencies
	for (int i = 0; i < n; i++)
	{
		if (ap[i][1] != -1)
		{
			row = ap[i][0] - 1;
			next = ap[i][1] - 1;
			do
			{
				col = ap[next][0] - 1;
				am[row][col] += 1;
				next = ap[next][1] - 1;
			}
			while (next != -1);
		}
		else
			iso[i] = i+1;
	}
	
	// Output adjacenty matrix
	cout << "Adjacency matrix is:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << am[i][j] << "\t";
		}
		cout << endl;
	}
	
	// Output isolated node
	cout << "Isolated nodes are:";
	for (int i = 0; i < n; i++)
	{
		if (iso[i] != 0)
		{
			cout << " " << iso[i];
		}
		else
			;
	}
	cout << endl;
	
	// Output degree of each node
	cout << "The degree of each node is:" << endl;
	for (int i = 0; i < n; i++)
	{
		degree = 0;
		for (int j = 0; j < n; j++)
		{
			if (am[i][j] != 0)
				degree += 1;
		}
        cout << i + 1 << ": " << degree << endl;
	}
	
	// Output nodes adjacent to each node
	cout << "The nodes adjacent to each node is:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ":";
		for (int j = 0; j < n; j++)
		{
			if (am[i][j] != 0)
				cout << " " << j + 1;
		}
		cout << endl;
	}
}


