#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }  
    
    // Enter data for inserting in left of current node
    root->left = buildTree(root->left);

    // Enter data for inserting in right of current node
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root)
{
    // also known as breadth first search
    queue<node*> q;
    q.push(root);
    q.push(NULL); // to mark the end of the current level

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            // purana level complete transverse ho chuka hai
            cout << endl; // end of current level

            if(!q.empty()) {
                // if queue is not empty, push NULL to mark the next level
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void printPreOrder(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* current = q.front();
        q.pop();

        int leftData, rightData;
        cin >> leftData >> rightData;

        if(leftData != -1) {
            current->left = new node(leftData);
            q.push(current->left);
        }
        if(rightData != -1) {
            current->right = new node(rightData);
            q.push(current->right);
        }
    }

}

int main(){


    node* root = NULL;

    buildFromLevelOrder(root);

    levelOrderTraversal(root);

    

    // // create a tree
    // root = buildTree(root);

    // // level order transversal
    // levelOrderTraversal(root);

    // cout << "Pre-order traversal: ";
    // printPreOrder(root);
    // cout << endl;   
    // cout << "In-order traversal: ";
    // printInOrder(root);
    // cout << endl;
    // cout << "Post-order traversal: ";
    // printPostOrder(root);
    // cout << endl;


    return 0;
}
