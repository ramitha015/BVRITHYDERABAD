#include<stdio.h>
#include<stdlib.h>
# define SIZE 5
int mutex = 1 ,empty = SIZE , full = 0 , item = 0;
int wait(int w){
	return(--w);
}
int signal(int s){
	return(++s);
}
void producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	printf("\nproducer produces the item %d\n" , ++item);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("consumer consumes the item %d" , item--);
	mutex = signal(mutex);
}



int main(){
	int n ;
	printf("enter 1. for producer\nenter 2 for consumer\nenter 3 for exit\n");
	while(1){
		printf("enter the choice: ");
		scanf("%d" , &n);
		switch(n){
			case 1: if((mutex==1)&&(empty!=0))
			           producer();
			        else
			        printf("buffer is full\n");
			        break;
			case 2 : if((mutex==1) &&(full!=0))
			           consumer();
			        else
			          printf("buffer is empty\n");
			          break;
			case 3 : exit(0);
			         break;

		}
	}
}
