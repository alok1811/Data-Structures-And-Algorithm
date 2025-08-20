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
Node* addLL(Node* num1, Node* num2){
    Node* dummyhead = new Node(-1);
    Node* curr = dummyhead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyhead->next;
}
int main() {
    vector<int> num1Arr = {9, 9, 9};
    vector<int> num2Arr = {1};

    Node* num1 = convertARRtoLL(num1Arr);
    Node* num2 = convertARRtoLL(num2Arr);

    cout << "Number 1: ";
    traverse(num1);
    cout << endl;

    cout << "Number 2: ";
    traverse(num2);
    cout << endl;

    Node* result = addLL(num1, num2);

    cout << "Sum: ";
    traverse(result);
    cout << endl;

    return 0;
}

