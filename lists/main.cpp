#include <iostream>
#include "List.h"
using namespace std;

int main(){
    List<int> list;


    // Insert data
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    list.insertAtBeginning(4);
    list.insertAtBeginning(5);
    list.insertAtEnd(6);

    // Verify before
    list.display();

    // Remove data
    list.remove(3);

    // Verify after
    list.display();
    list.displayHead();
    list.displayTail();
}