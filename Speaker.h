#pragma once
#include<string>
using namespace std;
class Speaker
{
public:
	string m_name;
	double m_score[2];
	Speaker();
	Speaker(string name, double score[]);
};