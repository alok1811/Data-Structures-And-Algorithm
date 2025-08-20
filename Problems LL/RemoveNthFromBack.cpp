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
Node* convertARRtoLL(vector<int> &arr){
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
}
Node* removeNthFromback(Node* head, int n){
    Node* fastp = head;
    Node* slowp = head;

    for(int i = 0; i < n; i++){
        fastp = fastp->next;
    }

    if(fastp == NULL){
        return head->next;
    }

    while(fastp->next != NULL){
        fastp = fastp->next;
        slowp = slowp->next;
    }

    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete(delNode);
    return head;
}
int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertARRtoLL(arr);

    cout << "Original Linked List: ";
    traverse(head);
    cout << endl;

    int n = 2;
    head = removeNthFromback(head, n);

    cout << "Linked List after removing " << n << "th node from the end: ";
    traverse(head);
    cout << endl;

    return 0;
}
