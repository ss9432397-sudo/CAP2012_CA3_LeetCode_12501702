
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k = k % n;
        if (k == 0) return head;

        tail->next = head;

        for (int i = 0; i < n - k; i++)
            tail = tail->next;

        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};
