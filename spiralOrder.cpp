#define _CRT_SECURE_NO_WARNINGS
#include"SpiralOrder.h"
using namespace std;

void Test()//4*4  3*4 4*3 3*3
{
	vector<vector<int>>m;
	int num = 1;
	for (int i = 0; i < 100; i++) {
		m.push_back(vector<int>());
		for (int j = 0; j < 100; j++) {
			m[i].push_back(num++);
		}
	}
	//vector<int>m1;
	//vector<int>m2;
	//vector<int>m3;
	//vector<int>m4;
	//for (int i = 0; i < 4; i++) {
	//	m1.push_back(i + 1);
	//	m2.push_back(i + 5);
	//	m3.push_back(i + 9);
	//	m4.push_back(i + 13);
	//}
	//m.push_back(m1);
	//m.push_back(m2);
	//m.push_back(m3);
	//m.push_back(m4);
	SpiralOrder s;
	vector<int>save;
	s.spiralOrder(m, save);
	for (vector<int>::iterator i = save.begin(); i < save.end(); i++) {
		cout << (*i) << " ";
	}
	cout << endl;
}
void Test1()//3*4 4*3 3*3
{
	vector<vector<int>>m;
	vector<int>m1;
	vector<int>m2;
	vector<int>m3;
	//vector<int>m4;
	for (int i = 0; i < 4; i++) {
		m1.push_back(i + 1);
		m2.push_back(i + 5);
		m3.push_back(i + 9);
		//m4.push_back(i + 13);
	}
	m.push_back(m1);
	m.push_back(m2);
	m.push_back(m3);
	//m.push_back(m4);
	SpiralOrder s;
	vector<int>save;
	s.spiralOrder(m, save);
	for (vector<int>::iterator i = save.begin(); i < save.end(); i++) {
		cout << (*i) << " ";
	}
	cout << endl;
}
void Test2()//4*3 3*3
{
	vector<vector<int>>m;
	vector<int>m1;
	vector<int>m2;
	vector<int>m3;
	vector<int>m4;
	for (int i = 0; i < 3; i++) {
		m1.push_back(i + 1);
		m2.push_back(i + 4);
		m3.push_back(i + 7);
		m4.push_back(i + 10);
	}
	m.push_back(m1);
	m.push_back(m2);
	m.push_back(m3);
	m.push_back(m4);
	SpiralOrder s;
	vector<int>save;
	s.spiralOrder(m, save);
	for (vector<int>::iterator i = save.begin(); i < save.end(); i++) {
		cout << (*i) << " ";
	}
	cout << endl;
}
void Test3()//3*3
{
	vector<vector<int>>m;
	vector<int>m1;
	vector<int>m2;
	vector<int>m3;
	//vector<int>m4;
	for (int i = 0; i < 3; i++) {
		m1.push_back(i + 1);
		m2.push_back(i + 4);
		m3.push_back(i + 7);
		//m4.push_back(i + 13);
	}
	m.push_back(m1);
	m.push_back(m2);
	m.push_back(m3);
	//m.push_back(m4);
	SpiralOrder s;
	vector<int>save;
	s.spiralOrder(m, save);
	for (vector<int>::iterator i = save.begin(); i < save.end(); i++) {
		cout << (*i) << " ";
	}
	cout << endl;
}
int main()
{
	Test();
	Test1();
	Test2();
	Test3();
	return 0;
}