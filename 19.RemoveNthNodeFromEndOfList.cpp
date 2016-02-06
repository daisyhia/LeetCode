/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s[100];
        ListNode* *t = s;
        int size = 0;
        while(head!=NULL) {
            t[size++] = head;
            head = head->next;
        }
        if(size==1) return NULL;
        if(n==size) return t[1];
        if(n==1) {
            t[size-2]->next = NULL;
        } else {
            n = size - n;
            t[n-1]->next = t[n+1];
        }
        return t[0];
    }
};