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
                
                Node(THING x){
                    data = x;
                    next = NULL;
                    previous = NULL;
                }
        };

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
                cout << "inserting at beg" << endl;
                insertAtBeginning(x); 
            }else{
                Node *newNode = new Node(x);  

                Node *temp = head;  

                while (temp->next != NULL) {  
                    temp = temp->next;  
                }  
                temp->next = newNode;  
                newNode->previous = temp;
                tail =  newNode;
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
            cout << head->data << " ";
        }

        void displayTail(){
            cout << tail->data << " ";
        }

        void display(){
            Node *temp = head;  

            while (temp != NULL) {  
                cout << temp->data << " ";  
                temp = temp->next;  
            }
        }

};