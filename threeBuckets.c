#include <stdio.h>

void threeBuckets(int *array, int length, int low, int high);
void swap(int *arra, int a, int b);
void printArray(int *array, int length);

int main(void) {
	int array[10] = {1, 7, 2, 5};
	int length = 4;
	int lowPivotValue = 3;
	int highPivotValue = 7;

	printArray(array, length);
	threeBuckets(array, length, lowPivotValue, highPivotValue);
	printArray(array, length);

	return 1;
}

void threeBuckets(int *array, int length, int low, int high) {
	int i = 0;
	int lowIndex = 0;			// initial low pivot index
	int highIndex = length-1;	// initial high pivot index
	int temp = 0;

	for(i = 0; i < length; i++) {
		// when two pivot indices met
		if (lowIndex == highIndex) {
			break;
		}

		if (low < array[i]) {
			// swap(array, lowIndex+1, i);
			printf("low swap: ");
			printArray(array, length);
			temp = array[lowIndex+1];
			array[lowIndex+1] = array[i];
			array[i] = temp;
			printf("low swap: ");
			printArray(array, length);
			lowIndex++;
		}

		if (array[i] < high) {
			// swap(array, highIndex-1, i);
			printf("high swap: ");
			printArray(array, length);
			temp = array[highIndex-1];
			array[highIndex-1] = array[i];
			array[i] = temp;
			printf("high swap: ");
			printArray(array, length);
			highIndex--;
		}
	}
}

void swap(int *array, int a, int b) {
	int temp = *(array + a);
	*(array + a) = *(array + b);
	*(array + b) = temp;
}

void printArray(int *array, int length) {
	int i = 0; 
	for (i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}