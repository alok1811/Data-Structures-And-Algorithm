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
}
// Optimal
Node* middleNode(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    // Example input
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    // Convert array to linked list
    Node* head = convertArrToLL(arr);

    cout << "Linked List: ";
    traverse(head);

    // Find middle node
    Node* mid = middleNode(head);
    cout << "Middle Node: " << mid->data << endl;

    return 0;
}
// Brute
/*Node* middle (Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
    count++;
    temp = temp->next;
    }
    temp = head;
    int middle  =(count / 2) + 1;
    for(int i = 1; i < middle; i++){
    temp = temp->next;
    }
    return temp;
}*/

// Both the approach use the same time complexity of O(n)