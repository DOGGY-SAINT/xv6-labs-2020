/*
*   2021.7.31
*   lab util exercise 1 sleep
*   created by Doggy_lee
*/
#include "kernel/types.h"   //not essential
#include "kernel/stat.h"    //not essential
#include "user/user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    fprintf(2, "usage: sleep tick_number...\n");
    exit(1);
  }
  for(i=1; i<argc; i++)
    sleep(atoi(argv[i]));
  exit(0);
}