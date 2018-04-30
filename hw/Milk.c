#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 1000000

int cnt = 0;
sem_t mutex;
int c=0;
int leche;
int keep=0;
void * Sell(void * a)
{
    int b= (int) (a) +1;
    sem_wait (&mutex);
	int numero=((rand() %3)+3);
	printf("\nHay %d litros de leche disponible en la tienda\n",leche);
	printf("\n Vendedor %d tratando de vender %d litros\n",b,numero);
	int tmp=leche;
	if( (tmp-numero)<0){
		printf("\n Vendedor %d no pudo vender %d litros porque no alcanzó \n",b,numero);
		keep=1;
	}
	else{
		tmp-=numero;
		leche=tmp;
		printf("\nQuedan %d litros disponibles\n",tmp);
	}
    sem_post (&mutex);

}

int main(int argc, char * argv[])
{
    //int i=0;
    int j=0;
    sem_init(&mutex, 0, 1);
    srand((unsigned int)time(NULL));
    int number= (rand() %2)+4;
	printf("Tenemos %d trabajadores\n",number);
    leche=(rand() %15)+15;
	printf("\nLa tienda tiene %d litros de leche para vender\n",leche);
    pthread_t Threads[number];
    while(keep==0){
    	int i=0;
	while(i<number){
       		if(pthread_create(&Threads[i],NULL,Sell, (void*) (i))){
			exit(1);
		}
		if(pthread_join(Threads[i],NULL)){
			exit(1);
		}
		++i;
    	}
    }
    pthread_exit(NULL);
}
