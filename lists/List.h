#include <iostream>
using namespace std;

template<class THING>
class List
{
    private:
        class Node {
            public:
                THING data;   
                Node *next; // Pointer to next node is the DLL
                // Node *previous; // Pointer to the previous node in the DLL
                
                // Constructor
                Node(THING x){
                    data = x;
                    next = NULL;
                }
        };

        // Pointers to head and tail
        Node *head;
        Node *tail;

    public:

        List(){
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
                head = newNode;
            }
        }

        void insertAtEnd(THING x){
            if (head == NULL) {  
                insertAtBeginning(x); 
            }else{
                Node *newNode = new Node(x);  
                tail->next = newNode;
                tail = newNode;
            }
        }

        void deleteHead(){
            if(head == tail){
                cout << "head is tail" << endl; // Remove
                head = NULL;
                tail = NULL;
            }else{
                cout << "head is not tail" << endl; // Remove
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void displayHead(){
            if(head == NULL){
                cout << "Array empty" << endl;
                return;
            }
            cout << "Head: " <<head->data << endl;
        }

        void displayTail(){
            if(head == NULL){
                cout << "Array empty" << endl;
                return;
            }
            cout << "Tail: " << tail->data << endl;
        }

        void display(){
            if(head == NULL){
                cout << "Array empty" << endl;
                return;
            }
            Node *temp = head;  

            cout << "List: ";
            while (temp != NULL) {  
                cout << temp->data << " ";  
                temp = temp->next;  
            }
            cout << endl;
            delete temp;
        }

        void remove(THING x){
            Node *temp = head;  
            Node *previous = head;  

            // If first element is being removed
            if(temp->data == x){
                cout << "Head is being removed." << endl;
                deleteHead();
                return;
            }

            // Start at the next item
            temp = temp->next;

            while (temp != NULL) {  

                // If last element is being removed
                if(temp->data == x && temp->next == NULL){
                    cout << "Tail is being removed." << endl;
                    tail = previous;
                    tail->next = NULL;
                    delete temp;
                    return;
                }

                if(temp->data == x){
                    previous->next = temp->next;
                    delete temp;
                    return;
                }

                previous = temp;
                temp = temp->next; 
            }

            cout << "Item not found" << endl;
            delete temp;
        }
};