#include<bits./stdc++.h>
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
Node* oddevenlist(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenhead = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;

    }
    odd->next = evenhead;
    return head;
}
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
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertARRtoLL(arr);

    cout << "Original Linked List: ";
    traverse(head);
    cout << endl;

    head = oddevenlist(head);

    cout << "Reordered Linked List: ";
    traverse(head);
    cout << endl;

    return 0;
}
