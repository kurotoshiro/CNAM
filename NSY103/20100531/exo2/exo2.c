/*
 * Faire un clone de la commande cp
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

  int fd_in,fd_out;
  ssize_t chr_read,chr_write;
  char buffer[BUFFSIZE];

  if(argc<=2) {
    perror("Vous devez fournir un fichier source et un fichier destination en argument.\n");
    return EXIT_FAILURE;
  }

  fd_in=open(argv[1],O_RDONLY);
  fd_out=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU|S_IRGRP|S_IROTH);
  if(fd_in==-1 || fd_out==-1) {
    perror("Impossible d'ouvrir le fichier source ou destination.\n");
    return EXIT_FAILURE;
  }

  while((chr_read=read(fd_in,buffer,BUFFSIZE))!=0) {
    /* write chr_read et pas BUFFSIZE,
     * car sur la dernière lecture il y a peut etre moins que BUFFSIZE */
    write(fd_out,buffer,chr_read);
  }

  close(fd_in);
  close(fd_out);

  return EXIT_SUCCESS;
}
