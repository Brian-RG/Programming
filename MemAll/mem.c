#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

int main(void){
	 srand((unsigned int)time(NULL));
	int segments[24];
	//Each segment has 10 of memory
	int processes[5];
	int used=0;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int m=0;
	int a=0;
	int resta=0;
	for(a;a<24;a++){
		segments[a]=0;
	}
	for(i=0; i<5; i++){
		processes[i] = (rand()%20)+25;
		int n=(int)  ( ceil( (float) (processes[i]) / 10)  )  ;
		for(j=0;j<n;j++){
			//printf("Asignando a j que es %d, el valor de %d",j,i);
			segments[used]=i+1;
			++used;
		}
	}	

	for(k=0;k<5;k++){
		printf("\nP%d with memory %d is using:\n",k+1,processes[k]);
		for(l=0;l<used;l++){
			if(segments[l] == k+1){
				//printf("l is equal to: %d and %d",l,segments[l]);
				printf("segment %d \n",l+1);
			}
		}
		
	}
	int *d;
	printf("Insert the number of process you want to delete: ");
	scanf("%d",d);
	for(m;m<used;m++){
		 //printf("ENTRE EN m = %d y d = %d ADEMAS EL VALOR EN M ES %d \n",m,d,segments[m]);
		printf("%d no es igual a %d \n",segments[m],*d);
		if(segments[m] == *d){
			segments[m]=0;
			printf("BORRADO \n");
			resta++;
		}
		
	}
	used-=resta;
	//printf("USED VALE %d",used);
	
	        for(k=0;k<5;k++){
                printf("\nP%d with memory %d is using:\n",k+1,processes[k]);
                //printf("l is equal to: %d and %d",l,segments[l]);
		for(l=0;l<used;l++){
                        //printf("l is equal to: %d and %d",l,segments[l]);
			if(segments[l] == k+1){
                               
                                printf("segment %d \n",l+1);
                        }
                }

        }
	
	
	int *input;
	printf("Insert the size of the new process you want to insert: ");
	scanf("%d",&input);
	int b=(int)  ( ceil( (float) (*input) / 10)  );
	int counter=0;
	int limit=0;
	for(counter;counter<24;counter++){
		if(limit<b){
			if(segments[counter]==0){
				segments[counter]=6;
				used++;
			}
		}		
	}
	
	
	for(k=0;k<5;k++){
                printf("\nP%d with memory %d is using:\n",k+1,processes[k]);
                for(l=0;l<used;l++){
                        if(segments[l] == k+1){
                                //printf("l is equal to: %d and %d",l,segments[l]);
                                printf("segment %d \n",l+1);
                        }
                }

        }
	printf("USADOS POR EL NUEVO PROCESO: \n");
	       	for(l=0;l<used;l++){
                        if(segments[l] == 6){
                                //printf("l is equal to: %d and %d",l,segments[l]);
                                printf("segment %d \n",l+1);
                        }
                }
	
}
