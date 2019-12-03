#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h> 
#include <sys/time.h> 
long prime = 0;
long prime2 = 0;
long prime3 = 0;
long prime4 = 0;
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
	for (j = copy_start; j <= check; j = j + 8)
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
		};
	}
	return NULL;
}
void *getPrime2 (void *input)
{
	unsigned long j, i, numsqrt, check;
	int copy_start;
	copy_start = ((struct numbers *) input)->start;
	check = ((struct numbers *) input)->end;
	int true;
	// start_num += 
	for (j = copy_start; j <= check; j = j + 8)
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
			prime2++;
		}
	}
	return NULL;
}

void *getPrime3 (void *input)
{
	unsigned long j, i, numsqrt, check;
	int copy_start;
	copy_start = ((struct numbers *) input)->start;
	check = ((struct numbers *) input)->end;
	int true; 
	for (j = copy_start; j <= check; j = j + 8)
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
			prime3++;
		}
	}
	return NULL;
}
void *getPrime4 (void *input)
{
	unsigned long j, i, numsqrt, check;
	int copy_start;
	copy_start = ((struct numbers *) input)->start;
	check = ((struct numbers *) input)->end;
	int true;
	// start_num += 
	for (j = copy_start; j <= check; j = j + 8)
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
			prime4++;
		}
	}
	return NULL;
}

int main()
{
	struct numbers thread1;
	struct numbers thread2;

	/*start count time*/
	unsigned long end = 10000000;
	thread1.start = 3;
	thread1.end = end;
	thread2.start = 5;
	thread2.end = end;
	struct timespec start_time, end_time;
	pthread_t tid1, tid2, tid3, tid4;
	if (thread1.start > 1)
	{
		prime++;
		
		clock_gettime(CLOCK_MONOTONIC, &start_time); 
		pthread_create(&tid1, NULL, getPrime, (void *) &thread1);
		pthread_create(&tid2, NULL, getPrime2, (void *) &thread2);
		pthread_create(&tid3, NULL, getPrime2, (void *) &thread2);
		pthread_create(&tid4, NULL, getPrime2, (void *) &thread2);
		pthread_join(tid1, NULL);
		pthread_join(tid2, NULL);
		pthread_join(tid3, NULL);
		pthread_join(tid4, NULL);
	}
	clock_gettime(CLOCK_MONOTONIC, &end_time); 
	double cpu_time_used;
	cpu_time_used = (end_time.tv_sec - start_time.tv_sec) * 1e9; 
    cpu_time_used = (cpu_time_used + (end_time.tv_nsec - start_time.tv_nsec)) * 1e-9; 
	
	/*end count time*/
	prime = prime + prime2+ prime3 + prime4;
	printf("prime : %ld\n", prime);
	printf("time : %.10f\n", cpu_time_used);
	pthread_exit(NULL); 
	return 0;
}
