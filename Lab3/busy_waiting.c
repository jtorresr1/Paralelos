#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "timer.h"

long thread_count;
long long n;
int flag;
double suma;


void* Thread_suma(void* rank) 
{
   long my_rank = (long) rank;
   double factor, my_suma = 0.0;
   long long i;
   long long my_n = n/thread_count;
   long long my_first_i = my_n*my_rank;
   long long my_last_i = my_first_i + my_n;

   if (my_first_i % 2 == 0) factor = 1.0;
   else factor = -1.0;

   for (i = my_first_i; i < my_last_i; i++, factor = -factor) my_suma += factor/(2*i+1);  
   
   while (flag != my_rank);
   suma += my_suma;  
   flag = (flag+1) % thread_count;
   return NULL;
} 


int main(int argc, char* argv[]) 
{
   long       thread;
   pthread_t* thread_handles;
   double start, finish, elapsed;
   int i;
   long val_start = 1.0;
   n = 1e8;
   for (i = 0; i < 7; ++i)
   {
      thread_count = val_start; 
      
      thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t)); 
      
      GET_TIME(start);
      suma = 0.0;
      flag = 0;
      for (thread = 0; thread < thread_count; thread++)  
         pthread_create(&thread_handles[thread], NULL, Thread_suma, (void*)thread);  

      for (thread = 0; thread < thread_count; thread++) 
         pthread_join(thread_handles[thread], NULL); 
      GET_TIME(finish);
      elapsed = finish - start;

      suma = 4.0*suma;
      printf("   %ld \t %e  \n", thread_count, elapsed);
      val_start *= 2.0;
      free(thread_handles);
   }

   return 0;
}
