class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *result = new ListNode(0);
    	ListNode *tmp;
	    tmp = result;
	    int tenth = 0;
	    while(l1 || l2) {
	        int val1 = l1 ? l1->val : 0;
	        int val2 = l2 ? l2->val : 0;
	        int sum = val1 + val2 + tenth;
		    tmp->next = new ListNode(sum % 10);
		    tmp = tmp->next;
		    if(l1) l1 = l1->next;
		    if(l2) l2 = l2->next;
		    tenth = sum / 10;
	    }
	    
	    if(tenth == 1) {
	        tmp->next = new ListNode(1);
	    }
	    return result->next;
    }
};
