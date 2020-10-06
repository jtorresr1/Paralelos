#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "timer.h"


long thread_count;
long long n;
double sum;
pthread_mutex_t mutex;


void* Thread_sum(void* rank) {
   long my_rank = (long) rank;
   double factor;
   long long i;
   long long my_n = n/thread_count;
   long long my_first_i = my_n*my_rank;
   long long my_last_i = my_first_i + my_n;
   double my_sum = 0.0;

   if (my_first_i % 2 == 0) factor = 1.0;
   else factor = -1.0;

   for (i = my_first_i; i < my_last_i; i++, factor = -factor) my_sum += factor/(2*i+1);
   pthread_mutex_lock(&mutex);
   sum += my_sum;
   pthread_mutex_unlock(&mutex);
   return NULL;
}


int main(int argc, char* argv[]) {
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
      pthread_mutex_init(&mutex, NULL);
      sum = 0.0;

      GET_TIME(start);
      for (thread = 0; thread < thread_count; thread++)  
         pthread_create(&thread_handles[thread], NULL,
             Thread_sum, (void*)thread);  

      for (thread = 0; thread < thread_count; thread++) 
         pthread_join(thread_handles[thread], NULL); 
      GET_TIME(finish);
      elapsed = finish - start;
      sum = 4.0*sum;
      printf("   %ld \t %e  \n", thread_count, elapsed);
      pthread_mutex_destroy(&mutex);
      val_start *= 2.0;
      free(thread_handles);
   }

   return 0;
}

