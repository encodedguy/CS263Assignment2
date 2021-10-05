#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//Function Declarations
int random();
void swap(int *, int *);
void bubbleSort(int[], int);
void print(int[], int);

//Function to generate random number
int random(){
	return (rand() % (10000 - 1 + 1)) + 1;
}

//Swapping via XOR Operator
//XOR Used for Speed !!
//Binary == Speed
void swap(int *x, int *y){
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

//Function for Bubble Sorting
//Implementing Using Pointers
//For Mode Speeeed !!
void bubbleSort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){	
			if(arr[j + 1] < arr[j]){
				swap(&arr[j], &arr[j + 1]);	
			}
		}
	}
}

//Function to Print Array
void print(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	puts("");
}

int main(void){
	//Seed for random generator using current time
	srand(time(0));

	//Array in Increasing Order
	int incArray[100000] = {0};

	//Filling Values in Increasing Order
	for (int i = 0; i < 100000; i++){
		incArray[i] = i+1;
	}

	//Array in Decreasing Order
	int decArray[100000] = {0};

	//Filling Values in Decreasing Order
	for (int i = 100000; i >= 1; i--){
		decArray[100000-i] = i;
	}

	//Array in Random Order
	int randArray[100000] = {0};

	//Filling Values in Random Order
	for (int i = 0; i < 100000; i++){
		randArray[i] = random();
	}
	
	clock_t t1;
	t1 = clock();
	bubbleSort(decArray, 100000);
	//print(decArray, 100000);
	t1 = clock() - t1;
	double time_taken = ((double)t1)/CLOCKS_PER_SEC;
	printf("Worst Case:\t%f seconds\n", time_taken);

	clock_t t2;
	t2 = clock();
	bubbleSort(incArray, 100000);
	//print(incArray, 100000);
	t2 = clock() - t2;
	time_taken = ((double)t2)/CLOCKS_PER_SEC;
	printf("Best Case:\t%f seconds\n", time_taken);
	
	
	clock_t t3;
	t3 = clock();
	bubbleSort(randArray, 100000);
	//print(randArray, 100000);
	t3 = clock() - t3;
	time_taken = ((double)t3)/CLOCKS_PER_SEC;
	printf("Average Case:\t%f seconds\n", time_taken);


	return 0;
}
