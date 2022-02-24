/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on February 23, 2022, 1:40 PM
 * Purpose:  XOR Equivalence Lab 
 * Proving: (p&&q)||~(p||q) = !(p^q) 
 * And That (p||q)&&~(p&&q) = p^q
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
    cout<<"XOR Equivalence Lab: \n"
        <<"Proving: (p&&q)||~(p||q) = !(p^q)\n"
        <<"Proving: (p||q)&&~(p&&q) = p^q\n"<<endl;
    //Truth Table Header:
    cout << "P Q P&&Q P||Q !(P&&Q) !(P||Q) P^Q (P||Q)&&!(P&&Q) !(P^Q) (P&&Q)||!(P||Q)" << endl;
    //Using a for loop, I test out all various truth value combinations.
    for(int P=1;P>=0;P--){     //Outer Loop for P.
        for(int Q=1;Q>=0;Q--){ //Inner Loop for Q.
            //First 3 Conditions:
            cout<<(P?'T':'F')<<" "<<(Q?'T':'F')<<setw(4)<<(P&&Q?'T':'F')<<setw(5)
            //Next  2 Statement Forms:
                <<(P||Q?'T':'F')<<setw(6)<<(!(P&&Q)?'T':'F')<<setw(8)
            //Next  3 Statement Forms:
                <<(!(P||Q)?'T':'F')<<setw(6)<<(P^Q?'T':'F')<<setw(10)<<(((P||Q)&&!(P&&Q))?'T':'F')
            //Final 2 Statement Forms:
                <<setw(12)<<(!(P^Q)?'T':'F')<<setw(11)<<(((P&&Q)||!(P||Q))?'T':'F')<<endl;
        }
    }
    //Exit the Program - Cleanup.
    return 0;
}