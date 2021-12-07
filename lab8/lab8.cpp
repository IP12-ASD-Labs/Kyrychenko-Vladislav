#include <iostream>
#include <iomanip>  
using namespace std;

void fillArr(double arr2D[5][8]);
void displayArr(double arr2D[5][8]){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            cout <<setw(3)<< arr2D[i][j] << " ";
        }
        cout << endl;
    }
}
//double** 

int main() {
    int i=8, j =5;

    double arr2D[5][8];

    fillArr(arr2D);
    displayArr(arr2D);
}
void fillArr(double arr2D[5][8]) {
    int counter = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            
            arr2D[i][j]=counter;
            counter++;
        }
    }
}