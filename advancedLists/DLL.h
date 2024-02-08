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

        // void insert(){}
        
        void search(THING x){
            Node *temp = head;

            while (temp != NULL) {  

                if(temp->data == x){
                    cout << x  << " found." << endl;  
                    delete temp;
                    return;
                }
                temp = temp->next;  
            }
            delete temp;
            cout << x << " not found." << endl;  
        }

        void max(){
            Node *temp = head;
            int maxSoFar = temp->data;
            temp = temp->next;  

            while (temp != NULL) {  
                if(temp->data > maxSoFar){
                    maxSoFar = temp->data;
                }
                temp = temp->next;  
            }
            delete temp;
            cout << "The max element is " << maxSoFar << endl;  
        }

        // void predecessor(){}
        
        void rank(THING x){
            Node *temp = head;
            int count = 0;

            while (temp != NULL) {  
                if(temp->data < x){
                    count++;
                }
                temp = temp->next;  
            }
            delete temp;
            cout << count  << " element(s) less than " << x << endl;  
        }

        // void remove(){}
        // void enumerate(){}

        void removeHead(){
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void removeTail(){
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