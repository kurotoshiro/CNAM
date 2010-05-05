/*
 * Exercice 3 - Ecrire un programme lançant la commande 'ls' puis 'who' et enfin 'date'
 *
 * Comme exec() remplace notre processus, il va falloir utiliser fork()
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  pid_t pid;

  // Pour chaque commande on va répéter ce bloque de code
  pid=fork();
  switch(pid) {
    case -1:
      perror("Impossible de faire un fork du processus");
      return EXIT_FAILURE;
      break;
    case 0:
      // On affiche un message
      printf("Lancement de la commande : ls\n");
      // On remplace notre programme par la commande ls
      execlp("ls","ls",(char *) NULL);
      // En cas de succè ce code n'est pas executé
      // On est donc en présence d'une erreur
      perror("Impossible de lancer la commande : ls");
      // Impossible de lancer 'ls', on quitte en retournant l'erreur
      return EXIT_FAILURE;
  }
  wait(); // On attends que le fils se termine

  // Pour chaque commande on va répéter ce bloque de code
  pid=fork();
  switch(pid) {
    case -1:
      perror("Impossible de faire un fork du processus");
      return EXIT_FAILURE;
      break;
    case 0:
      // On affiche un message
      printf("Lancement de la commande : who\n");
      // On remplace notre programme par la commande ls
      execlp("who","who",(char *) NULL);
      // En cas de succè ce code n'est pas executé
      // On est donc en présence d'une erreur
      perror("Impossible de lancer la commande : who");
      // Impossible de lancer 'ls', on quitte en retournant l'erreur
      return EXIT_FAILURE;
  }
  wait(); // On attends que le fils se termine

  // Pour chaque commande on va répéter ce bloque de code
  pid=fork();
  switch(pid) {
    case -1:
      perror("Impossible de faire un fork du processus");
      return EXIT_FAILURE;
      break;
    case 0:
      // On affiche un message
      printf("Lancement de la commande : date\n");
      // On remplace notre programme par la commande ls
      execlp("date","date",(char *) NULL);
      // En cas de succè ce code n'est pas executé
      // On est donc en présence d'une erreur
      perror("Impossible de lancer la commande : date");
      // Impossible de lancer 'ls', on quitte en retournant l'erreur
      return EXIT_FAILURE;
  }
  wait(); // On attends que le fils se termine


  // Chaque enfant a executé une commande et le processus père a fini son travail avec succès
  return EXIT_SUCCESS;
}
