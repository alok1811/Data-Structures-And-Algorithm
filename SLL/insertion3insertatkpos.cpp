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
Node* insertAtk(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(val);
        }
        else return head;
    }
    if(k == 1){
        return new Node(val,head);
    }
    int count = 0; Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k - 1){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
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
    head = insertAtk(head,2,3);
    traverse(head);
}
