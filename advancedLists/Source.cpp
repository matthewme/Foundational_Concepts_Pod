#include <iostream>
#include "DLL.h"
using namespace std;

int main(){
    DoublyLinkedList<int> LL;

    LL.insertAtBeginning(1);
    LL.insertAtBeginning(2);
    LL.insertAtBeginning(3);
    LL.insertAtBeginning(4);
    LL.insertAtBeginning(5);
    LL.insertAtEnd(6);

    LL.display();

    LL.deleteHead();
    
    LL.displayHead();
    LL.displayTail();

}