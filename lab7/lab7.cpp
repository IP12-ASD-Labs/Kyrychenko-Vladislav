#include <iostream>
#define SIZE 10
using namespace std;

void fillArrays(char arr1[], char arr2[]);
void generateArr(char arr1[], char arr2[], char newArr[]);
int calclulateProduct(char arr[]);

void showArr(char arr[], string message);

int main() {
    //Initializing values
    char arrA[SIZE];
    char arrB[SIZE];
    char arrC[SIZE];
    int product;
    //Processing data
    fillArrays(arrA, arrB);
    generateArr(arrA, arrB, arrC);
    product = calclulateProduct(arrC);

    // Displaying result
    showArr(arrA, "Елементы масиву A: ");
    showArr(arrB, "Елементи масиву B: ");
    showArr(arrC, "Елементи масиву C: ");
    cout <<"Добуток елеменів масиву С, які задовольняють умову задачі: " << endl <<product;

    return 0;
}


void fillArrays(char arr1[], char arr2[]) {
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = 43 - i;
        arr2[i] = 37 + i;
    }
}

void generateArr(char arr1[], char arr2[], char newArr[]) {
    for (int i = 0; i < SIZE; i++) {
        newArr[i] = 0;
        int j = 0;
        while (j < SIZE && ((int)newArr[i] == 0)) {
            if (arr1[i] == arr2[j]) {
                newArr[i] = arr1[i];
            };
            j++;
        }
    }

}

int calclulateProduct(char newArr[]) {
    int prod = 1;
    for (int i = 0; i < SIZE; i++) {
        if (newArr[i] > 40) prod *= newArr[i];
    }
    return (prod == 1) ? 0 : prod;
}

void showArr(char arr[], string message) {
    cout << message << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<< endl;
}
