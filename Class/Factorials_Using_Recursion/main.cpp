/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 20th, 2022, 1:30 PM
 * Purpose:  Factorials Using Recursion
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
int recFact(int);    //A recursive approach for finding factorials.
int iterFact(int);   //An iterative approach for finding factorials.

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, Units, Range, Description:
    int n; //The number we'll be taking the factorial of.
    
    //Initialize Variables:
    n=10;  
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Product/Factorial: f("<<n<<")= "<<recFact(n)<<endl;
    cout<<"Iterative Product/Factorial: f("<<n<<")= "<<iterFact(n)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations:
int recFact(int n){
    //Base Condition:
    if(n<=1)return 1; //0! = 1 & 1! = 1.
    //Recursion:
    //We simply take the previous factorial and multiply it by the current term...
    return recFact(n-1)*n;
}

int iterFact(int n){
    int prod=1;
    for(int i=1;i<=n;i++){
        prod*=i;
    }
    return prod;
}