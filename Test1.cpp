#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// Define a structure for the nodes in the graph
struct Node {
    int value;
    vector<Node*> children;

    Node(int val) : value(val) {}
};

// Function to perform breadth-first search
bool breadthFirstSearch(Node* start, Node* goal) {
    queue<Node*> open;
    unordered_set<Node*> closed;

    open.push(start);

    while (!open.empty()) {
        Node* current = open.front();
        open.pop();

        if (current == goal) {
            cout << "Goal found!\n";
            return true;
        } else {
            for (Node* child : current->children) {
                if (closed.find(child) == closed.end() && find(open.begin(), open.end(), child) == open.end()) {
                    open.push(child);
                }
            }
            closed.insert(current);
        }
    }

    cout << "Goal not found!\n";
    return false;
}

int main() {
    // Creating nodes
    Node* start = new Node(1);
    Node* goal = new Node(6);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    // Constructing the graph
    start->children.push_back(node2);
    start->children.push_back(node3);
    node2->children.push_back(node4);
    node3->children.push_back(node5);
    node3->children.push_back(goal);

    // Performing breadth-first search
    breadthFirstSearch(start, goal);

    return 0;
}
