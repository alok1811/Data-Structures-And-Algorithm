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
Node* convertARRtoLL(vector<int>& arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i],NULL);
        mover->next =temp;
        mover = temp;
    }
    return head;
}
void traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node* insertBeforeVal(Node* head, int el, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        return new Node(el,head);

    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el,temp->next);
            
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {2,43,12,55};
    Node* head = convertARRtoLL(arr);
    traverse(head);
    cout <<"\n";
    head = insertBeforeVal(head,69,12);
    traverse(head);
}
