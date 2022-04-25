/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 25, 2022, 11:20 AM
 * Purpose: N Permutations W/ Repetition.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
unsigned int nPrmRec(unsigned int,unsigned int);  //Recursive n^m.
unsigned int nPrmIter(unsigned int,unsigned int); //Iterative n^m.

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    unsigned int n,m,ntom;
    //Initialize Variables
    n=10;
    m=4;
    //Map Inputs to Outputs -> Process
   
    //Display Inputs/Outputs
    ntom=nPrmRec(n,m);
    cout<<"Recursive nPm = "<<n<<"^"<<m<<" = "<<ntom<<endl;
    ntom=nPrmIter(n,m);
    cout<<"Iterative nPm = "<<n<<"^"<<m<<" = "<<ntom<<endl;
    //Exit the Program - Cleanup
    return 0;
}

//N Permutations w/ Repetition (Recursive).
unsigned int nPrmRec(unsigned int n, unsigned int m){
    //Base case: If m = 0, then n^m = n^0 = 1.
    if(m<=0) return 1;
    return nPrmRec(n,m-1)*n;
}
//N Permutations w/ Iteration.
unsigned int nPrmIter(unsigned int n, unsigned int m){
    int ntom=1;
    for(int i=0;i<m;i++){
        ntom*=n;
    }
    return ntom;
}
