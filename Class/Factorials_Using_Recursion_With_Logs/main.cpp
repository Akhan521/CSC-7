/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 20th, 2022, 1:45 PM
 * Purpose:  Factorials Using Recursion & Logs
 * We use logs to handle very large factorials. Moreover, we represent the factorials
 * using scientific notation, so that we can represent extremely large products.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
float recFctLg(float);      //Returns the log of the factorial using recursion.
float iterFctLg(float);     //Returns the log of the factorial using iteration.
int split(float,float &);   //Splits the log of the factorial into 2 components. 

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, Units, Range, Description:
    int n;          //The number we'll be taking the factorial of.
    //The split function splits our factorial log into 2 components:
    float fraction; //The fractional component of our factorial log.
    int   powr10;   //The integer component of our factorial log.
    //Initialize Variables:
    n=1000;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs:
    powr10=split(recFctLg(n),fraction);              //  Mantissa       Characteristic
    cout<<"Recursive Product/Factorial f("<<n<<")="<<pow(10,fraction)<<"x10^"<<powr10<<endl;
    powr10=split(iterFctLg(n),fraction);             //  Mantissa       Characteristic
    cout<<"Iterative Product/Factorial f("<<n<<")="<<pow(10,fraction)<<"x10^"<<powr10<<endl;
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations:

//Return:  The integer component of our factorial log (Our characteristic or Power of 10).
//1st Arg: The log of our factorial with base e.
//2nd Arg: The variable that will hold the fractional component of our factorial log.
int split(float logFct,float &frac){
    //Convert to Base 10 using change of base formula: (log(fctrl)=ln(fctrl)/ln(10)).
    float lgBse10=logFct/log(10.0f);
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

float recFctLg(float n){
    //Base Condition:
    if(n==1)return 0; //Since ln(1)=0;
    //Recursion:
    //We take the previous log sum and add the current log...
    return recFctLg(n-1)+log(n);
}

float iterFctLg(float n){
    float lgSum=0;
    for(int i=1;i<=n;i++){
        lgSum+=log(i);
    }
    return lgSum;
}