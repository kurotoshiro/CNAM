#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {

  int fd;
  int i;
  int ret;
  char arg[argc];
  pid_t pid;

  if(argc<2) {
    perror("Vous devez donner un programme en argument.");
    return EXIT_FAILURE;
  }

  pid=fork();

  if(pid==0) {
    fd=open("/dev/null",O_WRONLY);
    if(fd==-1) {
      perror("Impossible d'ouvrir le fichier.");
      return EXIT_FAILURE;
    }

    dup2(3,1);

    execlp(argv[1],argv[2],NULL);
    return EXIT_FAILURE;
  }

  wait(&ret);
  printf("%d\n",WEXITSTATUS(ret));
  if(WEXITSTATUS(ret)) {
    printf("ERREUR\n");
  }
  else {
    printf("OK\n");
  }

  return EXIT_SUCCESS;
}
