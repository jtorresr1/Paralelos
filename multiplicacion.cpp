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
	for (int MAX = 50; MAX < 1001; MAX+= 50)
	{
		cout << MAX<<",";
		int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

		for (int i = 0;i < MAX;i++)
		{
			for (int  j= 0; j < MAX; j++)
			{
				A[i][j] = rand() % 1000 + 1;
				B[i][j] = rand() % 1000 + 1;
				C[i][j] = 0;
			}
		}

		float t0,t1, tiempo;
		t0 = clock();
		for(int i=0; i<MAX; ++i)
		{
	        for(int j=0; j<MAX; ++j)
	        {
	            for(int z=0; z<MAX; ++z)
	            {
	                C[i][j] += A[i][z] * B[z][j];
	            }
	        }
		}
		t1 = clock();
	    tiempo = ((t1-t0)/CLOCKS_PER_SEC);
	    cout << tiempo << endl;
    }
	return 0;
}