/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on March 7, 2022, 10:30 AM
 * Purpose: Luhn Algorithm Lab 2
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
using namespace std;

//Global Constants
//The ALL Type could be any of the 4 given CC types.
enum CrdCard{AMEX,VISA,MSTRCRD,DSCVR,ALL};
//AMEX = 0, VISA = 1, MSTRCRD = 2, DSCVR = 3, ALL = 4.

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
void prpLuhn(char[],int); //Prepares the Luhn Sequence
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
void output(char[],int);  //Output the sequence as integers
void Luhn(char[],int);    //Calculate and Append the Luhn Digit
//New Functions Added:
char *genCC(CrdCard);     //Generates a valid CC given the card type.
void flipDig(char []);    //Randomly flip only 1 digit of our CC number.
bool validCC(char[]);     //Determines if our CC is valid.

int main(int argc, char** argv) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare And Initialize Variables:
    int nCrds=10000;    //# of cards to generate.
    int nVld,nInvld;    //# of Valid/Invalid CC Numbers.
    
    //Set the Credit Cards up using the enumerated data type.
    //The genCC function returns a valid credit card number.
    for(int i=0;i<nCrds;i++){
        //Generate any 1 of the 4 CC types:
        char *crdCard=genCC(ALL);
        cout<<"CC Before Flipped Digit = "<<crdCard<<endl;
        //Randomly flip only 1 digit of our CC.
        flipDig(crdCard);
        cout<<"CC After Flipped Digit  = "<<crdCard<<endl;
        //Test the modified CC # for validity.
        validCC(crdCard)?nVld++:nInvld++;
        //Deallocate memory for every CC we create using genCC(TYPE).
        delete []crdCard;
        cout<<endl;
    }
    cout<<endl;
    //Output the percentages of valid/invalid CC's w/ respect to the total.
    cout<<"\t CC Statistics:\n";
    cout<<"----------------------------------\n";
    cout<<"Total # of Cards Generated  = "<<nCrds<<endl;
    cout<<"Number of Valid Cards       = "<<nVld<<endl;
    cout<<"Number of Invalid Cards     = "<<nInvld<<endl;
    cout<<"Percentage of Valid Cards   = "<<100*static_cast<float>(nVld)/nCrds<<"%"<<endl;
    cout<<"Percentage of Invalid Cards = "<<100*static_cast<float>(nInvld)/nCrds<<"%"<<endl;
    
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

