#include <iostream>
#include <iomanip>  
using namespace std;

int seqProduct(int a,int aEnd, int d);

int main() {
    int a=2;
    int aEnd=30;
    int d=4;
    int r;
    r = seqProduct(a,aEnd,d);
    
    cout << "a = " <<setw(29)<< a << endl
         << "aEnd ="<<setw(28) << aEnd << endl
         << "d = " <<setw(29)<< d << endl
         << "Добуток усіх членів прогресії = "<< r ;
    return 0;
}

int  seqProduct(int firdstEl, int lastEl, int step) {
    int rFunc;
    if(firdstEl==lastEl)
        return firdstEl;
    rFunc= firdstEl*seqProduct(firdstEl+step,lastEl,step);
    return rFunc;
}