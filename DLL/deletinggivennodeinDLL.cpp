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
    Node* back = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i],NULL,back);
        back->next = temp;
        back = temp;
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
void deleteNode(Node* temp){
    Node* front = temp->next;
    Node* back = temp->prev;

    if(front == NULL){
        back->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;

    temp->next = temp->prev = NULL;
    delete temp;
    

}
int main(){
    vector<int> arr = {23,67,21,11,9};
    Node* head = convertARRtoDLL(arr);
    traverse(head);
    cout << endl;
    deleteNode(head->next);
    traverse(head);
}