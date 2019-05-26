#include <stdio.h>
#include <time.h>
#include <omp.h>

int main(int argc, char *argn[])
{
	
	long sum=0;
	#pragma omp parallel num_threads(4)
	{
		double starttime,endtime;
		
		int i = omp_get_thread_num();
		
		starttime = omp_get_wtime();
		
		int j;
		#pragma omp for
		for(j=1; j<=1000000; j++)
			#pragma omp atomic        
			sum+=j;
		
		endtime = omp_get_wtime();
		
		printf("thread [%d] time is : %f \n", i,endtime-starttime);
		printf("Sum of 1~1000000 =  %ld  \n",sum);
		
	}
}
