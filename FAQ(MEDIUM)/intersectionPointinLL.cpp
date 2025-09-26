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
    public:
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
    cout<< endl;
}
// Brute
// Node* intersectionNode(Node* head1, Node* head2){
//     unordered_set<Node*> nodes_set;
//     Node* temp = head1;
//     while(temp != NULL){
//         nodes_set.insert(temp);
//         temp = temp->next;
//     }
//     temp = head2;
//     while(temp != NULL){
//         if(nodes_set.find(temp) != nodes_set.end()){
//             return temp;
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }
/* better

Node* intersectionPoint(Node* head1, Node* head2){
      temp1 = head1;
      temp2 = head2;

      int n1 = 0; int n2 = 0;
      while(temp1 != NULL){
      n1++;
      temp1 = temp1->next;
      }
      while(temp2 != NULL){
      n2++;
      temp2->next;
      }
      if(n1 < n2) return collisionpoint(Node* head1, Node* head2, n2 - n1);
      else return collisonpoint(Node* head2, Node* head1, n1 - n2);
}

Node* collisionpoint(Node* heada, Node* headb, int len){
    Node* t1 = heada;
    Node* t2 = headb;
    for(int i = 0 ; i < len; i++){
    t2 = t2->next;
    }
    while(t1 != t2){
      t1 = t1->next;
      t2 = t2->next;

    }
      return t1;
}
*/

Node* intersectionNode(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;

        if(t1 ==  t2) return t1;
        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    return t1;
}
int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {9, 8};

    Node* head1 = convertArrToLL(arr1);
    Node* head2 = convertArrToLL(arr2);

    // Create an intersection manually
    head2->next->next = head1->next->next;  // Intersect at node with value 3

    cout << "List 1: ";
    traverse(head1);

    cout << "List 2: ";
    traverse(head2);

    Node* inter = intersectionNode(head1, head2);

    if (inter != NULL) {
        cout << "Intersection at node with value: " << inter->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}
