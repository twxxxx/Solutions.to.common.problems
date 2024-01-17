// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 反转[a, b)之间的节点
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        while (cur != b) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    // 按照k个一组反转整个链表
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 创建一个哨兵节点
        ListNode* dummy = new ListNode(0, head);
        // 初始化前驱节点和当前节点
        ListNode* pre = dummy;
        ListNode* cur = head;
        // 循环直到链表末尾
        while (cur) {
            // 找到下一组的起点和终点
            ListNode* a = cur;
            ListNode* b = cur;
            for (int i = 0; i < k; i++) {
                if (!b) {
                    // 不足k个，直接返回
                    return dummy->next;
                }
                b = b->next;
            }
            // 反转当前组，并返回反转后的头节点
            ListNode* newHead = reverse(a, b);
            // 将反转后的部分连接到前驱节点后面
            pre->next = newHead;
            // 更新前驱节点和当前节点为反转后的尾节点和下一组的起点
            pre = a;
            cur = b;
        }
        return dummy->next;
    }
};
