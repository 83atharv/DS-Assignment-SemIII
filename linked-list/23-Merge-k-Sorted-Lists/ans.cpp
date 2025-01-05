// https://leetcode.com/problems/merge-k-sorted-lists/description/

// SOLUTION - 
 
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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)>
            minHeap(cmp);

        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy;
        ListNode* current = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            current->next = smallestNode; 
            current = current->next;

            if (smallestNode->next) {
                minHeap.push(smallestNode->next);
            }
        }

        return dummy.next; 
    }
};