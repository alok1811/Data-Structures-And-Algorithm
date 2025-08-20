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
        prev = NULL;
    }
};
Node* convertARRtoDLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], NULL, mover);
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
Node* insertbeforeKthNode(Node* head, int k, int val){
    if(k == 1){
        Node* newhead = new Node(val, head, NULL);
        head->prev = newhead;
        return newhead;
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* newNode = new Node(val, temp, back);
    back->next = newNode;
    temp->prev = newNode;

    return head;
}
int main(){
    vector<int> arr = {23,67,21,11,9};
    Node* head = convertARRtoDLL(arr);
    traverse(head);
    cout << endl;
    head = insertbeforeKthNode(head,3,78);
    traverse(head);
}