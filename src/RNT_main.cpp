#include "RNT.h"
#include "RNT.cpp"
#include <iomanip>
#include <iostream>
using namespace std;

//main for residual nitrogen time 
int main(){
    char repet_group;
    double SI_time;
    int depth;

    Residual_time rt;

   
    //asks the user for the original repet group
    cout << "What is the Repet group? ";
    cin >> repet_group;
    cout << endl;
    //ask the user how long they are at the surface before next dive
    cout << "What is the surface interval time? (Enter in 0.00 format) ";
    cin >> SI_time;
    cout << endl;
    //asks the user what the depth of the next dive is
    cout << "What is the depth of the the repet dive? ";
    cin >> depth;
    cout << endl;

    //calls the residual nitrogen time (RNT function)
    cout << "The Residual Nitrogen Time added to the Repet dive is: " << rt.RNT(repet_group, SI_time, depth) << " min" << endl;

    return 0;
    // actual bottom time (ATM) = planned bottom time * RNT
}