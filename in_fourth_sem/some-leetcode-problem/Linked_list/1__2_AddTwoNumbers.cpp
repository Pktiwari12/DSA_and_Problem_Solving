#include<iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}   // this can be used for mearging
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *sum = nullptr;
       ListNode *temp1 = l1;
       ListNode *temp2 = l2;
       ListNode *temp3 = nullptr;
       int carry = 0;
       while(temp1 != nullptr && temp2 != nullptr){
            ListNode *node = new ListNode();
            node->val = (temp1->val + temp2->val + carry) % 10 ;
            carry  = (temp1->val + temp2->val + carry) / 10;
            if(sum == nullptr){
                sum = node;
                temp3 = node;
            }else{
                temp3->next = node;
                temp3 = node;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
       }
       if(temp1 != nullptr){
            while(temp1 != nullptr){
                if(carry == 0){
                    temp3->next = temp1;
                    temp1 = nullptr;
                }else{
                    ListNode *node = new ListNode();
                    node->val = (temp1->val + carry) % 10;
                    carry = (temp1->val + carry) / 10;
                    temp3->next = node;
                    temp3 = node;
                    temp1 = temp1->next;
                }
            }
       }
       else if(temp2 != nullptr){
            while(temp2 != nullptr){
                if(carry == 0){
                temp3->next = temp2;
                temp2 = nullptr;
                }else{
                    ListNode* node = new ListNode();
                    node->val = (temp2->val + carry) % 10;
                    carry = (temp2->val + carry) / 10;
                    temp3->next = node;
                    temp3 = node;
                    temp2 = temp2->next;
                }
            }
       }
       if(carry != 0){
            ListNode* node = new ListNode(carry);
            temp3->next = node;
       }
       return sum;
    }
};


// Now soln with optimal space complexity
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *temp1 = l1;
       ListNode *temp2 = l2;
       ListNode *temp3 = nullptr;
       int carry = 0,sum = 0;
       // initially we increase both pointer with same pace, then perform calculation
       while(temp1 != nullptr && temp2 != nullptr){
            sum = (temp1->val + temp2->val + carry) % 10 ; // sum 1 bit value
            carry  = (temp1->val + temp2->val + carry) / 10;        // carry
            temp1->val = sum;
            if(temp1->next == nullptr){
                temp3 = temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
       }
       // if l2 exhausted
       if(temp1 != nullptr){
            while(temp1 != nullptr){
                if(carry == 0){     // rest list as it is which is pointed by temp1;
                    break;
                }else{ // if carry not 0, then perform calculation
                    sum = (temp1->val + carry) % 10;
                    carry = (temp1->val + carry) / 10;
                    temp1->val = sum;
                    if(temp1->next == nullptr){
                    // temp1 should not be nullptr
                        break;
                    }else{
                        temp1 = temp1->next;
                    }
                }
            }
       }
       // if l1 exhauseted , then we have to link listl1 with l2, so we take another pointer temp3
       else if(temp2 != nullptr){
        // link l1 with l2
            temp3->next = temp2;
            temp3 = temp3->next;
            // rest logic same as above if condtion
            while(temp3 != nullptr){
                if(carry == 0){
                    break;
                }else{
                    sum = (temp3->val + carry) % 10;
                    carry = (temp3->val + carry) / 10;
                    temp3->val = sum;
                    if(temp3->next == nullptr){
                        break;
                    }else{
                        temp3 = temp3->next;
                    }
                }
            }
       }
       // if carry is not 0 , then we have to create a new node to store carry value
       if(carry != 0){
            ListNode* node = new ListNode(carry);
            if(temp1 != nullptr){
                temp1->next = node;
            }
            else if(temp3 != nullptr){
                temp3->next = node;
            }
       }
       return l1;
    }
};



void printLL(ListNode * sum){
    ListNode* temp = sum;
    while(temp != nullptr){
        cout << temp->val << "\t";
        temp = temp->next;
    }
}


int main(){
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    Solution s;
    ListNode* sum = s.addTwoNumbers(l1,l2); 
    printLL(sum);
    Solution2 s2;
    sum = s2.addTwoNumbers(l1,l2);
    cout << endl << endl;
    cout << "Solution by algo 2 with optimal space" << endl;
    printLL(sum);
}



