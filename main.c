#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STARTING_MOTHERS 10000
#define GENERATIONS  100
#define MEANS_FEMALE_CHILDREN 1.5

#define randomize() srand(time(NULL));
#define random_linear(x) ((double)(rand()%((int)((x))*1000))/1000.)

unsigned long long int ancestor_vector_space[STARTING_MOTHERS*2];
unsigned long long int* ancestor_vector_curr;
unsigned long long int* ancestor_vector_new;




int main() {
	randomize();
//init vector
	for(int i=0;i<STARTING_MOTHERS*2;i++){
		ancestor_vector_space[i]=(i<STARTING_MOTHERS)?1:0;
	}

	ancestor_vector_curr=ancestor_vector_space;
	ancestor_vector_new=&(ancestor_vector_space[STARTING_MOTHERS]);

	//simulation
	for(int gen=0;gen<GENERATIONS;gen++){
		printf("%d\n",gen);
		for(int anc=0;anc<STARTING_MOTHERS;anc++){
			ancestor_vector_new[anc]= (unsigned long long int) (ancestor_vector_curr[anc] * random_linear(MEANS_FEMALE_CHILDREN*2));
		}
		unsigned long long int *temp=ancestor_vector_new;
		ancestor_vector_new=ancestor_vector_curr;
		ancestor_vector_curr=temp;
		for(int i=0;i<STARTING_MOTHERS;i++) ancestor_vector_new[i]=0;
	}

	//print
	printf("\n\n\n");
	for(int i=0;i<STARTING_MOTHERS;i++){
		if(ancestor_vector_curr[i]==0) continue;
		printf("%.2fkkk\n", (double) (ancestor_vector_curr[i] / 1000000000.));
	}

	return 0;
}