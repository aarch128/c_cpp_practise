//#define _CRT_SECURE_NO_WARNINGS
//#include<stack>
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    void push(int node) {
//        stack1.push(node);
//    }
//
//    int pop() {
//        cout << "(s1 " << stack1.size() << ")";
//        
//
//        while (!stack1.empty()) {
//            
//            stack2.push(stack1.top());
//            stack1.pop();
//        }
//        int ret = stack2.top();
//        stack2.pop();
//        cout << "(s2 " << stack2.size() << ")";
//        while (!stack2.empty()) {
//            
//            stack1.push(stack2.top());
//            stack2.pop();
//        }
//        return ret;
//    }
//
//private:
//    stack<int> stack1;
//    stack<int> stack2;
//};
//
//void Test()
//{
//    Solution s;
//    for (int i = 0; i < 10; i++) {
//        s.push(i + 1);
//    }
//    cout << "入队1-10" << endl;
//    cout << "出队1-5" << "  ";
//    for (int i = 0; i < 5; i++) {
//        cout << s.pop() << "  ";
//    }
//    cout << endl;
//    for (int i = 10; i < 15; i++) {
//        s.push(i + 1);
//    }
//    cout << "入队10-15"<<endl;
//    cout << "出队6-15" << "  ";
//    for (int i = 0; i < 10; i++) {
//        cout << s.pop() << "  ";
//    }
//    cout << endl;
//}
//int main()
//{
//    Test();
//    return 0;
//}