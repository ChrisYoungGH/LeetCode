class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> &pre, vector<int> &vin) {
        return reconstruct(pre, vin, 0, int(pre.size())-1, 0, int(vin.size())-1);
    }
    
    TreeNode *reconstruct(vector<int> &pre, vector<int> &in, 
                          int preBegin, int preEnd, int inBegin, int inEnd) {
        if ((preEnd - preBegin != inEnd - inBegin) || preEnd < preBegin) {
            return NULL;
        }
        
        int inRootId = inBegin;
        while (inRootId <= inEnd && in[inRootId] != pre[preBegin]) {
            inRootId++;
        }
        if (inRootId > inEnd) {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(pre[preBegin]);
        root->left = reconstruct(pre, in, preBegin+1, preBegin+inRootId-inBegin, inBegin, inRootId-1);
        root->right = reconstruct(pre, in, preBegin+inRootId-inBegin+1, preEnd, inRootId+1, inEnd);
        
        return root;
    }
};