char *genCC(CrdCard type){
    int size;    //Size of our CC given the CC type.
    char *cc;    //Our credit card that we will generate.
    //If the CC type is ALL:
        //We want to choose a random card between the 4 types we have.
        //We can use a random # between 0 and 3 to choose our CC type.
    if(type==ALL){
        //AMEX = 0, VISA = 1, MSTRCRD = 2, DSCVR = 3, ALL = 4.
        type=static_cast<CrdCard>(rand()%ALL);
    }
    switch(type){
        case AMEX:{
            size=16; //AMEX Cards Have 15 Digits + 1 for the null terminator.
            cc=new char[size]; //Allocate enough memory for an AMEX.
            cc[0]='3'; //The first digit will always be a 3 for AMEX.
            //The 2nd digit is either a 4 or 7, so we'll randomly choose.
            //If the random # is <= 4, we set it as 4. Otherwise, it's a 7.
            rndDgit()<='4'?cc[1]='4':cc[1]='7';
            //Set up the rest of the card (Until the 2nd to last digit).
            prpLuhn(cc,size-2);
            //Using the Luhn Algorithm, we fill in the last digit.
            Luhn(cc,size);
        }
            break;
        case VISA:{
            size=17; //VISA Cards Have 16 digits + 1 for the null terminator.
            cc=new char[size]; //Allocate enough memory for a VISA.
            cc[0]='4'; //The first digit will always be a 4 for VISA.
            //Set up the rest of the card (Until the 2nd to last digit).
            prpLuhn(cc,size-2);
            //Using the Luhn Algorithm, we fill in the last digit.
            Luhn(cc,size);
        }
            break;
        case MSTRCRD:{
            size=17; //MasterCard Cards Have 16 digits + 1 for the null terminator.
            cc=new char[size]; //Allocate enough memory for a MasterCard.
            cc[0]='5'; //The first digit will always be a 5 for MasterCard.
            //The 2nd digit will always be anything between a 1 and 5, inclusive.
            int temp=rndDgit();        //Get a random # between 0-9.
            while(temp>'5'||temp<'1'){ //As long as the # is not between 1-5, we loop.
                temp=rndDgit();        //Set a new random #.
            }
            //Once we get a # between 1-5, we set it as the 2nd digit of our MC card.
            cc[1]=temp;
            //Set up the rest of the card (Until the 2nd to last digit).
            prpLuhn(cc,size-2);
            //Using the Luhn Algorithm, we fill in the last digit.
            Luhn(cc,size);
        }
            break;
        case DSCVR:{
            size=17; //Discover Cards Have 16 digits + 1 for the null terminator.
            cc=new char[size]; //Allocate enough memory for a Discover Card.
            //The first 4 digits are always 6011 for a Discover Card.
            cc[0]='6',cc[1]='0',cc[2]=cc[3]='1';
            //Set up the rest of the card (Until the 2nd to last digit).
            prpLuhn(cc,size-2);
            //Using the Luhn Algorithm, we fill in the last digit.
            Luhn(cc,size);
        }
            break;
        default: 
            cout<<"You don't know what you are doing.\n";
            break;
    }
    return cc;
}

void flipDig(char cc[]){
    int numDgts; //The # of digits our CC has.
    cc[0]=='3'?numDgts=15:  //AMEX has 15 digits.
               numDgts=16;  //The rest have 16 digits.
    //Randomly flip only 1 digit from our CC number.
    //We don't want to flip the check digit held in the last index, so
    //we choose a random index that is NOT the last index.
    //For ex: If we had VISA, numDgts=16. We'd want an index between 0-14
    //because index 15 has our check digit, so we mod rand() by numDgts-1.
    //rand()%(16-1) = rand()%15 which returns a random # between 0-14.
    cc[rand()%(numDgts-1)]=rndDgit();
}

bool validCC(char cc[]){
    //We're able to get the Luhn digit before a digit is flipped because our 
    //flipDig function doesn't change the Luhn digit in the last index.
    char LuhnDgt; //The Luhn digit before a random digit is flipped.
    int size;     //The size of our CC (# of digits in our CC). 
    //The Luhn Digit is held in the last index of each CC number.
    cc[0]=='3'?size=15, LuhnDgt=cc[size-1]:  //AMEX has 15 digits.
               size=16, LuhnDgt=cc[size-1];  //The rest have 16 digits.
    //Assuming a digit has already been flipped using the flipDig function,
    //We now want to calculate the new Luhn digit given the modified CC number.
    Luhn(cc,size+1);
    //Return true if the Luhn digits match (Valid CC). Otherwise, return false (Invalid CC).
    //If the new Luhn digit matches with the previous Luhn digit, the CC is valid.
    if(cc[size-1]==LuhnDgt){
        cout<<"VALID";
    }else 
        cout<<"INVALID";
    return (cc[size-1]==LuhnDgt)?true:false;
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
    //Now that we have different card types, we need to know where to begin.
    //For example, AMEX cards always start with a 3 and either a 4 or 7.
    //So, we have to generate the rest of the card from the 3rd digit onwards.
    int start; //The index we'll start generating digits from.
    cc[0]=='4'?start=1: //For VISA cards, we begin from the 2nd digit.
    cc[0]=='6'?start=4: //For Discover cards, we begin from the 5th digit.
               start=2; //For MC & AMEX, we begin from the 3rd digit.
    
    //Create a random cc in prep for Luhn checksum.
    for(int i=start;i<n;i++){
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