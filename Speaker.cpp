#define _CRT_SECURE_NO_WARNINGS
#include"Speaker.h"
using namespace std;
Speaker::Speaker()
{
	this->m_name ="\0";
	this->m_score[0] = 0;
	this->m_score[1] = 0;
}
Speaker::Speaker(string name,double score[])
{
	this->m_name = name;
	this->m_score[0] = score[0];
	this->m_score[1] = score[1];
}