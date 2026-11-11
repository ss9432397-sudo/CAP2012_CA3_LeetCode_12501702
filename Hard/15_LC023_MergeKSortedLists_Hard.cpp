
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
        decltype([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        })> pq;

        for (auto node : lists)
            if (node) pq.push(node);

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};
