#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* searchBST(TreeNode* root, int val) {
    while(root!=NULL && root->val !=val){
        root=val < root-> val ? root->left:root->right;
    }
    return root;
}

int ceil(TreeNode* root, int key) {
    int ceil = -1;
    
    while (root) {
        if (root->val == key) {
            ceil = root->val;
            return ceil;
        }

        if (key > root->val) {
            root = root->right;
        } else {
            ceil = root->val;
            root = root->left;
        }
    }
    
    return ceil;
}

int floor(TreeNode* root, int key) {
    int floor = -1;
    
    while (root) {
        if (root->val == key) {
            floor = root->val;
            return floor;
        }

        if (key < root->val) {
            root = root->left;
        } else {
            floor = root->val;
            root = root->right;
        }
    }
    
    return floor;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr=root;
        while(true){
            if(curr->val<=val){
                if(curr->right != NULL) curr=curr->right;
                else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }else{
                if(curr->left != NULL) curr=curr->left;
                else{
                   curr->left=new TreeNode(val);
                    break; 
                }
            }
        }
        return root;
    }

TreeNode* findLastRight(TreeNode* root) {
    if (root->right == NULL) {
        return root;
    }

    return findLastRight(root->right);
}
TreeNode* helper(TreeNode* root) {
    if (root->left == NULL) {
        return root->right;
    } 
    else if (root->right == NULL) {
        return root->left;
    }

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);

    lastRight->right = rightChild;
    return root->left;
}



TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == key) {
        return helper(root);
    }

    TreeNode* dummy = root;

    while (root != NULL) {
        if (root->val > key) {
            if (root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } 
            else {
                root = root->left;
            }
        } 
        else {
            if (root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } 
            else {
                root = root->right;
            }
        }
    }

    return dummy;
}

    void inorderTraversal(TreeNode* node, vector<int>& values) {
        if (node) {
            inorderTraversal(node->left, values);
            values.push_back(node->val);
            inorderTraversal(node->right, values);
        }
    }

int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        inorderTraversal(root, values);        
        return  values[k - 1];
    }

TreeNode* inorderSuccessor(TreeNode* root, int key) {
    TreeNode* ans=NULL;
    while(root!=NULL){
        if(key >=root->val){
            root=root->right;
        }else{
            ans=root;
            root=root->left;
        }
    }
    return ans;
}

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Print subtree in level order
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int val;
    cin >> val;

    TreeNode* root = buildTree(nodes);

    TreeNode* searchresult = searchBST(root, val);

    printTree(searchresult);

    cout<<ceil(root,5)<<endl;
    cout<<floor(root,5)<<endl;

    TreeNode* insertresult = insertIntoBST(root, 9);

    printTree(insertresult);

    TreeNode* deleteResult = deleteNode(root, 6);

    printTree(deleteResult);
    cout<<kthSmallest(root,3)<<endl;

    TreeNode* ans = inorderSuccessor(root, 4);

    if (ans) cout << ans->val << endl;
    else cout << "null" << endl;

    return 0;
}