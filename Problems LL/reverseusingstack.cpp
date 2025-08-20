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
    Node* head= new Node(arr[0]);
    Node* mover =  head;
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
Node* reverseLLUsingStack(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    stack<Node*> st;
    Node* temp = head;

    while(temp != NULL){
        st.push(temp);
        temp = temp->next;
    }

    Node* newHead = st.top();
    st.pop();
    temp = newHead;

    while(!st.empty()){
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return newHead;
}
int main() {
    vector<int> arr = {67, 2, 49, 14, 5};

    Node* head = convertARRtoLL(arr);

    cout << "Original Linked List: ";
    traverse(head);
    cout << endl;

    Node* reversedHead = reverseLLUsingStack(head);

    cout << "Reversed Linked List: ";
    traverse(reversedHead);
    cout << endl;

    return 0;
}
