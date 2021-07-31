/*
*   2021.7.31
*   lab util exercise 2 pingpong
*   created by Doggy_lee
*/
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  
  int fd[2];
  pipe(fd);
  int *rfd=&fd[0],*wfd=&fd[1];
  uint8 wdata=0;
  uint8 rdata;

  
  int ci=fork();
  int i=getpid();
  
  if(0==ci)
  {
  close(*rfd);
  fprintf(2,"%d: received ping\n",i);
  write(*wfd,&wdata,8);
  }
  else
  {
  close(*wfd);
  read(*rfd,&rdata,8);
  fprintf(2,"%d: received pong\n",i);
  }
  
  exit(0);
}