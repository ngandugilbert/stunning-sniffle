// This is the basics of utusoka

#include<iostream>
using namespace std;

// start by first creating a structure that defines the Node
struct Node{
    // has a data section
    int data;
    // and an address to the next node and this must be of the same Node structure
    // This is pointer
    Node *next;

};

int main(){

    //Now we interact with the node to create a linked list by first allocating the containers of the lists
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL; // created the pointers, now lets create the actual

    // This is the actual creation of the node containers
    one = new Node;
    two = new Node;
    three = new Node;

    // assign some values to the containers
    one->data = 12;
    two->data = 14;
    three->data = 28;

    // create the links between  the nodes

    one->next = two;
    one->next = three;
    three->next = NULL;






    return 0;
}
