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

Node* reverseDLL(Node* head) {
if(head==nullptr||head->next==nullptr){
    return head;
}

    Node* last=nullptr;
    Node* current=head;
    while(current!=nullptr){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    return last->back;
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
    head = reverseDLL(head);
    cout << "Linked list after inserting: ";
    printLinkedList(head);

    return 0;
}
