
// https://leetcode.com/problems/binary-tree-cameras/

class Solution {
private:
    int ans=0;
    enum state{CAMERA, COVERED, NOT_COVERED};
public:
    int minCameraCover(TreeNode* root) {
        ans=0;
        return (cameraState(root)==NOT_COVERED? 1: 0)+ans;
    }
    
    
    state cameraState(TreeNode* root) {
        if(!root) return COVERED;
        
        state leftChild = cameraState(root->left);
        state rightChild = cameraState(root->right);
        
        if(leftChild ==NOT_COVERED || rightChild == NOT_COVERED) {
            // Place camera here
            ans++;
            return CAMERA;
        }
        if(leftChild == CAMERA || rightChild == CAMERA) {
            // Children have camera(s), so I am covered
            return COVERED;
        }
        return NOT_COVERED;
    }
    
};
