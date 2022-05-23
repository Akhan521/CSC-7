/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on May 9, 2022, 12:45 PM
 * Purpose: Bloom Filter Lab.
 * 
 * I utilize 9 hashes in this program.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>    //String Library.
#include <vector>    //Vector Library.
#include <cmath>     //Math Library.
//User Libraries
#include "GeneralHashFunctions.h"
using namespace std;

//Execution Begins Here:
int main(int argc, char* argv[])
{
   //Declare + Initialize our variables:
    int n=15,    //Size of our Array/Bit Vector.
        m=0,     //# of keys used for our hashes (# of elements in our list).
        k=9;     //# of hashes utilized.
    char choice; //Whether we'd like to store more elements or not.
    vector<char> bitVctr(n,'0'); //Our "bit vector" or array initialized with 0's.
    vector<string> list;          //Our list of elements/strings.
    
    //Map Inputs to Outputs -> Process
    cout<<"\tBloom Filter Lab:\n";
    do{
        string input; //To hold our string input.
        cout<<"\nEnter a string to hash:\n";
        cin>>input;
        list.push_back(input);
        cout<<endl;
        
        cout<<"FNV Hash Value:  "<<FNVHash(input)%n<<endl;
        cout<<"RS  Hash Value:  "<<RSHash(input)%n<<endl;
        cout<<"PJW Hash Value:  "<<PJWHash(input)%n<<endl;
        cout<<"ELF Hash Value:  "<<ELFHash(input)%n<<endl;
        cout<<"DJB Hash Value:  "<<DJBHash(input)%n<<endl;
        cout<<"DEK Hash Value:  "<<DEKHash(input)%n<<endl;
        cout<<"BP  Hash Value:  "<<BPHash(input)%n<<endl;
        cout<<"AP  Hash Value:  "<<APHash(input)%n<<endl;
        cout<<"JS  Hash Value:  "<<JSHash(input)%n<<endl;
        
        //Setting our bits given our hash values:
        //For the FNV hash:
        bitVctr[FNVHash(input)%n]='1';
        //For the RS hash:
        bitVctr[RSHash(input)%n]='1';
        //For the PJW hash:
        bitVctr[PJWHash(input)%n]='1';
        //For the ELF hash:
        bitVctr[ELFHash(input)%n]='1';
        //For the DJB hash:
        bitVctr[DJBHash(input)%n]='1';
        //For the DEK hash:
        bitVctr[DEKHash(input)%n]='1';
        //For the BP hash:
        bitVctr[BPHash(input)%n]='1';
        //For the AP hash:
        bitVctr[APHash(input)%n]='1';
        //For the JS hash:
        bitVctr[JSHash(input)%n]='1';
        
        //Ask whether we'd like to store another string.
        cout<<"\nWould you like to add another string (Y/N)?\n";
        cin>>choice;      
    }while(choice=='y'||choice=='Y');
    
    //Display Elements in our Set:
    cout<<endl;
    cout<<"\tElements in our Set:\n";
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<endl;
    }
        
    //Testing elements for membership:
    do{
        string input; //To hold our string input.
        cout<<"\nEnter a string to see if it's in our set:\n";
        cin>>input;
        
        //Output which bits have been set:
        cout<<"\nThe following bits have been set:\n";
        for(int i=0;i<bitVctr.size();i++){
            if(bitVctr[i]=='1'){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        
        //Output our hash values for the inputted string:
        /*
        cout<<"FNV Hash Value:  "<<FNVHash(input)%n<<endl;
        cout<<"RS  Hash Value:  "<<RSHash(input)%n<<endl;
        cout<<"PJW Hash Value:  "<<PJWHash(input)%n<<endl;
        cout<<"ELF Hash Value:  "<<ELFHash(input)%n<<endl;
        cout<<"DJB Hash Value:  "<<DJBHash(input)%n<<endl;
        cout<<"DEK Hash Value:  "<<DEKHash(input)%n<<endl;
        cout<<"BP  Hash Value:  "<<BPHash(input)%n<<endl;
        cout<<"AP  Hash Value:  "<<APHash(input)%n<<endl;
        cout<<"JS  Hash Value:  "<<JSHash(input)%n<<endl;
        */ 
        //If the bits have been set for all 9 hash functions, it's highly likely
        //that the element is present in our set or list of elements.
        if(bitVctr[FNVHash(input)%n]=='1'&&bitVctr[RSHash(input)%n] =='1'&&
           bitVctr[PJWHash(input)%n]=='1'&&bitVctr[ELFHash(input)%n]=='1'&&
           bitVctr[DJBHash(input)%n]=='1'&&bitVctr[DEKHash(input)%n]=='1'&&
           bitVctr[BPHash(input)%n] =='1'&&bitVctr[APHash(input)%n] =='1'&&
           bitVctr[JSHash(input)%n] =='1'){
            cout<<"\nPresent? MAYBE!\n";
        }else{
            cout<<"\nPresent? N0.\n";
        }
        //Determine the probability of a false-positive in 2 ways:
        int numHshd=0;   //The number of bits that were set (# of unique hashes).
        float prob=0.0f; //The probability of a fp.
        //Way 1: P = (# of bits set/size of bit vector)^# of hashes.
        //Finding out how many bits were set:
        for(int i=0;i<bitVctr.size();i++){
            if(bitVctr[i]=='1') numHshd++;
        }
        prob=pow((static_cast<float>(numHshd)/n),k);
        prob*=100; //To have it as a %.
        cout<<"\nProbability of a FP (Exact)   = "<<prob<<"%\n";
        //Way 2: P = (1-e^(-km/n))^k, where m = # of elements in our list (NOT # of bits set).
        m=list.size(); //# of elements in our list or the # of keys used in the hash.
        float ratio=(-k*m/static_cast<float>(n));
        prob=pow((1-exp(ratio)),k);
        prob*=100; //To have it as a %.
        cout<<"Probability of a FP (Approx.) = "<<prob<<"%\n";
        cout<<"\nWould you like to test another string (Y/N)?\n";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    
    //Exit the Program - Cleanup
   return 0;
}
