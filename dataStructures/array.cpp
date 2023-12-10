#include <iostream>
using namespace std;

template <typename T>
struct Data { 
    T item;
}; 

template <typename T>
void printArray(T arr[], int len){
    for(int i = 0; i< len; i++){
        cout << arr[i].item;
    }
    cout <<'\n';
}

int main() {
    Data myArr[3] = {{1},{2},{3}}; 

    printArray(myArr, 3);

    cout << "Hello World!";
    return 0;
}
