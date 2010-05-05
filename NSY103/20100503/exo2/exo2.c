/*
 * Exercice 2 - Ecrire un programme lançant la commande 'ls -l /tmp'
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // On affiche un message
  printf("Lancement de la commande : ls -l /tmp\n");

  // On remplace notre programme par la commande ls
  execlp("ls","ls","-l","/tmp",(char *) NULL);

  // En cas de succè ce code n'est pas executé
  // On est donc en présence d'une erreur
  perror("Impossible de lancer la commande : ls -l /tmp");

  // Impossible de lancer 'ls', on quitte en retournant l'erreur
  return EXIT_FAILURE;
}
