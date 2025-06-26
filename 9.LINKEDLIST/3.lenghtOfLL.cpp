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


Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lenghtOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int checkPresent(Node*head,int value){
    Node* temp = head;
    while(temp){
        if(temp->data==value){
            return 1;
        }
        temp=temp->next;
        
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* head=convertArr2LL(arr);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n"<<"the length of LL is "<<lenghtOfLL(head)<<"\n";
    cout<< checkPresent(head,30);
   
}