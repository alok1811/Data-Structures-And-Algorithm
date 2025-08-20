#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = NULL;
        
    }
};
Node* convertARRtoDLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
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
Node* insertbeforetail(Node* head, int val){
    if(head->next == NULL){
        Node* newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* back = tail->prev;
    Node* newNode = new Node(val, tail, back);
    tail->prev = newNode;
    back->next = newNode;
    return head;
}
int main(){
    vector<int> arr = {23,67,21,11,9};
    Node* head = convertARRtoDLL(arr);
    traverse(head);
    cout << endl;
    head = insertbeforetail(head,5);
    traverse(head);
}
