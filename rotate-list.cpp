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
    ListNode* rotateRight(ListNode* head, int k) {
        //exit if the list is empty
        if(head == nullptr){
            return head;
        }

        //save head and create size variable
        ListNode* temp = head;
        int size = 0;

        //get size of list
        while(head->next != nullptr){
                head = head->next;
                ++size;
        }

        //set head back to original posistion
        head = temp;

        //rotate the list
        for(int i = 0; i < k % (size + 1); i++){
            while(head->next != nullptr){
                head = head->next;
                int temp_val = temp->val;
                temp->val = head->val;
                head->val = temp_val;
            }
            head = temp;
        }

        //return the head of the list
        return head;
    }
};
