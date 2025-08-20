#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data ;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
    }
};
Node* convertARRtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i],NULL);
        mover->next = temp;
        mover = temp; //or mover = mover->next 
    }
    return head;
}
void LLtraversal(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {9,26,5,4};
    Node* head = convertARRtoLL(arr);
    
    LLtraversal(head);

    return 0;
}
