/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on March 21st, 2022, 12:30 PM
 * Purpose:  Comparing the Arithmetic Mean
 *              and the Geometric Mean.
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
#include <cmath>      //Math Library
#include <iomanip>    //Format Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);

//Returns the logs of the AM & GM:
float logAM(int [],int); //Log of the Arithmetic Mean.
float logGM(int [],int); //Log of the Geometric Mean.

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    const int SIZE=1000;
    int array[SIZE];
    int perLine=40;
    
    //Initialize variables here:
    cout<<"Arithmetic vs. Geometric Mean Inequality Simulation:\n";
    for(int i=10;i<=SIZE;i*=10){
        fillAry(array,i);
    
        //Display the results:
        prntAry(array,i,perLine);
    
        //Map inputs to outputs here, i.e. the process:
        cout<<fixed<<setprecision(6)<<showpoint<<endl;
        cout<<i<<" Elements Between [10,99]"<<endl;
        //Log(AM) = Log of the Average.
        cout<<"AM = "<<exp(logAM(array,i))<<" >= ";
        //Log(GM) = Average of the Log Sum.
        cout<<"GM = "<<exp(logGM(array,i))<<endl;
    }

    return 0;
}

float logAM(int a[],int n){
    //AM = Sum of all elements / # of elements.
    float am=0.0f;
    //Take the sum of all elements:
    for(int i=0;i<n;i++){
        am+=a[i];
    }
    //We divide the sum by the # of elements.
    am/=n;
    return log(am);
}

float logGM(int a[],int n){
    //GM = Nth root of the Product of all elements.
    //This is equivalent to the Product of all elements ^ 1/N power.
    //log(GM) = log(Product ^ 1/N) = 1/N * log(Product) = 1/N * Sum of all the logs.
    //Log(AB) = Log(A) + Log(B) & Log(A^n) = nLog(A).
    float logGm=0.0f;
    //Take the sum of all the logs:
    for(int i=0;i<n;i++){
        logGm+=log(a[i]);
    }
    //Log(GM) = 1/N * Sum of all the logs:
    logGm*=(1.0f/n);
    return logGm;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    cout<<"Array Size = "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
}