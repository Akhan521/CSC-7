/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 25th, 2022, 1:00 PM
 * Purpose:  Permutations w/ Rep. Using Logs.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes:
float recLgPrm(unsigned int,unsigned int);  //log(nPm) Recursive.
float iterLgPrm(unsigned int,unsigned int); //log(nPm) Iterative.
//Splits the log of the permutation into 2 components for Sci. Not.
int split(float,float &);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    unsigned int n,m;
    //The split function splits our permutation log into 2 components:
    float fraction; //The fractional component of our permutation log.
    int   powr10;   //The integer component of our permutation log.

    //Initialize Variables
    n=10;
    m=4;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Recursive: Log(nPm) = "<<recLgPrm(n,m)<<endl;
    cout<<"Iterative: Log(nPm) = "<<iterLgPrm(n,m)<<endl;
    //Calculate nPm using recursion:
    powr10=split(recLgPrm(n,m),fraction);
    cout<<"Recursive: nPm =  f("<<n<<","<<m<<") = "
        <<pow(10,fraction)<<"x10^"<<powr10<<endl;
    //Calculate nPm using iteration:
    powr10=split(iterLgPrm(n,m),fraction);
    cout<<"Iterative: nPm =  f("<<n<<","<<m<<") = "
        <<pow(10,fraction)<<"x10^"<<powr10<<endl;
    
    //Display the outputs
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations:

//Return:  The integer component of our permutation log (Our characteristic or Power of 10).
//1st Arg: The log of our permutation with base e.
//2nd Arg: The variable that will hold the fractional component of our permutation log.
int split(float logPrm,float &frac){
    //Convert to Base 10 using change of base formula: (log(fctrl)=ln(fctrl)/ln(10)).
    float lgBse10=logPrm/log(10.0f);
    //Divide the log into an integer and fraction -> characteristic and mantissa:
    int iLgBs10=lgBse10;  //The int comp. of our log with base 10.
    frac=lgBse10-iLgBs10; //The fract. comp. of our log with base 10.
    return iLgBs10;
    /* The reason we split the log is to take advantage of scientific notation.
     * For Ex: log(5!) = 2.07918125. (Int = 2, Fract = 0.07918125)
     * 10^log(5!) = 10^2.07918125 = 10^0.07918125 * 10^2 = 120.
     * (When you take the product of 2 #s w/ the same base, you add the exponents.)
     * -> 10^0.07918125 * 10^2 = 10^2+0.07918125 = 10^2.07918125. 
     * We can separately display both components now that we've split 
     * the log up into its integer and fractional components. 
     * Our characteristic will be 10^int. comp. of our log. (10^2)
     * Our mantissa will be 10^fract. comp. of our log.     (10^0.07918125)
     * FINALLY, the product = mantissa * characteristic.
     */
}

float iterLgPrm(unsigned int n,unsigned int m){
    float lgNtoM=0;     //Log(n^m) = log(n) + ... (m times)
    for(unsigned int i=1;i<=m;i++){
        lgNtoM+=log(n); //Sum of the logs.
    }
    return lgNtoM;
}

float recLgPrm(unsigned int n,unsigned int m){
    //Base Condition:
    if(m<=0)return 0; //N^M when M=0 = N^0 = 1.
    //Recursion: (Previous Log Sum + Log(n)).
    return recLgPrm(n,m-1)+log(n);
}