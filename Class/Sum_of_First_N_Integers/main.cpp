/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 20th, 2022, 12:15 PM
 * Purpose:  Sum of the first n integers.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
int recSum(int);  //Recursive.
int iterSum(int); //Iterative.
int clsSum(int);  //Closed-Form.

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n;
    //Initialize Variables
    n=10000;
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Sum:   f("<<n<<") = "<<recSum(n)<<endl;
    cout<<"Iterative Sum:   f("<<n<<") = "<<iterSum(n)<<endl;
    cout<<"Closed Form Sum: f("<<n<<") = "<<clsSum(n)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations

int recSum(int n){
    //Base Condition:
    if(n<=0)return 0; //0=0.
    if(n==1)return 1; //0+1=1
    //Recursion: Previous sum + current term.
    return recSum(n-1)+n;
}

int iterSum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}

int clsSum(int n){
    return n*(n+1)/2;
}