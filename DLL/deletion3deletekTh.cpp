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
        next = NULL;
        prev = NULL;
    }
};
Node* convertARRtoDLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], mover, NULL);
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
Node* deletetail(Node* head){
    if(head == NULL||head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* back = temp->prev;
    back->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}
Node* deleteKth(Node* head,int k){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* front = temp->next;

    if(back == NULL && front == NULL){
        return NULL;
    }
    else if(back == NULL){
        return deletehead(head);
    }
    else if(front == NULL){
        return deletetail(head);
    }

    back->next = front;
    front->prev = back;

    temp->next = NULL;
    temp->prev = NULL;
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
    head = deleteKth(head,5);
    traverse(head);
}