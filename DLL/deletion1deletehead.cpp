#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* prev1, Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        prev = NULL;
        next = NULL;
    }
};
Node* convertARRtoDLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i],mover,NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* deletehead(Node* head){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}
void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next; 
    }
}
int main(){
    vector<int> arr = {23,67,21,11,9};
    Node* head = convertARRtoDLL(arr);
    traverse(head);
    cout << endl;
    head = deletehead(head);
    traverse(head);
}