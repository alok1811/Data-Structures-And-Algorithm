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
    }
};
Node* convertARRtoLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i],NULL);
        mover->next = temp;
        mover = temp;

    }
    return head;
}
void traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
Node* insertathead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}
int main(){
    vector<int> arr = {2,43,12,55};
    Node* head = convertARRtoLL(arr);
    traverse(head);
    cout <<"\n";
    head = insertathead(head,69);
    traverse(head);
}
