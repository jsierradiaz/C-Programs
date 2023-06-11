// Program to Practice dynamic memory allocation.


#include<iostream> //cin,cout
#include<iomanip> 
#include<cstring>
#include<cctype>
#include<cstdlib>
#include <limits> 
using namespace std;

#define MAX 10

bool isPositive(int );
int* allocate(int );
void deallocate(int* &);
void inputTestScores(int [], int);
float calcTestAvg(int [], int);
void displayTestResults(const int[], int, float);
void convertToLowerCase( char [], int);


int main () {

    int count, *tests = nullptr;
    
    
    float avg = 0;
    char response[MAX];

    do {
        do {
            cout << "How many tests scores do you want to enter? ";
            cin >> count;
            cin.clear(); //Clear the buffer of the BAD input
  		    cin.ignore(256,'\n'); //^


        }while(!isPositive(count)); // need to define
       tests = allocate(count); // need to define


       if(tests!=nullptr){
          inputTestScores(tests,count); // need to define
          avg = calcTestAvg(tests, count);// need to define
          displayTestResults(tests, count, avg); //need to define

          deallocate(tests);   
       }
       else {
           cout << "bad allocation \n";
           exit(1);
       }

       cout << "Enter new series of test scores? (yes/no)";
       cin.ignore(256, '\n');
       cin.getline(response, MAX);
       convertToLowerCase(response, strlen(response)); // need to define


    }while(!strcmp(response, "yes"));





    return 0;
}


bool isPositive(int number){
    bool status;

    if (number >= 1 && number <= 100)
        status = true;
    else status = false;

    return status;
}


int* allocate(int size){


    int* temp=nullptr;
    temp  = new int[size];

    return temp;


}


void deallocate(int * &p){
    if (p!=nullptr) {
        delete [] p;
    }
    p = nullptr;
}


void inputTestScores(int scores[], int size){
    //looop counter
    int index;

    //Get each test score.
    for(index = 0; index <= size - 1; index++){
        cout << "Enter test score number " << (index + 1) << ": ";
        cin >> scores[index];
        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter test score number " << (index + 1) << ": ";
            cin >> scores[index];
            
        }

    }
}



float calcTestAvg(int  scores[], int size){
    double total = 0;  //Accumulator
    float average;

    //Add each elelment to the total
    for (int count = 0; count < size; count++){
        total += scores[count];
    }

    average = total/size;
   return average;
}


void displayTestResults(const int scores[], int size, float avg){

    for(int i = 0; i < size ; i++){
        cout << "Test #" << (i + 1) << ": " << scores[i] << endl;
    }
    cout << "Average: " << setprecision(2) << fixed << avg << endl;
}


void convertToLowerCase(char response[], int size){
    
    for (int i = 0; response[i]; i++){
        response[i] = tolower(response[i]);
    }

}

