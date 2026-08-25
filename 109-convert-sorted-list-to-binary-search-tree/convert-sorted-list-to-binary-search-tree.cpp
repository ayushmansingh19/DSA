
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list into left and right halves
        prevSlow->next = NULL;

        TreeNode* root = new TreeNode(slow->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};