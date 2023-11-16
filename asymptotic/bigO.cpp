#include <iostream>
using namespace std;

// O(1)
void printElement(int arr[], int index){
    cout << arr[index];
    cout << endl;
}

// O(n^2)
void insertionSort(int arr[], int length){
    for( int currentIndex=1; currentIndex < 6; currentIndex++ ){
        int key = arr[currentIndex];

        int previousIndex = currentIndex-1;

        while( previousIndex >= 0 && arr[previousIndex] > key){

            arr[previousIndex+1] = arr[previousIndex];
            previousIndex = previousIndex-1;
        }
        arr[previousIndex+1] = key;

        // Print after each interation 
        for(int i = 0; i < 6 ; i++){
            cout << arr[i];
        };
        cout << endl;
    }
}

// O(n^3)
// for(...)
//     for(...)
//         for(...)
//
// O(n^n)
int multidimensionalForLoop(int n, int m){
    if(m == 0 ) return 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += multidimensionalForLoop(n, m-1);
    }
    return sum;
}

int main()
{
    int nums[] = { 5,2,4,6,1,3 };
    int length = 6;

    printElement(nums, 4);
    cout << endl;

    insertionSort(nums, length);
    cout << endl;

    int result = multidimensionalForLoop(3,4);
    cout << result << endl;
}