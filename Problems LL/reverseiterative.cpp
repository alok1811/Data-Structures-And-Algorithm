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
Node* convertARRtoLL(vector<int> &arr){
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
Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = convertARRtoLL(arr);

    cout << "Original Linked List: ";
    traverse(head);
    cout << endl;

    Node* reversedHead = reverseLL(head);

    cout << "Reversed Linked List: ";
    traverse(reversedHead);
    cout << endl;

    return 0;
}
