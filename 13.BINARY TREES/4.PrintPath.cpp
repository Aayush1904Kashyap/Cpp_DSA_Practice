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

bool getPath(TreeNode* root,vector<int>& arr,int x){
    if(!root)return false;

    arr.push_back(root->val);

    if(root->val==x)return true;

    if(getPath(root->left,arr,x) || getPath(root->right,arr,x))return true;

    arr.pop_back();
    
    return false;
}

vector<int> rootToNodePath(TreeNode* root, int target) {
    // code here
    vector<int>ans;
    if(!root)return ans;
    getPath(root,ans,target);
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

int main() {
    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int target;
    cin >> target;

    TreeNode* root = buildTree(nodes);

    vector<int> path = rootToNodePath(root, target);

    for (int x : path) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}