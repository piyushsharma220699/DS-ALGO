//Lowest Common Ancestor of Two Nodes Code in C++

/*
The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newTreeNode(int k)
{
    TreeNode* temp = new TreeNode;
    temp->val = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* node1, TreeNode* node2)
{
    if(!root || root->val == node1->val || root->val == node2->val)
        return root;

    TreeNode* left = lowest_common_ancestor(root->left, node1, node2);
    TreeNode* right = lowest_common_ancestor(root->right, node1, node2);
    
    if(left && right)
        return root;
    
    if(!left)
        return right;
    
    return left;
}

int main()
{
    TreeNode* root = newTreeNode(3);
    root->left = newTreeNode(5);
    root->right = newTreeNode(1);
    
    root->left->left = newTreeNode(6);
    root->left->right = newTreeNode(2);
    root->right->left = newTreeNode(0);
    root->right->right = newTreeNode(8);
    
    root->left->right->left = newTreeNode(7);
    root->left->right->right = newTreeNode(4);

    cout<<"Lowest Common Ancestor of 6 and 7 is: "<<(lowest_common_ancestor(root, root->left->left, root->left->right->left))->val<<endl;
    
    cout<<"Lowest Common Ancestor of 5 and 0 is: "<<(lowest_common_ancestor(root, root->left, root->right->left))->val<<endl;
    

    return 0;
}

/* 
Time Complexity: O(N)
Space Complexity: O(1)
*/
