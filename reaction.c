/* reaction.c -  The program waits for a random interval of time and then prints a single digit
 on the screen. The user has to respond by typing that digit as quickly as possible. 
 The program records how long it takes the user to respond. Performs for 10 such tests and report 
 the minimum, maximum, and average response time
 *    
 */

#include	<stdio.h>
//#include	<sys/time.h>
#include    <stdlib.h>
//#define _USE_32BIT_TIME_T 1
#include    <time.h>


// ensures no error in getting time of day 
timeerr(int status)
{
	if (status != 0)
	{
		printf("Error getting time of day in seconds");
		exit(1);
	}
}


main()
{
	
	
	/*
time_t start_t, end_t;
   double diff_t;

   printf("Starting of the program...\n");
   time(&start_t);

   printf("Sleeping for 5 seconds...\n");
   sleep(5);

   time(&end_t);
   diff_t = difftime(end_t, start_t);

   printf("Execution time = %f\n", diff_t);
   printf("Exiting of the program...\n");

   return(0);
	
	*/
	
	
	
	
	
	
	
	time_t responseTime;
	time_t startTime;
	//suseconds_t responseTime;  microseconds
	//suseconds_t startTime;     microseconds
	int randomTime, validTime, input;
	int output = 1;
	int iteration = 0;
	double seconds;
	double fastestTime; 
	double slowestTime;
	srand(time(NULL));
	
	printf("Reaction Test Beginning imitate int on screen as fast as you can...\n");

	while (iteration < 11 )
	{
		randomTime = rand() % 10;
		output = rand() % 40;
		
		if (iteration != 0)
			printf("Accepted... Get Ready\n");
		
		
		
		sleep(randomTime);   // pause for random time before displaying digit
		printf("%d\n", output);
		//time(&startTime);
		validTime = gettimeofday(&startTime,NULL);
		timeerr(validTime);  //error check
		scanf("%d",&input);
		
		while(input != output)
			{
			printf("Ooops you entered the wrong digit.  Try again.\n");
			scanf("%d",&input);
		
			}
	
		//time(&responseTime);
		validTime = gettimeofday(&responseTime,NULL);
		timeerr(validTime);
		//printf("Start Time is %f\n", startTime);
		//printf("Response Time is %f\n",responseTime);
		
		seconds = difftime(responseTime,startTime);  // compute difference between start and end time
		//printf("Difference is %f",seconds);  
		if (seconds > fastestTime)  // if fastest time record it
			fastestTime = seconds;
			//printf("%d\n",fastestTime);  // DEBUG
		if (seconds < slowestTime)   // if slowest time record it
			slowestTime = seconds;
		++iteration;
	
	}
	
	printf("Your slowest reaction time in seconds was %f\n", fastestTime);
	printf("Your fastest reaction time in seconds was %f\n", slowestTime);
	
	
}



