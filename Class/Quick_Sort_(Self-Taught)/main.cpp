/* 
 * File:   main.cpp
 * Author: Aamir Khan
 * Created on July 2nd, 2022, 6:30 PM
 * Purpose: Quick Sort Algorithm
 * 
 * EXPLANATION:
 * Just like the merge sort, the quick sort is a recursive algorithm w/ a
 * time complexity of O(nlogn). The algorithm can be broken down into 3 steps:
 * 1. Choosing a Pivot & Placing it at the End of Your Array.
 * 2. Partitioning the Array Into 2 Sub-Arrays.
 * 3. Recursively Sorting the Partitions.
 * 
 * What is a Pivot?
 * A pivot is any element that satisfies the following 3 conditions:
 * 1. It's in its correct position in the final, sorted array.
 * 2. To the left of the pivot, values are smaller.
 * 3. To the right of the pivot, values are larger.
 * 
 * What Are Our Partitions?
 * We place all values smaller than the pivot to the left of it, and we place
 * all values larger than the pivot to the right of it. To the left of our pivot,
 * we have a sub-array of values less than the pivot. To the right of our pivot,
 * we have a sub-array of values larger than the pivot. (2 Sub-Arrays).
 * 
 * How Exactly Do We Partition our Array?
 * We'll need to utilize 2 variables that will serve as pointers to elements in 
 * our array. The left pointer will begin from the left and will be used to point
 * to the 1st element that is larger than the pivot. The right pointer will begin 
 * from the right and will be used to point to the 1st element that is smaller than 
 * the pivot. We'll keep moving our pointers forward as we look for these values. 
 * Once we have values for both pointers, we'll swap the 2 values. We will 
 * continue this process until the left and right pointers point to the same value. 
 * At this point, all values that are smaller than the pivot will be together and all
 * values that are larger than the pivot will be together. The very last step is 
 * swapping the pivot with the value being pointed to by the left pointer. This
 * will put the pivot in its correct position (Left pointer will now be pointing to
 * the pivot.)
 * 
 * Once we have our partitions, we simply need to call the quick sort algorithm
 * on our 2 partitions.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Rand + Srand
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void quickSort(int [],int,int);    //Quick Sort Algorithm.
int partition(int [],int,int,int); //Partitions an Array.
void swap(int [],int,int);         //Swaps 2 Values.
void fillAry(int [],int);          //Fills an Array.
void print(int [],int,int);        //Prints an Array.
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed:
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables:
    const int SIZE=100;
    int perLine=10;
    int array[SIZE];
    //Fill the Array:
    fillAry(array,SIZE);
    //Display Inputs/Outputs:
    cout<<"Before Sorting:\n";
    print(array,SIZE,perLine);
    //Perform the Quick Sort:
    quickSort(array,0,SIZE-1);
    cout<<"After Sorting:\n";
    print(array,SIZE,perLine);
    //Exit the Program - Cleanup
    return 0;
}

//This function fills our array w/ random numbers.
void fillAry(int array[], int size){
    for(int i=0;i<size;i++)
        array[i]=rand()%90+10; //10-99.
}

//This function prints our array.
void print(int array[], int size, int perLine){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%perLine==perLine-1)
            cout<<endl;  
    }
    cout<<endl;
}

//We'll need to specify a starting and ending index. This is because we need
//to know where our partitions begin and end when we recursively sort them.
void quickSort(int array[], int start, int end){
    //Base Condition: If we have a partition of just 1 element, then we simply return.
    //Any sub-array of 1 element is already sorted to begin with, so we don't need
    //to further partition and recursively sort the given partition.
    if(start>=end) //If we only have 1 element, we simply do nothing.
        return;
    //Step 1: Choosing a Pivot. We'll just choose the last element as our index.
    //We could choose any element if wanted, but I simply use the last element.
    int pivot=array[end];
    //Step 2: Partitioning our Array.
    //The index that the pivot is at is returned.
    int pivotIdx=partition(array,start,end,pivot);
    //Step 3: Recursively sorting our 2 partitions:
    //We begin at the starting index and end at the element just before the pivot.
    //The pivot is being pointed to by pivotIdx, so pivotIdx-1 is the
    //index of the element just before the pivot. This is our left partition.
    quickSort(array,start,pivotIdx-1);
    //We begin at the element just after the pivot and stop at the end of our
    //array. Again, the pivot is being pointed to by pivotIdx, so pivotIdx+1
    //is the index of element just after the pivot. This is our right partition.
    quickSort(array,pivotIdx+1,end);
}

//This function partitions our array into left and right partitions. 
//It returns the index that the pivot is located at.
int partition(int array[],int start,int end,int pivot){
    //Creating 2 pointer variables:
    int lftPtr=start;   //The starting index.
    int rghtPtr=end-1;  //The ending index (1 index before the pivot).
    //Finding the 1st elements larger and smaller than the pivot:
    while(lftPtr!=rghtPtr){ //As long as they don't point to the same value...
        //Find the 1st element from the left that is larger than our pivot:
        while(array[lftPtr]<=pivot && lftPtr!=rghtPtr)
            lftPtr++;  //We keep incrementing as long as the value is <= pivot.
                       //This is because we want to stop when the value is > pivot.
        //Find the 1st element from the right that is smaller than our pivot:
        while(array[rghtPtr]>=pivot && lftPtr!=rghtPtr)
            rghtPtr--; //We keep decrementing as long as the value is >= pivot.
                       //This is because we want to stop when the value is < pivot.
        //We now need to swap the values being pointed to by both pointers:
        swap(array,lftPtr,rghtPtr);
    }
    //Finally, we swap the pivot with the value being pointed to by left pointer:
    //If the value pointed to by lftPtr is > pivot, then we want to swap the two. 
    //This is when the pivot isn't the largest value. (This is usually the case).
    if(array[lftPtr]>pivot){
        swap(array,lftPtr,end); 
    }
    else{ //However, if the pivot IS the largest value, it stays at the end.
        lftPtr=end; //This would correctly return the index of the pivot if the
                    //pivot happened to be the largest value in the partition.
    }
    //We return lftPtr. This is the index of the pivot.
    return lftPtr;
}

//This function swaps 2 values given their indices.
void swap(int array[],int idx1,int idx2){
    int temp=array[idx1];
    array[idx1]=array[idx2];
    array[idx2]=temp;
}