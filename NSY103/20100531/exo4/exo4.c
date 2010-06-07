#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {

  int fd;
  int ret;
  pid_t pid;

  if(argc<2) {
    perror("Vous devez donner un programme en argument.");
    return EXIT_FAILURE;
  }

  pid=fork();

  if(pid==-1) {
    perror("Impossible de créer un processus fils.");
    return EXIT_FAILURE;
  }
  if(pid==0) {
    fd=open("/dev/null",O_WRONLY);
    if(fd==-1) {
      perror("Impossible d'ouvrir le fichier.");
      return EXIT_FAILURE;
    }

    // Ferme stdout et utilise 
    dup2(fd,1);
    dup2(fd,2);
    close(fd);

    // argv+1 ne decale pas la fin de argv, uniquement l'adresse de debut
    execvp(argv[1],argv + 1);
    perror("Le programme n'existe pas.");
    return EXIT_FAILURE;
  }

  wait(&ret);
  //printf("%d\n",WEXITSTATUS(ret));
  if(WEXITSTATUS(ret)) {
    printf("ERREUR\n");
  }
  else {
    printf("OK\n");
  }

  return EXIT_SUCCESS;
}
