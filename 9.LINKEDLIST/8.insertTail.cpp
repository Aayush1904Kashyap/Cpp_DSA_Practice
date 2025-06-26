#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Function to convert an array to a linked list
Node* convertArr2LL(vector<int> &arr) {
    if (arr.empty()) return nullptr; // Handle empty array case

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

// Function to insert new node of the linked list
Node* insertTail(Node* head, int k) {

     if (head == nullptr || k <= 0) return new Node(k);

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* nnode = new Node(k);
    temp->next = nnode;
    nnode->next = nullptr;

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
