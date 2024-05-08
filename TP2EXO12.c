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


int programme3_code(){
 	pid_t pid_pere, pid_fils1, pid_fils2;

    pid_pere = getpid(); 
    
    printf("PID du porocessus est: %d\n  \n", pid_pere);

    // creationn du premier fils
    pid_fils1 = fork(); 
    
    if (pid_fils1 == 0) {
    		printf("**** fils 1 prend le relais ****\n");
	        printf("Je suis le premier processus fils, fils1 et mon PID est : %d\n", getpid());
			printf("le PID de mon père est : %d   \n", getppid() );
	        printf("***** le fils 1 a finis son execution ******* \n");
	        printf(" \n ");

    } else if (pid_fils1 > 0) {  
    
		    // creation du fils 2, frere de 1
		    pid_t pid_fils2 = fork(); 
		    
		    if (pid_fils2 == 0) {
		    	printf("**** fils 2 prend le relais ****\n");
		        printf("Je suis le deuxieme fils, fils 2 et mon PID est : %d\n", getpid());
		        printf("le PID de mon père est : %d   \n", getppid() );
				printf(" \n ");

		        //creation du petit fils
		        pid_t petit_fils1 = fork(); 
		        
		        if (petit_fils1 == 0) {
		        	printf("**** le petit fils debuts son execution ****\n ");
		            printf("Je suis le porocessus petit fils, fils du fils2 avec PID  %d\n", getpid());
		            printf("**** le petit fils a finis son execution **** \n");
		        }else if (petit_fils1 > 0) {
		        	printf("**** le fils 2 est mise en attente **** \n");
					wait( NULL);
		        	printf(" **** le fils 2 finis son execution **** \n ");
					printf(" \n ");
		        }
	        }else if(pid_fils2 > 0) {
	        	printf("**** le pere est en cours d'execution ****\n");
	        	printf(" **** le pere est mise  en attente ****\n");
	        	printf(" \n ");
	        	wait(NULL);
	        	wait(NULL);
	        	wait(NULL);
	        	wait(NULL);
	    		wait(NULL); 
	    		printf("**** le programme est terminné ****\n");
	        }else{
	        	printf("err");
	        }


    } else {
    		    }

		return 0;
	}

int main(){
	printf(" \n ");
	printf("===== WELCOME=====\n");
		programme3_code();
	printf(" \n ");
	return 0;
}