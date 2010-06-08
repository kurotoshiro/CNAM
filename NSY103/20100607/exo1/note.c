

int main(){
  int tableau_fd[2]; // Tableau de int
  pipe(tableau_fd); // Tableau de fd, [0] en O_RONLY
                    //              , [1] en O_WRONLY
                    //              , ecrit dans [1]
                    //              , apparait dans [0] (impossible de lire tant que pas ecrit dans [1]
  dup2(tableau_fd[1],1); // du processus ecrivain/generateur
  dup2(tableau_fd[0],0); // du processus lecteur/consommateur

  close(tableau_fd[0]); // Dans le processus ecrivain
  close(tableau_fd[1]); // Dans le processus lecteur

  write(tableau_fd[1],"coucou\n",7); // On doit ecrire pour pouvoir lire
  read(tableau_fd[0],buffer,20); // On doit lire, pour pouvoir à nouveau ecrire

  // Penser à close(tableau_fd[0] dans le process qui ecrit dans [1]
  // Penser à close(tableau_fd[1] dans le process qui lit dans [0]
}
