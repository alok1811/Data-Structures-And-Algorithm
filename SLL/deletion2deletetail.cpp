#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
    }
};
Node* ConvertARRtoLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    int n = arr.size();
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i],NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void traversal(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data <<" ";
        temp  = temp->next;
    }
}
Node* deletetail(Node* head){
    if(head == NULL || head->next == NULL)return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}
int main(){
    vector<int> arr = {2,43,12,55};
    Node* head = ConvertARRtoLL(arr);
    traversal(head);
    cout <<"\n";
    head = deletetail(head);
    traversal(head);
}