#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>




int programme2_code() {
    pid_t pid_pere, pid_fils1, petit_fils1;

    pid_pere = getpid(); 
  
    printf("Je suis le père et mon PID est: %d \n", pid_pere);
    printf(" \n ");
    // Création du premier fils
    pid_fils1 = fork(); 
    if (pid_fils1 == 0) {
        printf("Je suis le premier processus fils\n mon PID est %d \n le PID de mon père est %d\n", getpid(), getppid());
        printf(" \n ");

        // Création du petit fils
        petit_fils1 = fork(); 
        
        if (petit_fils1 == 0) {
            printf("Je suis le processus petit fils\n mon PID est : %d\n", getpid());
            printf("Le PID de mon père est: %d \n", getppid());
            printf("Le PID de mon grand-père est : %d \n", pid_pere);
            printf(" \n ");
        } else if (petit_fils1 > 0) {
            wait(NULL); // Attendre que le petit fils se termine
            printf("Encore moi le processus fils \n mon PID est %d\n", getpid());
            printf("Le PID de mon fils est : %d\n", petit_fils1);
            printf("Le PID de mon père est : %d\n", getppid());
            printf(" \n ");
            return 0;
        } else {
            perror("Erreur lors de la création du petit fils");
            return 1;
        }
    } else if (pid_fils1 > 0) {
        printf(" \n ");
        wait(NULL); // Attendre que le fils se termine
        printf("Enfin, mon fils et mon petit fils ont fini leur exécution, je peux maintenant terminer le programme\n");
        return 0;
    } else {
        perror("Erreur lors de la création du premier fils");
        return 1;
    }

    return 0;
}

int main(){
	printf(" \n ");
	printf("===== WELCOME=====\n");
		programme2_code();
	printf(" \n ");
	return 0;
}