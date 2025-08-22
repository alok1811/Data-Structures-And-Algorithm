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
        next = NULL;
    }
};
Node* convertArrToLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i]);
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
    cout << endl;
}
// Brute
Node* deleteMiddle(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    temp = head;
    int middlePos = (count / 2) + 1;
    for(int i = 1; i < middlePos - 1; i++){
        temp = temp->next;
    }
    Node* mid = temp->next;
    temp->next = temp->next->next;
    delete(mid);
    return head;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertArrToLL(arr);
    traverse(head);
    head = deleteMiddle(head);
    traverse(head);
    return 0;
}