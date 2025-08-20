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

Node* sortList(Node* head){
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);
    Node* temp = head;

    Node* zero = zerohead;
    Node* one = onehead;
    Node* two = twohead;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else if(temp->data == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = NULL;

    Node* newHead = zerohead->next;
    delete(zerohead);
    delete(onehead);
    delete(twohead);

    return newHead;
}
int main() {
    vector<int> arr = {2, 1, 0, 2, 1, 0, 1, 2};
    Node* head = convertARRtoLL(arr);

    cout << "Original Linked List: ";
    traverse(head);
    cout << endl;

    head = sortList(head);

    cout << "Sorted Linked List: ";
    traverse(head);
    cout << endl;

    return 0;
}
