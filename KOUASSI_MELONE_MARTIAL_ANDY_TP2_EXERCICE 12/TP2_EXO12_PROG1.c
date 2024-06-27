#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>



int programme1_code() {
    pid_t pid_fils1, pid_fils2;
    
    printf("Je suis le père et mon PID est : %d\n", getpid());
    printf("\n");

    // creation du premier fils
    pid_fils1 = fork(); 
    if (pid_fils1 == 0) {
        	printf("Je suis le premier processus fils mon PID est %d, le PID de mon père est %d\n", getpid(), getppid());
        return 0;
    } else if (pid_fils1 > 0) {
        // création du deuxième fils
        pid_fils2 = fork(); 
        if (pid_fils2 == 0) {
            printf("Je suis le deuxième processus fils et mon PID est %d, le PID de mon père est %d\n", getpid(), getppid());
            return 0;
        } else if (pid_fils2 > 0) {
            // Attente des deux fils
            int status;
            waitpid(pid_fils1, &status, 0);
            waitpid(pid_fils2, &status, 0);

            printf("\n");
			printf("Je suis le père, fin de l'execution de mes fils\n");
            printf("***** RECAPITULATIF*****\n");
            printf("\n");
            printf("PID du père : %d\n", getpid());
            printf("PID du premier fils : %d\n", pid_fils1);
            printf("PID du deuxième fils : %d\n", pid_fils2);
            return 1;
        }
    } else {
        perror("Erreur lors de la création du premier fils");
        return 1;
    }

    return 0;
}

int main(){
	printf(" \n ");
	printf("===== WELCOME=====\n");
		programme1_code();
	printf(" \n ");
	return 0;
}