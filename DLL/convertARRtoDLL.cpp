#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* back1, Node* next1){
        data = data1;
        back = back1;
        next = next1;

    }
    Node(int data1){
        data = data1;
        next = NULL;
        back = NULL;
    }
};
Node* convertARRtoDLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], prev, NULL);
        prev->next = temp;
        prev = temp;
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
int main(){
    vector<int> arr = {23,67,21,11,9};
    Node* head = convertARRtoDLL(arr);
    traverse(head);
}