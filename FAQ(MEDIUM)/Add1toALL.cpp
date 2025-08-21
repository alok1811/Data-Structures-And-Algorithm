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
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL)
    {
        /* code */
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
    
}
Node* Add1toLL(Node* head){
    head = reverse(head);

    Node* temp = head;
    int carry = 1;
    while(temp != NULL){
        int sum = temp->data + carry;
        carry = sum / 10;
        temp->data = sum % 10;

        if(carry == 0){
            break;
        }
        if(temp->next == NULL && carry != 0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    head = reverse(head);
    return head;
}
int main() {
    vector<int> arr = {9, 9, 9};
    Node* head = convertARRtoLL(arr);

    cout << "Original Linked List (Number): ";
    traverse(head);
    cout << endl;

    head = Add1toLL(head);

    cout << "After Adding 1: ";
    traverse(head);
    cout << endl;

    return 0;
}
