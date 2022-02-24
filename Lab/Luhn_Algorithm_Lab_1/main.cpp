/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 23, 2022, 3:15 PM
 * Purpose: Luhn Algorithm Lab 1
 * Luhn Function Written By: Aamir Khan
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
void prpLuhn(char[],int); //Prepares the Luhn Sequence
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
void output(char[],int);  //Output the sequence as integers
//Function you are to create
void Luhn(char[],int);    //Calculate and Append the Luhn Digit

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set the Credit Card size
    const int SIZE=17;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    output(crdCard,SIZE-2);
    
    //Credit Card with the appended Luhn Digit.
    Luhn(crdCard,SIZE);
    cout<<"The Luhn Digit with Luhn Encoding = "<<crdCard[SIZE-2]<<endl;
    cout<<"Credit Card With Appended Luhn Digit = "<<crdCard<<endl;
    
    //Exit Stage Right
    return 0;
}

void Luhn(char cc[],int n){
    //From the rightmost digit, we multiply every other digit by 2.
    //The right most digit is at index 14 or n-3 in our case (n=17).
    int sum=0;   //To hold the sum of all of our digits.
    char ccc[n]; //A copy of our cc to perform Luhn's Algo. on.
    //Copying the contents of our credit card.
    for(int i=0;i<n;i++){ccc[i]=cc[i];}
    //Multiplying every other digit by 2 & handling the products.
    for(int i=n-3;i>=0;i-=2){
        //To handle our calculations, we convert ccc[i] to an integer.
        int temp=cnvrt(ccc[i]);
        //Multiply the digit by 2 according to the Luhn Algorithm.
        temp*=2;
        //If the product > 9, we take the sum of the digits.
        //For ex: 5 * 2 = 10 -> 1 + 0 = 1.
        if(temp>9){
            //Dividing by 10 gives us the tens place digit (For ex: 16/10=1).
            //Modding by 10 gives us the ones place digit  (For ex: 16%10=6).
            temp=(temp/10)+(temp%10);
            //Put our calculated sum into ccc[i].
            ccc[i]=cnvrt(temp);
        }
        //If the product <= 9, we put the product into ccc[i] as is.
        else{
            ccc[i]=cnvrt(temp);
        }
    }
    //Calculate the sum of our digits in the cc copy.
    for(int i=0;i<n-2;i++){
        sum+=cnvrt(ccc[i]);
    }
    //Determining the last digit (check digit) of our original cc.
    //We take the product of the sum and 9. Then, we mod by 10.
    //Check Digit = (Sum * 9) % 10 -> Goes into our original cc.
    cc[n-2]=cnvrt((sum*9%10));
    cout<<endl;
}

void output(char cc[],int n){
    cout<<"The char array output as each integer digit"<<endl;
    for(int i=0;i<n;i++){
        cout<<cnvrt(cc[i]);
    }
    cout<<endl;
}

char  cnvrt(int digit){
    if(digit<0||digit>9){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+'0';
    return digit+48;
}

int  cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+'0';//Ascii Code for numbers '0'=48 and '9'=57
    //return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}