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
// bool isPalindrome(Node* head){
//     stack<int> st;
//     Node* temp = head;
//     while(temp != NULL){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp != NULL){
//         if(temp->data != st.top()) return false;
//         temp = temp->next;
//         st.pop();
//     }
//     return true;
// }

// Optimal

Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverse(slow->next);
    Node* first = head;
    Node* second = newHead;

    while(second != NULL){
        if(first->data != second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 2, 1};
    Node* head = convertArrToLL(arr);
    traverse(head);
    if(isPalindrome(head)) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
    return 0;
}