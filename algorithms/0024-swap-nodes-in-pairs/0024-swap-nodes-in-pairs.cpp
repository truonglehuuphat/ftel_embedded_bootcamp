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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode * currNode = head;
        ListNode * preNode;
        while(currNode != NULL && currNode->next != NULL){
            ListNode * nextNode = currNode->next;
            if(head == currNode){
                head = nextNode;
            }else{
                preNode->next = nextNode;   
            }   
                currNode->next = nextNode->next;
                nextNode->next = currNode;
                preNode = currNode;
                currNode = currNode->next;    
        
        }
        return head;
    }
};