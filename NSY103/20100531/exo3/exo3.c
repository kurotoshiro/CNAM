#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {

  int fd;

  fd=open("toto",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU|S_IRGRP|S_IROTH);
  if(fd==-1) {
    perror("Impossible d'ouvrir le fichier.");
    return EXIT_FAILURE;
  }

  dup2(3,1);

  execlp("ls","ls",NULL);
  
  return EXIT_SUCCESS;
}
