/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on June 15th, 2022, 9:25 PM
 * Purpose: Merge Sort Algorithm
 * 
 * EXPLANATION:
 * The merge sort algorithm is a recursive algorithm w/ a time complexity of
 * O(nlogn). It has two steps: dividing the array into subarrays and merging 
 * the sorted subarrays. We start by dividing our array into 2 subarrays. We 
 * then divide each subarray into 2 subarrays, and we continue to divide our
 * subarrays into halves until we end up with subarrays of 1 element each. At
 * this point, we have sorted subarrays because arrays of length 1 are sorted
 * by default. We then work our way back up by merging these sorted subarrays
 * with one another. 
 * 
 * HOW DO WE MERGE SUBARRAYS?
 * We begin by comparing the 1st elements of both subarrays and add the smaller 
 * of the two into our merged array. We continue comparing values in pairs to
 * decide in what order to add our values into our merged array. By the end,
 * we should have a merged subarray that is sorted.
 * 
 * FOR EXAMPLE: Suppose we had [1,3] and [2,4,5]. We'd compare 1 and 2.
 * Since 1 is smaller, we add 1 to our merged array -> [1,?,?,?,?]. We'd then
 * compare 3 and 2. 2 is smaller, so we'd add 2 next -> [1,2,?,?,?]. We'd then
 * compare 3 and 4. We'd add 3 since it's smaller -> [1,2,3,?,?]. We then add 
 * the remaining values into our merged array -> [1,2,3,4,5].
 * NOTE: If we've added all of the values from one array, we'd need to add the 
 * remaining values from the other array to our merged array. In our example, we
 * had added all of the values in our 1st array after the 3 was added. Since there
 * were no longer any elements to add in our 1st array, we added the remaining 
 * values from our 2nd array (4 & 5) to our merged array to complete the merge.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Rand + Srand
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void fillAry(int [],int);                 //Generate a random array of #'s.
void print(int [],int,int);               //Print an array of numbers.
void mergeSort(int [],int);               //The recursive merge sort algorithm.
void merge(int [],int [],int [],int,int); //The merge function used in mergeSort
                                          //to merge two subarrays into 1 array.
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables:
    int size=100;
    int array[size];
    
    //Map Inputs to Outputs -> Process:
    fillAry(array,size);
    
    //Display Inputs/Outputs:
    cout<<"Before (Unsorted): \n";
    print(array,size,10);
    //Call the Merge Sort:
    mergeSort(array,size);
    cout<<"After (Sorted): \n";
    print(array,size,10);
    
    //Exit the Program - Cleanup
    return 0;
}

void fillAry(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10; //10-99.
    }
}

void print(int array[], int size, int perLine){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%perLine==perLine-1)
            cout<<endl;
    }
    cout<<endl;
}
void mergeSort(int array[],int size){
    //Base Condition: 
    //An array of size 1 is sorted by default, so we exit the function.
    //Otherwise, we continue to split our array into halves (subarrays). 
    if(size==1){
        return;
    }
    //Halving our Array:
    int midPnt = size/2;    //Find the midpoint.
    int left[midPnt];       //Create the left half of our array.
    //We need to specify "size-midPnt" to account for an odd # of elements.
    int right[size-midPnt]; //Create the right half or our array.
    //Fill our Sub-Arrays:
    for(int i=0;i<midPnt;i++)     //Our left half.
        left[i]=array[i];
    for(int i=midPnt;i<size;i++)  //Our right half.
        //We need to specify "i-midPnt", so that the index of our right half
        //begins at 0 as it should.
        right[i-midPnt]=array[i];
    //Merge Sort our Halves (We want to continue halving our sub-arrays):
    mergeSort(left,midPnt);       //midPnt      -> Size of our left  array.
    mergeSort(right,size-midPnt); //size-midPnt -> Size of our right array.
    //Merge our Sorted Halves (The merge will be stored in array):
    merge(array,left,right,midPnt,size-midPnt);
}

void merge(int array[], int left[], int right[], int lftSze, int rghtSze){
    //Declare our Index Variables for our 3 Arrays:
    int i=0, //For our left half. 
        j=0, //For our right half.
        k=0; //For our merged array.
    //Comparing and Adding our Elements into Our Merged Array:
    //If we've added all of the values in one array, we don't need to compare 
    //anymore, so we'd just need to fill the rest of our merged array with 
    //the remaining values from the other array. 
    while(i<lftSze && j<rghtSze){//If we still have elements in both to compare...
        if(left[i]<=right[j]){ //If the left half contains the smaller of the 2...
            array[k]=left[i];  //We store it in our merged array.
            i++;               //We increment i to check the next element in left.
        }
        else{                  //If the right half contains the smaller of the 2...
            array[k]=right[j]; //We store it in our merged array.
            j++;               //We increment j to check the next element in right.
        }
        k++;                   //We increment k to store the next element in array.
    }
    //If we've added all the values in right, we store the remaining in left
    //into our merged array. (Adding the remaining values to complete array).
    while(i<lftSze){
        array[k]=left[i];
        i++;
        k++;
    }
    //If we've added all the values in left, we store the remaining in right
    //into our merged array. (Adding the remaining values to complete array).
    while(j<rghtSze){
        array[k]=right[j];
        j++;
        k++;
    }
}