#include "RNT.h"
#include "RNT.cpp"
#include <iomanip>
#include <iostream>
using namespace std;

//unit testing for residual nitrogen time 
int main(){
    Residual_time testdata;
    cout << "Beginning tests." << endl;

    if (testdata.RNT('B', 13.45, 32) != 17){
        cout << "FAILED RNT() for values 'B', 13.45, 32" << endl;
    }
    if (testdata.RNT('O', 21.1, 50) != 11){
        cout << "FAILED RNT() for values 'O', 21.1, 50" << endl;
    }
    cout << "Tests complete." << endl;
    return 0;
}