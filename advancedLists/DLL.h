#include <iostream>
using namespace std;

template<class THING>
class DoublyLinkedList
{
    private:
        class Node {
            public:
                THING data;   
                Node *next; // Pointer to next node is the DLL
                Node *previous; // Pointer to the previous node in the DLL
                
                // Constructor
                Node(THING x){
                    data = x;
                    next = NULL;
                    previous = NULL;
                }
        };

        // Pointers to head and tail
        Node *head;
        Node *tail;

    public:

        DoublyLinkedList(){
            head = NULL;
        }

        void insertAtBeginning(THING x){
            Node *newNode = new Node(x);

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
        }

        void insertAtEnd(THING x){
            if (head == NULL) {  
                insertAtBeginning(x); 
            }else{
                Node *newNode = new Node(x);  
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
        }

        void deleteHead(){
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void deleteTail(){
            Node *temp = tail;
            tail = tail->previous;
            delete temp;
        }

        void displayHead(){
            cout << "Head: " <<head->data << endl;
        }

        void displayTail(){
            cout << "Tail: " << tail->data << endl;
        }

        void display(){
            Node *temp = head;  

            cout << "List: ";
            while (temp != NULL) {  
                cout << temp->data << " ";  
                temp = temp->next;  
            }
            cout << endl;
            delete temp;
        }
};