#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h> 
#include <sys/time.h>
long prime = 0;
int wait = 0;
struct numbers {
   int start;
   unsigned long end;
};
void *getPrime (void *input)
{
	unsigned long j, i, numsqrt, check;
	int copy_start;
	copy_start = ((struct numbers *) input)->start;
	check = ((struct numbers *) input)->end;
	int true;
	while (!wait)
	{

	}
	for (j = copy_start; j <= check; j = j + 2)
	{
		numsqrt = (unsigned long) (sqrt(j));
		true = 1;
		
		// mengecek apakah check bilangan prima atau bukan dengan
		// cara mengecek keterbagian dari 3 hingga akar(check) + 1
		for (i = 3; i <= numsqrt; i = i + 2)
		{
			if ((j % i) == 0)
			{
				true = 0;
				break;
			}
		}
		if (true)
		{
			prime++;
		}
	}
	wait = 0;
	return NULL;
}

int main()
{
	struct numbers thread1;

	/*start count time*/
	unsigned long end = 10000000;
	thread1.start = 3;
	thread1.end = end;
	struct timespec start_time, end_time;
	pthread_t tid1;
	pthread_create(&tid1, NULL, getPrime, (void *) &thread1);
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	wait = 1;
	if (thread1.start > 1)
	{
		prime++;
		while (wait)
		{
			// end_time = clock();
		}
	}
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	/*end count time*/
	double cpu_time_used;
	cpu_time_used = (end_time.tv_sec - start_time.tv_sec) * 1e9; 
    cpu_time_used = (cpu_time_used + (end_time.tv_nsec - start_time.tv_nsec)) * 1e-9; 
	
	printf("prime : %ld\n", prime);
	printf("time : %.10f\n", cpu_time_used);
	pthread_exit(NULL); 
	return 0;
}
