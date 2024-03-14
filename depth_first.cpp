#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node* prev;

    Node(int val) : data(val),prev(nullptr), next(nullptr) {}
};

// defines the blueprint for the list
class LinkedList{
public:
    Node *head;
    Node *prev;
    int nodeCount;
public:
    LinkedList() : head(nullptr),prev(nullptr) {} // This is a constructor

     void createNode(int val) {

        Node* newNode = new Node(val);

        if (head == nullptr) {
            prev = head;
            head = newNode;

        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // create a forward
    void toEnd(){
        Node* temp = head;
        while(temp != nullptr){
            temp = temp->next;
        }
        head = temp;
    }
    // create a reverse
    void toStart(){
        Node* temp = head;
        while(nodeCount>=0){
            nodeCount--;

        }
    }


};

int main(){
    LinkedList myList;
    myList.createNode(12);
    myList.createNode(13);
    myList.createNode(14);
    myList.createNode(15);

    myList.toEnd();


    cout<<myList.head->data<<endl;



    return 0;
}
