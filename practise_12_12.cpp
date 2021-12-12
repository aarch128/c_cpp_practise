#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
class Person
{
public:
	vector<int>score;
	Person()
	{
		for (int i = 0; i < 10; i++) {
			this->score.push_back(0);
		}
	}
};
class Rating
{
private:
	vector<double>average_score;
public:
	vector<Person>person;
	Rating()
	{
		for (int i = 0; i < 5; i++) {
		this->person.push_back(Person());
		this->average_score.push_back(0);
		}
	}
	Rating(int size)
	{
		for (int i = 0; i < size; i++) {
			this->person.push_back(Person());
			this->average_score.push_back(0);
		}
	}
	vector<double> AverageScore()
	{
		for (int i = 0; i < person.size(); i++) {//对每个人成绩排序，升序
			sort(this->person[i].score.begin(), this->person[i].score.end());
			int sum = 0;
			for (int j = 1; j <= 8; j++) {
				sum += this->person[i].score[j];
			}
			this->average_score[i] = sum / 8.0;
		}
		return average_score;
	}
};
void Test()
{
	Rating r;

	for (int i = 0; i < 10; i++) {
		r.person[0].score[i] = i + 59+4;

	}
	for (int i = 0; i < 10; i++) {
		r.person[1].score[i] = i + 29+51;

	}
	for (int i = 0; i < 10; i++) {
		r.person[2].score[i] = i + 39+39;

	}
	for (int i = 0; i < 10; i++) {
		r.person[3].score[i] = i + 71+12;

	}
	for (int i = 0; i < 10; i++) {
		r.person[4].score[i] = i + 53+33;

	}
	for (int i = 0; i < r.AverageScore().size(); i++) {
		cout << i + 1 << " average score: ";
		cout << r.AverageScore()[i];
		cout << "  score: ";
		for (int j = 0; j < 10; j++) {
			cout << r.person[i].score[j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Test();
	return 0;
}