
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int pipes[2];
  ssize_t chr_read,chr_write;
  char c;
  pid_t pid;

  // Fils lit stdin
  // Pere lit sortie du tube et toupper() les char
  pipe(pipes);
  pid=fork();
  if(pid==0) {
    // lire stdin et ecrire dans pipe
    dup2(pipes[1],1);
    close(pipes[0]);
    while((scanf("%c",&c)!=0)) {
      write(pipes[1],&c,1);
    }
  }
  else {
    // lire dans pipe et ecrire dans stdout toupper()
    dup2(pipes[0],0);
    close(pipes[1]);
    while((read(pipes[0],&c,1))!=0) {
      printf("%c",toupper(c));
    }
  }

  return EXIT_SUCCESS;
}
