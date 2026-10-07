#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;


// gestionnaire du signal SIGPIPE - fonction du gestionnaire de signal
void gest_sigpipe(int s) {
  cout << "signal " << s << " reçu par le processus " << getpid() << endl;
}

int main(void) { // programme principal : le père
  int rf, p[2];

  pipe(p); // initialisation du pipe

  rf = fork(); // création du fils

  // Mise en place d'un gestionnaire pour le signal SIGPIPE.
  // Notons que cela est fait après le fork(), donc mis en place pour les 2 processus
  // Mais seul le père reçoit le signal
  struct sigaction act;
  sigaction(SIGPIPE, NULL, &act); // On récupére la structure sigaction actuelle pour SIGPIPE.
  // pour remplir la structure act : sigaction (le signal qui nous intéresse, NULL, &act)

  act.sa_handler = &gest_sigpipe; // On remplace dans act le gestionnaire de signal par le notre.
  // on met un pointeur vers la fonction utilisee dans le gestionnaire de signal mis en place
  
  sigaction(SIGPIPE, &act, NULL); // On installe le nouveau gestionnaire de signal.

  if(rf > 0){ // cas processus père

    cout << "(père) mon PID est " << getpid() << endl << flush;
    cout << "(père) le PID de mon fils est " << rf << endl << flush;
    close(p[0]);  // fermeture du décripteur en lecture
    int wr;
    for(int i = 1; i < 100; i++) {
      wr = write(p[1], &i, sizeof(int)); // écriture sur le pipe
      if(wr == -1) { // cas retour d'erreur du write
        cerr << "Erreur : " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
      }
    
      cout << "(père) " << i << endl << flush;
    }

    close(p[1]); // fermeture descripteur en écriture
    if(waitpid(rf, NULL, 0) == -1) { // gestion erreur sur waitpid
      cerr << "Erreur : " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    cout << "(père) terminaison normale." << endl << flush;
    
  }
  else { // cas processus fils
  
    cout << "(fils) mon PID est " << getpid() << endl << flush;
    close(p[1]); // fermeture descripteur en écriture

    // lecture d'un seul entier sur le pipe
    int rd, n;
    rd = read(p[0], &n, sizeof(int)); // fils ne lit qu'une seule donnée
    if(rd == -1) { // gestion erreur sur le read
      cerr << "Erreur : " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    cout << "(fils) j'ai lu " << n << endl << flush;

    close(p[0]); // le fils ferme tout de suite son descripteur de fichier en lecture,
    // alors que le père écrit encore de l'autre côté !
    // cela entraine la génération du signal SIGPIPE 
    // cela va appelé le gestionnaire de signal que nous avons mis en place
    cout << "(fils) terminaison normale." << endl << flush;
 
  }

  return EXIT_SUCCESS;
}
