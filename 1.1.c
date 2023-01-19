#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <sys/resource.h>  //Including necessary header files


void *countA()   //CountA(first function) is made 
{
	for(long long int a = 0;a<pow(2,32);a++)
    {
    continue;
      //Blank loop only for counting...
    }
}

void *countB()   //CountB(first function) is made 
{
	for(long long int a = 0;a<pow(2,32);a++)
    {
     continue;
      //Blank loop only for counting...
    }
}

void *countC()   //CountC(first function) is made 
{
	for(long long int a = 0;a<pow(2,32);a++)
    {
     continue;
      //Blank loop only for counting...
    }
}


int main()
{
  pthread_t thrA;   //Creating Thread A
  pthread_t thrB;   //Creating Thread B
  pthread_t thrC;   //Creating Thread C
  struct sched_param sched;
	struct timespec starttime,endtime;  //For starting timeclock and ending the same

  FILE * f;
  f = fopen("time.txt","a");  //Opening a text file in append mode to note down the time

  printf("The following are the runtimes for threadA, threadB and threadC respectively :\n");
  
  clock_gettime( CLOCK_REALTIME, &starttime ); //Starting the clock for thrA
  pthread_create(&thrA, NULL, countA, NULL);
  pthread_create(&thrA, NULL, countB, NULL);
  pthread_create(&thrA, NULL, countC, NULL);
  pthread_setschedparam(thrA,SCHED_OTHER,&sched); //Sched_other as given in question
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime);//Ending the clock for thrA
  float temptime = ((double)(starttime.tv_nsec-endtime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 1(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before


  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrA,10); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
    if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 1(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before

  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrA,11); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 1(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before


  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrA,12); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 1(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before


  //NOW CARRYING OUT THE SAME THING REST OF THE THREADS
  clock_gettime(CLOCK_REALTIME, &starttime ); //Starting the clock for thrA
  pthread_create(&thrB, NULL, countA, NULL);
  pthread_create(&thrB, NULL, countB, NULL);
  pthread_create(&thrB, NULL, countC, NULL);
  pthread_setschedparam(thrB,SCHED_RR,&sched);   //Sched_rr as given in question
  pthread_join(thrB, NULL); //
  clock_gettime(CLOCK_REALTIME, &endtime ); //Ending the clock for thrA
  temptime = -((double)(starttime.tv_nsec-endtime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 2(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before


  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrB,10); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 2(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before

 
  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrB,11); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 2(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before


  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrB,12); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 2(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before



  clock_gettime(CLOCK_REALTIME, &starttime ); //Starting the clock for thrA
  pthread_create(&thrC, NULL, countA, NULL);
  pthread_create(&thrC, NULL, countB, NULL);
  pthread_create(&thrC, NULL, countC, NULL);
  pthread_setschedparam(thrC,SCHED_FIFO,&sched);  //Sched_fifo as given in question
  pthread_join(thrC, NULL);
  clock_gettime( CLOCK_REALTIME, &endtime ); //Ending the clock for thrA
  temptime = (double)(starttime.tv_nsec-endtime.tv_nsec);
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 3(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before

  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrC,10); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 3(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before

  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrC,11); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 3(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before

  clock_gettime( CLOCK_REALTIME, &starttime );
  pthread_setschedprio(thrC,12); //Changing priority to 10
  pthread_join(thrA, NULL); //Joining the thread
  clock_gettime( CLOCK_REALTIME, &endtime );//Ending the clock for thrA
  temptime = ((double)(endtime.tv_nsec-starttime.tv_nsec));
  if(temptime>10000 || temptime<-1000)
  {
    temptime=temptime/1000000;
  }
  if(temptime<0)
  {
    temptime=-temptime;
  }
  printf("Time Taken To Run Thread 3(in nanoseconds) : %f\n",temptime); //Printing as output
  fprintf(f," %f\n",temptime);//Printing in the time file we created before
    //Closing threads here.

  fclose(f);  //Closing the file here
  return 0;
  
}