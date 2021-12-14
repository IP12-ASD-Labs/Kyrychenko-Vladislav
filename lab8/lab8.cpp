#include <iostream>
#include <iomanip>  
using namespace std;

// Заповнення масивів 
void fillArr1D(double [8][5],double [8]);
void fillArr2D(double [8][5]);

// Відображення масивів
void displayArr2D(double [8][5], string);
void displayArr1D(double [8],string);

// Сортування масивів
void swap(double* , double* );
void bulbSort(double [8]);


int main() {
    // Ініціалізація масивів
    double arr2D[8][5];
    double arr1D[8];

    // Заповнення масивів 
    fillArr2D(arr2D);
    fillArr1D(arr2D,arr1D);

    // Відбраження початкових масивів
    displayArr2D(arr2D, "Двовимірний масив: ");
    displayArr1D(arr1D, "Початковий одновимірний масив: ");

    //Сортування одновимірного масиву
    bulbSort(arr1D);

    //Відображення відосртованого масиву
    displayArr1D(arr1D, "Відсортований одновимірний масив: ");
    
    
}


void fillArr1D(double arr2[8][5],double arr1[8] ) {
    for (int i = 0 ; i < 8; i ++ ) {
        arr1[i] = 0;

        for (int j = 0 ; j < 5; j++) {
            if (arr2[i][j] > 0 ){
                arr1[i]+=arr2[i][j];
            }
        }

    }
}
void fillArr2D(double arr2[8][5]) {
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 5; j++) {
            arr2[i][j]=rand()%201 -100 + double(rand()%100)/100;
        }

    }
}


void displayArr1D(double arr1[8], string message){
    cout << message << "\n\n";

    for (int i = 0; i < 8; i++) {
        cout << setw(3) << arr1[i] << "\n";;
    } 

    cout << "\n";
}
void displayArr2D(double arr2[8][5], string message){
    cout << message << "\n\n";

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 5; j++) {
            cout <<setw(6)<< arr2[i][j] << " ";
        }

        cout << "\n";;

    }

    cout << "\n";
}

void bulbSort(double arr1[8]) {
    for (int i =0; i < 8; i++) {

        for (int j = 0; j < 7; j++) {

            if (arr1[j] > arr1[j+1]){
                swap(&arr1[j], &arr1[j+1]);
             }
       }

    }
}
void swap(double* a, double* b) {
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}