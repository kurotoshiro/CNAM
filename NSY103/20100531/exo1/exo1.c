/*
 * Faire un clone de la commande cat
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 512

int main(int argc, char *argv[]) {

  int fd;
  ssize_t chr_read;
  char buffer[BUFFSIZE];
  int i=0;

  if(argc<=1) {
    perror("Vous devez fournir au moins un fichier en argument.\n");
    return EXIT_FAILURE;
  }

  for(i=1;i<argc;i++) {
    fd=open(argv[i],O_RDONLY);
    if(fd==-1) {
      perror("Impossible d'ouvrir le fichier.\n");
      return EXIT_FAILURE;
    }
  
    while((chr_read=read(fd,buffer,BUFFSIZE))!=0) {
      /* write chr_read et pas BUFFSIZE,
       * car sur la dernière lecture il y a peut etre moins que BUFFSIZE */
      write(STDOUT_FILENO,buffer,chr_read);
    }
  
    close(fd);
  }

  return EXIT_SUCCESS;
}
