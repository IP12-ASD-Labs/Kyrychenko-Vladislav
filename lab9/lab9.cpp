#include <iostream>
#include <iomanip>
using namespace std;
void fillArr(double** ,int, int);
void displayArr(double**, string, int, int);
int* findNum(double** ,int, int, double);
int countGreaterBelowDiagonal(double** , int, int , double);

int main(){
    int row,col;
    double num;
    int* numCoord; 

//
    cout << "Введіть кількість рядків матриці: ";
    cin >> row;
    cout << "Введіть кількість стовпців матриці: ";   
    cin >> col;
    cout << "Введіть шукане число: "; 
    cin >> num;
//

    double** arr = new double*[row];
//
    for (int i=0; i < row; i++) {
        arr[i] = new double[col]{};
    }
//
    

    fillArr(arr, row, col);
    arr[4][7] = 38;
    numCoord = findNum(arr, row, col, num );
    int countGreater = countGreaterBelowDiagonal(arr,row,col,num);
    


    if (numCoord[0]==-1) {
        cout << "Число " << num <<" не було знайдено серед елементів матриці";
    } else {
        cout << "Число " << num <<" було знайдено серед елементів матриці у " << numCoord[0] << "-му рядку, "<< numCoord[1] << "-му стовпчику"<<endl; 
    }
//
    displayArr(arr,"Array: ", row, col);
    
    cout << "Кількість чисел під основною діагоналлю, що перевищують "<< num << " : " << countGreater;


    delete[] numCoord;

    for (int i=0; i < row; i++) {
        delete[] arr[i];
    }

    delete[] arr;
//
    return 0;
}

void fillArr(double ** arr, int row,int col) {
    srand(time(NULL));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
				arr[i][j] = rand()%201 -100 + double(rand()%100)/100;
				
			}
		}
}


void displayArr(double** arr2, string message, int row, int col){
    cout << endl << message << "\n\n";

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {
            cout <<setw(6)<< arr2[i][j] << " ";
        }

        cout << "\n";;

    }

    cout << "\n";
}

int* findNum(double** arr,int row, int col , double num) {
    int i = 0 ,j = 0;;
    bool found = false;
    int* numCoord = new int[2] {-1};
    while (i < row &&  found != true) {

        if (i%2==0) {
            
            while (j < col &&  found != true ) {
                if ( arr[i][j] == num ){
                    numCoord[0] = i+1;
                    numCoord[1] = j+1;
                    found = true;
                }
                j++;
            }
        } else {

            while (j > -1 &&  found != true ) {
                if ( arr[i][j] == num ){
                    numCoord[0] = i+1;
                    numCoord[1] = j+1;
                    found = true;
                }
                j--;
            }
        }
        
        i++;
    }
    return numCoord;
}

int countGreaterBelowDiagonal(double** arr, int row, int col, double num) {
    int counter = 0;
    for (int i = 0; i < row; i++) {
        int j = 0;
        while (j < i && j < col) {
            if (arr[i][j] > num) {
                counter++;
            }
            j++;
        }
    }
    return counter;
}