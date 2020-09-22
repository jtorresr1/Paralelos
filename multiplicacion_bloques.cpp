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
	for (int MAX = 800; MAX < 801; MAX += 100)
	{
		cout << MAX<<",";
		int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

		for (int i = 0;i < MAX;i++)
		{
			for (int  j= 0; j < MAX; j++)
			{
				A[i][j] = rand() % 10000 + 1;
				B[i][j] = rand() % 10000 + 1;
				C[i][j] = 0;
			}
		}

		float t0,t1, tiempo;
		/*
		
		int step = MAX / 10;
		t0 = clock();		
		for(int i0=0; i0<MAX; i0+=step)
		{
	        for(int j0=0; j0<MAX; j0+=step)
	        {
	            for(int z0=0; z0<MAX; z0+=step)
	            {
	            	for (int i = i0; i < min(i0 + step, MAX); ++i)
	            	{
	            		for (int j = j0; j < min(j0 + step, MAX); ++j)
	            		{
	            			for (int k = z0; k < min(z0 + step, MAX); ++k)
	            			{
	            				C[i][j] += A[i][k] * B[k][j];
	            			}
	            		}
	            	}
	            }
	        }
		}
		t1 = clock();
	    tiempo = ((t1-t0)/CLOCKS_PER_SEC);
	    cout << tiempo << endl;//",";
*/

	    for (int i = 0;i < MAX;i++)
		{
			for (int  j= 0; j < MAX; j++)
			{
				// cout << C[i][j] << "\t";
				C[i][j] = 0;
			}
			//cout << endl;
		}

		t0 = clock();
		for(int i=0; i<MAX; ++i)
		{
	        for(int j=0; j<MAX; ++j)
	        {
	            for(int z=0; z<MAX; ++z)
	            {
	                C[i][j] += (A[i][z] * B[z][j]);
	            }
	        }
		}
		t1 = clock();
	    tiempo = ((t1-t0)/CLOCKS_PER_SEC);
	    cout << tiempo << endl;
	    /*
	    for (int i = 0;i < MAX;i++)
		{
			for (int  j= 0; j < MAX; j++)
			{
				cout << C[i][j] << "\t";
			}
			cout << endl;
		}
		*/
    }
	return 0;
}
