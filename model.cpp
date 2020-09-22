#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdlib.h> 
#include <time.h> 

using namespace std;


int main()
{
	srand (time(NULL));

	for (int MAX = 100; MAX < 1001; MAX+= 100)
	{
		cout << MAX<<",";
		double A[MAX][MAX], x[MAX], y[MAX];
		int i, j;
		float t0,t1, tiempo;

		for (i = 0;i < MAX;i++)
			for (j= 0; j < MAX; j++)
				A[i][j] = rand() % 1000 + 1;

		for (i = 0;i < MAX;i++)
		{
			y[i] = rand() % 1000 + 1;
			x[i] = rand() % 1000 + 1;
		}


		t0 = clock();    
		for (i = 0;i < MAX;i++)
			for (j= 0; j < MAX; j++)
				y[i] += A[i][j] * x[j];

	    t1 = clock();
	    tiempo = ((t1-t0)/CLOCKS_PER_SEC);
	    cout << tiempo << ",";

	    t0 = clock();
		for (j = 0; j < MAX; j++)
			for (i = 0; i < MAX; i++)
				y[i] += A[i][j]* x[j];

		t1 = clock();
	    tiempo = ((t1-t0)/CLOCKS_PER_SEC);
	    cout << tiempo << endl;
	}

	return 0;	
}