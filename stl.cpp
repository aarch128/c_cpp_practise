//#define _CRT_SECURE_NO_WARNINGS
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<iostream>
//using namespace std;
////class Person
////{
////public:
////	string m_name;
////	int m_age;
////	Person() 
////	{
////		this->m_age = 0;
////		this->m_name = "0";
////	}
////	Person(string name, int age)
////	{
////		this->m_name = name;
////		this->m_age = age;
////	}
////};
////void Print(Person& p)
////{
////	cout << p.m_name << "  " << p.m_age << endl;
////}
////void Test()
////{
////	vector<Person*> v1;
////	Person p1("张三", 19);
////	Person p2("lisa", 20);
////	Person p3("john", 10);
////	v1.push_back(&p1);
////	v1.push_back(&p2);
////	v1.push_back(&p3);
////	//for_each(v1.begin(), v1.end(), Print);
////	for (vector<Person*>::iterator i = v1.begin(); i < v1.end(); i++) {
////		Print(**i);
////		cout << (*i)->m_name << "	" << (*i)->m_age << endl;
////	}
////}
//////for_each()遍历容器嵌套容器**************
////void Print3(int& num)
////{
////	cout << num << " ";
////}
////void Print1(vector<int>& v)
////{
////	for_each(v.begin(), v.end(), Print3);
////	cout << endl;
////}
//////for_each()遍历容器嵌套容器***************
////
////void Test1()//大容器嵌套小容器
////{
////	vector<vector<int>>v1;
////	vector<int>v2;
////	vector<int>v3;
////	vector<int>v4;
////	vector<int>v5;
////	for (int i = 0; i < 5; i++) {
////		v2.push_back(i + 1);
////		v3.push_back(i + 2);
////		v4.push_back(i + 3);
////		v5.push_back(i + 4);
////	}
////	v1.push_back(v2);
////	v1.push_back(v3);
////	v1.push_back(v4);
////	v1.push_back(v5);
////	
////	for_each(v1.begin(), v1.end(), Print1);//使用for_each（）遍历容器
////	cout << endl;
////	for (vector<vector<int>>::iterator i = v1.begin(); i < v1.end(); i++) {//使用循环遍历容器  
////		for (vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++) {
////			cout << *j << " ";
////		}
////		cout << endl;
////	}
////}
////############################2.string容器##################
////void Test2()
////{
////	string str1;
////	//str1[0] = 'a';
////	//str1[1] = 'a';
////	cout << str1 <<" "<<str1.size()<<" "<<" "<<sizeof(str1) << endl;
////	vector<int>a1();
////}
////#################vector容器###########################
////#define llun long long unsigned int
////void Test3()
////{
////	vector<int>v1;
////	v1.resize(42);
////	for (llun i = 0; i < 42; i++) {
////		v1[i] = i + 1;
////	}
////	cout << sizeof(vector<int>) << " "<<sizeof(int)<<" " << v1.size()<< endl;
////	//for (llun i = 0; i < 429496729; i++) {
////	//	cout << v1[i];
////	//}
////}
////class Solution {
////public:
////    /**
////     * 反转字符串
////     * @param str string字符串
////     * @return string字符串
////     */
////    string solve(string str) {
////        int len = str.size();
////        for (int i = str.size() - 1; i >= 0; i--) {
////            str += str[i];
////        }
////        return str.substr(len,len);
////    }
////};
////void Test4()
////{
////    Solution s;
////    cout << s.solve("abc") << endl;
////}
//
//
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int> >& matrix) {
//        vector<int>save;
//        Solve(matrix, save);
//        return save;
//    }
//    void Solve(vector<vector<int>>&matrix, vector<int>& save)
//    {
//      
//        int len = matrix.size();//行数
//        int thw = matrix[0].size();//列数
//        if (2 == len || 2 == thw) {
//            return;
//        }
//        else {
//        
//            vector<int>tmp_r;
//            vector<int>tmp_l;
//            int len_r = 0;
//            int len_l = 0;
//            bool flag_r = 0;
//            bool flag_l = 0;
//            for (int i = 0; i < len; i++) {
//                for (int j = 0; j < thw; j++) {
//                    if (0 == i) {//第一行
//                        save.push_back(matrix[0][j]);
//                    }
//                    if (j == thw-1 && i > 0) {//最后一列
//                        save.push_back(matrix[i][j]);
//                    }
//                    if (i == len-1 && j < thw-1) {//最后一行
//                        if (flag_r == 0)len_r = save.size();
//                        flag_r = 1;
//                        save.push_back(matrix[i][j]);//从save[len_r]开始存储
//                        tmp_r.push_back(matrix[i][j]);//从tmp_r[0]开始存储
//                    }
//                    if (i > 0 && i < len-1 && j == 0) {//第一列
//                        if (flag_l == 0)len_l = save.size();
//                        flag_l = 1;
//                        save.push_back(matrix[i][j]);
//                        tmp_l.push_back(matrix[i][j]);
//                    }
//                }
//            }
//
//            for (int i = tmp_r.size() - 1, j = 0; i >= 0; i--, j++) {
//                save[len_r + j] = tmp_r[i];
//            }
//            for (int i = tmp_l.size() - 1, j = 0; i >= 0; i--, j++) {
//                save[len_l + j] = tmp_l[i];
//            }
//            vector<vector<int>>Recall;
//            vector<int>v;
//            for (int i = 1, ii = 0; i < len - 1; i++, ii++) {
//                Recall.push_back(v);
//                for (int j = 1, jj = 0; j < thw - 1; j++, jj++) {
//                    Recall[ii].push_back(matrix[i][j]);
//                }
//
//            }
//            cout << Recall[0].size() << endl;
//           // Solve(Recall, save);
//        }
//
//    }
//};
//void Test5()
//{
//    Solution s;
//    vector<vector<int> > m;
//    vector<int>m1;
//    vector<int>m2;
//    vector<int>m3;
//    for (int i = 0; i < 3; i++) {
//        m1.push_back(i + 1);
//        m2.push_back(i + 4);
//        m3.push_back(i + 7);
//    }
//    m.push_back(m1);
//    m.push_back(m2);
//    m.push_back(m3);
//    vector<int>save=s.spiralOrder(m);
//    for (int i = 0; i < save.size(); i++) {
//        cout << save[i] << " ";
//    }
//    
//}
//int main()
//{
//	//Test();
//	//Test1();
//	//Test2();
//	//Test3();
//    //Test4();
//    Test5();
//	return 0;
//}