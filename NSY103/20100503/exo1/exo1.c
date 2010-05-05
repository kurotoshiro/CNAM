/*
 * Exercice 1 - Ecrire un programme lançant la commande 'ls'
 *
 * On utilisera pour cela une fonction de la famille exec()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // On affiche un message
  printf("Lancement de la commande : ls\n");

  // On remplace notre programme par la commande ls
  execlp("ls","ls",(char *) NULL);

  // En cas de succèe ce code n'est pas executé
  // On est donc en présence d'une erreur
  perror("Impossible de lancer la commande : ls");

  // Impossible de lancer 'ls', on quitte en retournant l'erreur
  return EXIT_FAILURE;
}
