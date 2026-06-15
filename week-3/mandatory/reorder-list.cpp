/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recur(ListNode* node, ListNode* mid, bool isOdd) {
        if ((!isOdd && node->next == mid) || (isOdd && node == mid)) {
            ListNode* nextComp  = mid->next;
            mid->next = nullptr;
            return nextComp;
        }
        ListNode* nodeComp = recur(node->next, mid, isOdd);
        ListNode* nextComp = nodeComp->next;
        nodeComp->next = node->next;
        node->next = nodeComp;
        return nextComp;
    }

    void reorderList(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *slow = head, *fast = &dummy;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        bool isOdd = !(fast->next == nullptr);
        recur(head, slow, isOdd);
    }
};