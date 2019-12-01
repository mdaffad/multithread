#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h> 
#include <time.h> 
#include <unistd.h>
long prime = 0;
long prime2 = 0;
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
	clock_t start_time, end_time;
	pthread_t tid1;
	if (thread1.start > 1)
	{
		prime++;
		
		start_time = clock();
		pthread_create(&tid1, NULL, getPrime, (void *) &thread1);
		pthread_join(tid1, NULL);
		end_time = clock();
	}
	double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
	/*end count time*/
	prime = prime + prime2;
	printf("prime : %ld\n", prime);
	printf("time : %f\n", cpu_time_used);
	pthread_exit(NULL); 
	return 0;
}
