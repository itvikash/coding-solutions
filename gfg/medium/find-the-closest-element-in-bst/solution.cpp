/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    int minDiff(Node *root, int k) {
        int min_diff = INT_MAX;
        Node* curr = root;

        while (curr != NULL) {
            min_diff = min(min_diff, abs(curr->data - k));

            if (curr->data == k) {
                return 0;
            } else if (k < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return min_diff;
    }
};