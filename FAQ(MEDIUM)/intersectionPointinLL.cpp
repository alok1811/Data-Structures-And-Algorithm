#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = NULL;
    }
};
Node* convertArrToLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<< endl;
}
// Brute
Node* intersectionNode(Node* head1, Node* head2){
    unordered_set<Node*> nodes_set;
    Node* temp = head1;
    while(temp != NULL){
        nodes_set.insert(temp);
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL){
        if(nodes_set.find(temp) != nodes_set.end()){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {9, 8};

    Node* head1 = convertArrToLL(arr1);
    Node* head2 = convertArrToLL(arr2);

    // Create an intersection manually
    head2->next->next = head1->next->next;  // Intersect at node with value 3

    cout << "List 1: ";
    traverse(head1);

    cout << "List 2: ";
    traverse(head2);

    Node* inter = intersectionNode(head1, head2);

    if (inter != NULL) {
        cout << "Intersection at node with value: " << inter->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}
