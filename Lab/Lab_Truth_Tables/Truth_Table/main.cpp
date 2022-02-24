/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on February 23, 2022, 12:40 PM
 * Purpose:  Truth Table (In Fewer Lines of Code) 
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
    cout<<"General Truth Table:\n\n";
    //Truth Table Header:
    cout << "P Q !P !Q P&&Q P||Q P^Q (P^Q)^Q (P^Q)^P !(P&&Q) !P||!Q !(P||Q) !P&&!Q" << endl;
    //Using a for loop, I test out all various truth value combinations.
    for(int P=1;P>=0;P--){     //Outer Loop for P.
        for(int Q=1;Q>=0;Q--){ //Inner Loop for Q.
            //First 4 Conditions:
            cout<<(P?'T':'F')<<" "<<(Q?'T':'F')<<setw(3)<<(!P?'T':'F')<<setw(3)<<(!Q?'T':'F')<<setw(4)
            //Next  3 Statement Forms:
                <<(P&&Q?'T':'F')<<setw(5)<<(P||Q?'T':'F')<<setw(4)<<(P^Q?'T':'F')<<setw(7)
            //Next  3 Statement Forms:
                <<((P^Q)^Q?'T':'F')<<setw(8)<<((P^Q)^P?'T':'F')<<setw(7)<<(!(P&&Q)?'T':'F')<<setw(8)
            //Final 3 Statement Forms:
                <<(!P||!Q?'T':'F')<<setw(7)<<(!(P||Q)?'T':'F')<<setw(8)<<(!P&&!Q?'T':'F')<<endl;
        }
    }
    //Exit the Program - Cleanup.
    return 0;
}