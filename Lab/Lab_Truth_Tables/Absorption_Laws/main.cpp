/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on February 23, 2022, 2:40 PM
 * Purpose:  Absorption Laws Truth Table 
 * Proving:  p||(p&&q) = p 
 * And That: p&&(p||q) = p
 */

//System Libraries:
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting
using namespace std;

//User Libraries:

//Global Constants:
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare Variables.
    
    //Initialize Variables.
    
    //Map Inputs to Outputs -> Process.
    
    //Display Inputs/Outputs.
    cout<<"Absorption Laws Truth Table: \n"
        <<"Proving: p||(p&&q) = p\n"
        <<"Proving: p&&(p||q) = p\n"<<endl;
    //Truth Table Header:
    cout << "P Q P&&Q P||Q P||(P&&Q) P&&(P||Q)" << endl;
    //Using a for loop, I test out all various truth value combinations.
    for(int P=1;P>=0;P--){     //Outer Loop for P.
        for(int Q=1;Q>=0;Q--){ //Inner Loop for Q.
            //First 3 Conditions:
            cout<<(P?'T':'F')<<" "<<(Q?'T':'F')<<setw(4)<<(P&&Q?'T':'F')<<setw(5)
            //Next  2 Statement Forms:
                <<(P||Q?'T':'F')<<setw(7)<<(P||(P&&Q)?'T':'F')<<setw(9)
            //Final Statement Form:
                <<(P&&(P||Q)?'T':'F')<<endl;
        }
    }
    //Exit the Program - Cleanup.
    return 0;
}