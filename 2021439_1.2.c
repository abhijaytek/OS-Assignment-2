#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sched.h>
#include<sys/types.h>
#include<sys/stat.h>


//Including necessary header files


int r;
struct sched_param sched;



pid_t defa,pra1,pra2,pra3,defb,prb1,prb2,prb3,defc,prc1,prc2,prc3;
//For default process of A
double defaulta()
{
  clock_t time;    //Taking the time initially
  time=clock();
  defa=fork();      //Forking A
  if(defa==-1){   //Condition for error during fork
    printf("Error, No Child Process\n");
  }
  else if(defa==0)   //Successful fork
  {
    sched_setscheduler(defa, SCHED_OTHER,&sched);
    execlp("make","make",NULL);
  }
  waitpid(defa,&r,0);
  time=clock()-time;    //Noting the time here
  return (double)time;
}

double processa1(){
  clock_t time;
  time=clock();     //Taking the time initially
  pra1=fork();     //Forking A1
  if(pra1==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(pra1==0){
    sched.sched_priority=1;    
    
    sched_setscheduler(pra1, SCHED_OTHER,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(pra1,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}

double processa2(){
  clock_t time;
  time=clock();     //Taking the time initially
  pra2=fork();     //Forking A1
  if(pra2==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(pra2==0){
    sched.sched_priority=2;    
    
    sched_setscheduler(pra2,SCHED_OTHER,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(pra2,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}
double processa3(){
  clock_t time;
  time=clock();     //Taking the time initially
  pra3=fork();     //Forking A1
  if(pra3==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(pra3==0){
    sched.sched_priority=3;    
    
    sched_setscheduler(pra3,SCHED_OTHER,&sched);  //Scheduling priority Other
    execlp("make","make",NULL);
  }
  
  waitpid(pra3,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}
double defaultb(){
  clock_t time;    //Taking the time initially
  time=clock();
  defb=fork();      //Forking B
  if(defb==-1){   //Condition for error during fork
    printf("Error, No Child Process\n");
  }
  else if(defb==0)   //Successful fork
  {
    sched_setscheduler(defb, SCHED_RR,&sched);
    execlp("make","make",NULL);
  }
  waitpid(defb,&r,0);
  time=clock()-time;    //Noting the time here
  return (double)time;
}

double processb1(){
  clock_t time;
  time=clock();     //Taking the time initially
  prb1=fork();     //Forking A1
  if(prb1==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(prb1==0){
    sched.sched_priority=1;    
    
    sched_setscheduler(prb1,SCHED_RR,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(prb1,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}

double processb2(){
  clock_t time;
  time=clock();     //Taking the time initially
  prb2=fork();     //Forking A1
  if(prb2==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(prb2==0){
    sched.sched_priority=2;    
    
    sched_setscheduler(prb2,SCHED_RR,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(prb2,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}
double processb3(){
  clock_t time;
  time=clock();     //Taking the time initially
  prb3=fork();     //Forking A1
  if(prb3==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(prb3==0){
    sched.sched_priority=3;    
    
    sched_setscheduler(prb3,SCHED_RR,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(prb3,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}

double defaultc(){
  clock_t time;    //Taking the time initially
  time=clock();
  defc=fork();      //Forking A
  if(defc==-1){   //Condition for error during fork
    printf("Error, No Child Process\n");
  }
  else if(defc==0)   //Successful fork
  {
    sched_setscheduler(defc,SCHED_FIFO,&sched);
    execlp("make","make",NULL);
  }
  waitpid(defc,&r,0);
  time=clock()-time;    //Noting the time here
  return (double)time;
}


double processc1(){
  clock_t time;
  time=clock();     //Taking the time initially
  prc1=fork();     //Forking A1
  if(prc1==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(prc1==0){
    sched.sched_priority=1;    
    
    sched_setscheduler(prc1,SCHED_FIFO,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(prc1,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}

double processc2(){
  clock_t time;
  time=clock();     //Taking the time initially
  prc2=fork();     //Forking A1
  if(prc2==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(prc2==0){
    sched.sched_priority=2;    
    
    sched_setscheduler(prc2,SCHED_FIFO,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(prc2,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}

double processc3(){
  clock_t time;
  time=clock();     //Taking the time initially
  prc3=fork();     //Forking A1
  if(prc3==-1){    //Condition for error during fork
    printf("Unable to create a child procee\n");
  }
  else if(prc3==0){
    sched.sched_priority=3;    
    
    sched_setscheduler(prc3,SCHED_FIFO,&sched);  //Scheduling priority Other
    
    execlp("make","make",NULL);
    
  }
  
  waitpid(prc3,&r,0);
  
  time=clock()-time;    //Noting the time here
  if(time!=0)
  {
    //continue;
  }
  return (double)time;
}



//DONE WITH ALL SCHEDULING AND ALL PROCESSES
int main()

{

  //RETURNING DOUBLE VALUES OF ALL THE TIME THE PROCESS TOOK
  double a=defaulta();
  
  double a1=processa1();
  
  double a2=processa2();
  
  double a3=processa3();
  
  double b=defaultb();
  
  double b1=processb1();
  
  double b2=processb2();
  
  double b3=processb3();
  
  double c=defaultc();
  
  double c1=processc1();
  
  double c2=processc2();
  
  double c3=processc3();

  //PRINTING ALL OF GRAPHS ALONG WITH THE TIME :::::
  //PROCESS 1
  printf("FIRST PROCESS PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<a;i++){
    printf("*");
  }
  printf("%f\n",a);   //Printing the time :::

  printf("FIRST PROCESS WITH SCHEDULING 1 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<a1;i++){
    printf("*");
  }
  printf(" %f\n",a1);

  printf("FIRST PROCESS WITH SCHEDULING 2 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<a2;i++){
    printf("*");
  }
  printf(" %f\n",a2);

  printf("FIRST PROCESS WITH SCHEDULING 3 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<a3;i++){
    printf("*");
  }
  printf(" %f\n",a3);


  //PROCESS 2
  printf("SECOND PROCESS PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<b;i++){
    printf("*");
  }
  printf(" %f\n",b);

  printf("SECOND PROCESS WITH SCHEDULING 1 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<b1;i++){
    printf("*");
  }
  printf(" %f\n",b1);

  printf("SECOND PROCESS WITH SCHEDULING 2 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<b2;i++){
    printf("*");
  }
  printf(" %f\n",b2);

  printf("SECOND PROCESS WITH SCHEDULING 3 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<b3;i++){
    printf("*");
  }
  printf(" %f\n",b3);


  //PROCESS 3
  printf("THIRD PROCESS PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<c;i++){
    printf("*");
  }
  printf(" %f\n",c);

  printf("THIRD PROCESS WITH SCHEDULING 1 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<c1;i++){
    printf("*");
  }
  printf(" %f\n",c1);

  printf("THIRD PROCESS WITH SCHEDULING 2 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<c2;i++){
    printf("*");
  }
  printf(" %f\n",c2);

  printf("THIRD PROCESS WITH SCHEDULING 3 PRINTING STARS FOR GRAPH :\n");
  for(int i=0;i<c3;i++){
    printf("*");
  }
  printf(" %f\n",c3);

  return 0;
}