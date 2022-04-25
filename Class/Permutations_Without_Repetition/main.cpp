/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 25th, 2022, 12:45 PM
 * Purpose:  Recursive Product or Factorial
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes:
//Recursive Factorial Calculator:
unsigned int recFctrl(unsigned int);
//Iterative Factorial Calculator:
unsigned int iterFctrl(unsigned int);
//N Permutations w/o Repetition: N!/(N-M)!.
unsigned int nPrmRec(unsigned int,unsigned int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    unsigned int n,m;
    
    //Initialize Variables
    n=10;
    m=4;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Factorial    "<<n<<"!     = "<<recFctrl(n)<<endl;
    cout<<"Iterative Factorial    "<<n<<"!     = "<<iterFctrl(n)<<endl;
    cout<<"Recursive nPm w/o rep. f("<<n<<","<<m<<") = "
                                  <<nPrmRec(n,m)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
unsigned int nPrmRec(unsigned int n,unsigned int m){
    //N!/(N-M)!:
    return recFctrl(n)/recFctrl(n-m);
}

unsigned int recFctrl(unsigned int n){
    //Base Condition
    if(n<=1)return 1; //1!=1 & 0!=1.
    //Recursion: (Previous term * current term).
    return recFctrl(n-1)*n;
}

unsigned int iterFctrl(unsigned int n){
    unsigned int fctrl=1;
    for(int i=1;i<=n;i++){
        fctrl*=i;
    }
    return fctrl;
}