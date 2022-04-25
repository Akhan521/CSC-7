/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on April 25th, 2022, 2:15 PM
 * Purpose:  Combinations w/ Pascal's Triangle.
 * 
 * Pascal's Triangle can be used to determine the binomial coefficients
 * used to represent (p+q)^N. 
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>    //Format Library
#include <cmath>      //Math Library
using namespace std;

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
int bCoeff(int,int); //Returns the coefficient or Pascal's Triangle value.

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n; //# of rows in our Triangle.
    int m; //# of elements to choose from.
    
    //Initialize Variables
    n=5;
    m=2;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"                  Column"<<endl;
    cout<<" Row";
    for(int col=0;col<=n;col++){ //We'll have as many cols. as rows.
        cout<<setw(5)<<col<<" "; //Outputting our cols.
    }
    cout<<endl;
    //Outputting Pascal's Triangle:
    for(int row=0;row<=n;row++){
        cout<<setw(4)<<row;
        //Outputting the coefficients for the current row.
        //Every row will have exactly row+1 coeffs., so we go from 0-row.
        for(int col=0;col<=row;col++){
            //The coefficient for the given row and column:
            cout<<setw(5)<<bCoeff(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<m<<" Elements Chosen From a Set of "<<n<<" Elements: "<<endl;
    cout<<n<<"C"<<m<<" = "<<bCoeff(n,m);
    cout<<" Combinations";
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations:

//Returns the binomial coefficient or Pascal's Triangle value.
//Row and Col #ing begin at 0. When the col=0, we have our leftmost 1.
//When the row=col, we have our rightmost 1.
//Otherwise, we take the sum of the two terms above.
int bCoeff(int n,int m){
    //Base Condition:
    if(m==0)return 1; //If the col=0, we have our left-most 1.
    if(n==m)return 1; //If the row=col, we have our right-most 1.
    
    //Recursion: (Take the sum of the 2 terms above.)
    //(Term on the previous row & col) + (Term on the previous row current col).
    /*
    * For Ex: The 2 in 121 = 1 (R1C0) + 1 (R1C1) = 2 (R2C1).
    * 
    * Row   0 1 2 (Column)
    * 0     1
    * 1     1 1
    * 2     1 2 1 
    * ... 
    */ 
    return bCoeff(n-1,m-1)+bCoeff(n-1,m);
}

/*
* N 
* 0       1
* 1      1 1
* 2     1 2 1    *Notice that 2 = 1 + 1 above it.
* 3    1 3 3 1   *Notice that 3 = 1 + 2 above it.
* 4   1 4 6 4 1  *Notice that 6 = 3 + 3 above it.
*
* In general, if we're not at the ends, we take the sum of the 2 terms above. 
*/