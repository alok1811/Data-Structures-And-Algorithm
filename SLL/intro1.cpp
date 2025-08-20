#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

};
int main(){
    vector<int> arr = {1,2,3,4};
    Node* y1 = new Node(arr[0], nullptr);
    Node* y2 = new Node(arr[1], nullptr);
    Node* y3 = new Node(arr[2], nullptr);
    Node* y4 = new Node(arr[3], nullptr);

    y1->next = y2;
    y2->next = y3;
    y3->next = y4;


    cout << y1->data << " " << y1->next << "\n";
    cout << y2->data << " " << y2->next << "\n";
    cout << y3->data << " " << y3->next << "\n";
    cout << y4->data << " " << y4->next << "\n";

    return 0;
}
