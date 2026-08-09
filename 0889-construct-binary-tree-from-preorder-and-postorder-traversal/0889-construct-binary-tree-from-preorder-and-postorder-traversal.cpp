class Solution {
public:
    TreeNode* build(vector<int>& pre, vector<int>& post, int& i, int l, int r) {
        if (i >= pre.size() || l > r) return nullptr;

        TreeNode* root = new TreeNode(pre[i++]);
        if (l == r) return root;

        int j = l;
        while (post[j] != pre[i]) j++;

        root->left = build(pre, post, i, l, j);
        root->right = build(pre, post, i, j + 1, r - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int i = 0;
        return build(preorder, postorder, i, 0, postorder.size() - 1);
    }
};
