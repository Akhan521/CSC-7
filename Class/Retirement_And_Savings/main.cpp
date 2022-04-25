/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 20th, 2022, 1:30 PM
 * Purpose:  Retirement + Savings (All-in-one).
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
float recFrmla(float,float,float,int);
float iterFrmla(float,float,float,int);
float clsFrm(float,float,float,int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float pv,rate,dep;
    int n;
    
    //Initialize Variables
    pv=0;         //Present Value.
    rate=1.0f;    //1 + Interest Rate. (Ex. 8% interest = 1.08 as our rate).
    dep=10000.0f; //Deposit.
    n=50;         //Number of periods.
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Formula  f("<<pv<<","<<rate<<","<<dep<<","<<n<<") = "
            <<recFrmla(pv,rate,dep,n)<<endl;
    cout<<"Iterative Formula  f("<<pv<<","<<rate<<","<<dep<<","<<n<<") = "
            <<iterFrmla(pv,rate,dep,n)<<endl;
    cout<<"Closed formFormula f("<<pv<<","<<rate<<","<<dep<<","<<n<<") = "
            <<clsFrm(pv,rate,dep,n)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations:
float recFrmla(float pv,float rate,float dep,int n){
    //Base Condition: 
    if(n<=0)return pv;
    //Recursion: (Previous term * the rate + our deposit).
    return rate*recFrmla(pv,rate,dep,n-1)+dep;
}

float iterFrmla(float pv,float rate,float dep,int n){
    float total=pv;
    for(int i=1;i<=n;i++){
        total*=rate; //Multiply our rate.
        total+=dep;  //Add our deposit.
    }
    return total;
}

float clsFrm(float pv,float rate,float dep,int n){
    //If we have no interest, we simply return the value we began with
    //along with the deposits that we made in n periods.
    if(rate==1)return pv+n*dep;
    //To simply our final calculation, we find rate^n.
    float rteTon=pow(rate,n);
    //Return the final closed form result:
    return pv*rteTon+dep*(1-rteTon)/(1-rate);
}