#include <iostream>
#include "DLL.h"
using namespace std;

int main(){
    DoublyLinkedList<int> dll;

    dll.insertAtBeginning(1);
    dll.insertAtBeginning(2);
    dll.insertAtBeginning(3);
    dll.insertAtBeginning(4);
    dll.insertAtBeginning(5);
    dll.insertAtEnd(6);

    dll.display();
    dll.displayHead();
    dll.displayTail();
}