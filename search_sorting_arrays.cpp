// This program demostrates some searching and sorting algorithm

#include <iostream>
#include <typeinfo> 
using namespace std;


int ArraySorted = false;


int linearSearch(const int[], int, int);
int binarySearch(const int[], int, int);

void bubbleSort(int[], int);
void selectionSort(int[], int);


void swap(int &, int &);
void printArray(int[], int);



int main(){


	int choice = 0;
	int size = 0;
	int value;

	bool quit = false;

	// Flag to keep track of array status
	bool arr_status = false;

	int arr[1000];

	int pos = 0;
	
	


	do
	{
		cout << endl;
		cout << "1. Generate Random Array of integers." << endl;
		cout << "2. Search for element in the array using Linear Search." << endl;
		cout << "3. Search for an element in the array using Binary Search" << endl;
		cout << "4. Sort the Array using BubbleSort." << endl;
		cout << "5. Sort the Array using Selection Sort." << endl;
		cout << "6. Print Array." << endl;
		cout << "7. End Program" << endl;
		cout << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		cin.clear(); //Clear the buffer of the BAD input
  		cin.ignore(256,'\n'); //^


		cout << endl;

		switch(choice) {
  			case 1:
				cout << "Enter array size (MAX SIZE = 1000): ";
				cin >> size;

				for(int i=0;i<size;i++)
      					arr[i]=rand()%100;  //Generate number between 0 to 99

				arr_status = true;


    			break;

			case 2:
				if(arr_status){
					cout << "Enter value to search: ";
					cin >> value;

					pos = linearSearch(arr, size, value);

					cout << "Value found at Position " << pos << endl;
					cout << endl;
				}
				else{
					cout << "Please generate array first!" << endl;
				}
			break;
			case 3:
				if(ArraySorted && arr_status){
					cout << "Enter value to search: ";
					cin >> value;

					pos = binarySearch(arr, size, value);
					cout << "Value found at Position " << pos << endl;
				}
				else{
					cout << "Binary Search requires Array to be sorted first or generate array first" << endl;
				}

				cout << endl;


			break;
			case 4:

				if(arr_status){
					bubbleSort(arr, size);

					cout << "Array is now sorted!" << endl;
				}
				else{
					cout << "Please generate array first." << endl;
				}

			break;
			case 5:
				if(arr_status){
					selectionSort(arr, size);

					cout << "Array is now sorted!" << endl;
				}
				else{
					cout << "Please generate array first." << endl;
				}
			break;
			case 6:
				printArray(arr, size);
				cout << endl;
			break;
  			case 7:
    				quit = true;
    			break;
  			default:
   	 			cout << "TRY AGAIN" << endl;
		}
		cout << endl;
	} while(!quit);
	return 0;
}

int linearSearch(const int arr[], int size,  int value){
	int index = 0;
	int position = -1; // Position of the value we are searching
	bool found = false; // Flag to indicate if the value was found

	while(index < size && !found)
	{
		if(arr[index] == value)
		{
			found = true;
			position = index; // Record the value's subscript

		}
		index++;

	}
	return position;
}


int binarySearch(const int array[], int numElements, int value){
	int first = 0;					// First element 
	int last = numElements - 1;		// Last element of array
	int middle;						// Midpoint
	int position = -1;
	bool found = false;				

	while(!found && first <= last)
	{
		middle = (first + last) / 2;	// Calculate midpoint


										// Value is in the midpoint
		if(array[middle] == value)
		{
			found = true;
			position = middle;
		}
										// Search left
		else if(array[middle] > value)
			last = middle - 1;
										// Search right
		else
			first = middle + 1;
	}
	return position;

}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    ArraySorted = true;
    cout << "Array Sorted!" << endl;
    cout << endl;
}

// A function to implement selection sort
void selectionSort(int array[], int size){

	int minIndex;
	int minValue;
	for (int start=0; start < (size-1); start++){
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++){
			
			if (array[index] < minValue){

				minValue = array[index];
				minIndex = index;
			}


		}
		swap(array[minIndex], array[start]);
	}
}


void swap(int &a, int &b){

	int temp = a;
	a=b;
	b=temp;
}



void printArray(int arr[], int size){

	for(int i=0; i<size; i++)
		cout << arr[i] << ", ";

	cout << endl;

}
