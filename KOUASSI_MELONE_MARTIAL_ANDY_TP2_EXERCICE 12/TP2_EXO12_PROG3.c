#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


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