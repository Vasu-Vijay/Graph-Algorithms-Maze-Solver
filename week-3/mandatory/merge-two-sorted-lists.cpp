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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr && list2==nullptr) {
            return nullptr;
        } else if(list1==nullptr) {
            return list2;
        } else if(list2==nullptr) {
            return list1;
        }
        ListNode *newlist=nullptr, *newcurr, *prev=nullptr;
        ListNode *curr1 = list1, *curr2 = list2;
        while (curr1 != nullptr && curr2 != nullptr) {

            if (curr1->val <= curr2->val) {
                newcurr = curr1;
                curr1 = curr1->next;
            } else {
                newcurr = curr2;
                curr2 = curr2->next;
            }

            if (!newlist) {
                newlist = newcurr;
            } else {
                prev->next = newcurr;
            }

            prev = newcurr;
        }

        if(curr1==nullptr) {
            prev->next = curr2;
        } else {
            prev->next = curr1;
        }
        
        return newlist;
    }
};