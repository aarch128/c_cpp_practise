//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//using namespace std;
//
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) :
//            val(x), next(NULL) {
//    }
//};
//class Solution {
//public:
//    ListNode* ReverseList(ListNode* pHead) {
//        if (NULL == pHead) {
//            return NULL;
//        }//else
//        ListNode* tmp_add = pHead;
//        ListNode* prev_node_add = NULL;
//        ListNode* next_node_add=NULL;
//        ListNode* ret = NULL;
//        bool flag = 0;
//
//        while (NULL != tmp_add) {
//            ret = tmp_add;
//            next_node_add = tmp_add->next;//下个节点
//            tmp_add->next = prev_node_add;//此节点指向上一个节点
//            prev_node_add = tmp_add;//此节点成为上个节点
//            tmp_add = next_node_add;
//        }
//        return ret;
//    }
//};
//void Test()
//{
//#define LEN 4
//    ListNode n[LEN] = { 1,2,3 ,4};
//    for (int i = 0; i < LEN-1; i++) {
//        n[i].next = &n[i+1];
//    }
//    n[LEN-1].next = NULL;//最后一个元素指向NULL
//    Solution s;
//    ListNode* ret = s.ReverseList(&n[0]);
//    for (int i = 0; i < LEN; i++) {
//        cout << ret->val <<"|";
//        ret = ret->next;
//    }
//   
//}
//int main()
//{
//    Test();
//    return 0;
//}