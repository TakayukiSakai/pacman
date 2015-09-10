#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <sys/fcntl.h>

void main() {
  int fd;
  char buf[256];

  if(mkfifo("/tmp/FifoTest",0666)==-1){
    perror("mkfifo");
    /* 死にはしない */
  }
  
  if((fd=open("/tmp/FifoTest",O_WRONLY))==-1){
    perror("open");
    exit(-1);
  }

  while(1){
    fgets(buf,sizeof(buf)-1,stdin);
    if(feof(stdin)){
      break;
    }
    write(fd,buf,strlen(buf));
  }
  close(fd);
}
