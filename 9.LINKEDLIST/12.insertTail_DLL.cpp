#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr ,Node* back1=nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int> &arr) {
    if (arr.empty()) return nullptr; // Handle empty array case

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev=temp;
    }
    return head;
}

Node* insertHead(Node* head, int k) {
   Node* temp =new Node(k,head,nullptr);
   head->back=temp;
   return temp;
}

// Function to insert new node of the linked list
Node* insertTail(Node* head, int k) {

     if (head->next== nullptr || k <= 0) return insertHead(head,k);

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* prev=temp->back;
    Node* nnode = new Node(k,temp,prev);
    prev->next = nnode;
    temp->back=nnode;
   

    return head;
}



// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
      int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = convertArr2LL(arr);

    cout << "Original linked list: ";
    printLinkedList(head);

    // print the updated linked list
    head = insertTail(head,2);
    cout << "Linked list after inserting: ";
    printLinkedList(head);

    return 0;
}
