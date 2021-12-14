#define _CRT_SECURE_NO_WARNINGS
#include"SpeechManager.h"
using namespace std;
SpeechManager::SpeechManager()
{
	this->InitSpeech();
	this->CreateSpeaker();
}
SpeechManager::~SpeechManager()
{

}
void SpeechManager::InitSpeech()
{
	this->m_v1speakers_index.clear();
	this->m_v2speakers_index.clear();
	this->m_victories_index.clear();
	this->m_speakers_info.clear();
	this->contest_times = 1;
}
void SpeechManager::CreateSpeaker(int num)
{
	if (num > 26) {
		num = 26;
	}
	else if (num < 0) {
		num = 0;
	}
	double score[2] = { 0,0 };
	for (int i = 0; i < num; i++) {
		string name = "ѡ��";
		char second_name = 'A';
		(char)(second_name += i);
		name += second_name;
		this->m_v1speakers_index.push_back(1001 + i);
		
		this->m_speakers_info.insert(make_pair(1001 + i, Speaker(name, score)));
		
	}
}
void SpeechManager::Menu()
{
	cout << "********mock speech contest************" << endl;
	cout << "      1.start contest" << endl;
	cout << "      2.print records of previous" << endl;
	cout << "      3.clear records" << endl;
	cout << "      4.exit" << endl;
	cout << "***************************************" << endl;

}

void SpeechManager::SpeechLottery()
{
	cout << "��" << this->contest_times << "��������ǩ��" << endl;
	cout << "�ݽ�˳�����£�"<<endl;
	if (1 == this->contest_times) {
		random_shuffle(this->m_v1speakers_index.begin(), this->m_v1speakers_index.end());//��ǩ1
		for (vector<int>::iterator index = this->m_v1speakers_index.begin(); index != this->m_v1speakers_index.end(); index++) {
			cout << "��ţ�" << *index << "    ������" << this->m_speakers_info.find(*index)->second.m_name<<endl;
		}
	}
	else {
		random_shuffle(this->m_v2speakers_index.begin(), this->m_v2speakers_index.end());//��ǩ2
		for (vector<int>::iterator index = this->m_v2speakers_index.begin(); index != this->m_v2speakers_index.end(); index++) {
			cout << "��ţ�" << *index << "    ������" << this->m_speakers_info.find(*index)->second.m_name<<endl;
		}
	}
	system("pause");
	cout << endl;
}

void SpeechManager::StartSpeech()
{
	this->SpeechLottery();//��ǩ1
	this->SpeechContest();//����1
	this->contest_times = 2;
	this->SpeechLottery();//��ǩ2
	this->SpeechContest();//����2
}
double accumulate(deque<double>::iterator beg, deque<double>::iterator end,int n)
{
	double sum=0.f;
	for (deque<double>::iterator it=beg; it!=end ; it++) {
		sum += *it;
	}
	return sum;
}
void SpeechManager::SpeechContest()
{
	cout << "��" << this->contest_times << "�������ɼ���" << endl;
	multimap<double, int, greater<double>>save_score[2];
	if (1 == this->contest_times) {//��һ�������� ÿ��6�ˣ�ÿ��10��������ȡÿ��ǰ����������

		multimap<double,int,greater<double>>sp_avg_score[2];//����������Ӧ��ţ����ճɼ���������,����
		for (int i = 0; i < 12; i++) {
			deque<double>score;
			score.resize(0);
			for (int j = 0; j < 10; j++) {
				score.push_back((rand() % 400 + 600) / 10.f);
			}
			sort(score.begin(), score.end());
			score.pop_back();
			score.pop_front();
			if (i < 6) {
				sp_avg_score[0].insert(make_pair(accumulate(score.begin(), score.end(), 0) / score.size()*1.f, this->m_v1speakers_index.at(i)));
			}
			else {
				sp_avg_score[1].insert(make_pair(accumulate(score.begin(), score.end(), 0) / score.size()*1.f, this->m_v1speakers_index.at(i)));
			}
		}
		this->m_v2speakers_index.resize(6);
		int i = 0, j = 3;
		for (multimap<double, int, greater<double>>::iterator it1 = sp_avg_score[0].begin(), it2 = sp_avg_score[1].begin(); 
			i<3;it1++,it2++,i++,j++) {//������ǰ������Ż����룬�ڶ��������������
			this->m_v2speakers_index[i] = it1->second;
			this->m_v2speakers_index[j] = it2->second;
		}
		cout << "��һ�飺" << endl;
		for (multimap<double, int, greater<double>>::iterator it = sp_avg_score[0].begin(); it != sp_avg_score[0].end();it++) {//��ӡ�ɼ�
			cout << "��ţ�" << it->second << "      ������" << this->m_speakers_info.find(it->second)->second.m_name
				<< "      ��һ���ɼ���" << it->first << endl;
		}
		cout << "�ڶ��飺" << endl;
		for (multimap<double, int, greater<double>>::iterator it = sp_avg_score[1].begin(); it != sp_avg_score[1].end(); it++) {//��ӡ�ɼ�
			cout << "��ţ�" << it->second << "      ������" << this->m_speakers_info.find(it->second)->second.m_name
				<< "      ��һ���ɼ���" << it->first << endl;
		}
		//����һ���ɼ�����
		for (multimap<double, int, greater<double>>::iterator it1 = sp_avg_score[0].begin(); it1 != sp_avg_score[0].end(); it1++) {
			save_score[0].insert(make_pair(it1->first,it1->second));
		}
		for (multimap<double, int, greater<double>>::iterator it1 = sp_avg_score[1].begin(); it1 != sp_avg_score[1].end(); it1++) {
			save_score[0].insert(make_pair(it1->first, it1->second));
		}
		cout << "\n\n\n";
		system("pause");
		cout << "\n";
	}
	else if(2==this->contest_times) {//�ڶ�����6��
		multimap<double, int, greater<double>>sp_avg_score;//����������Ӧ��ţ����ճɼ���������,����
		for (int i = 0; i < 6; i++) {
			deque<double>score;
			score.resize(0);
			for (int j = 0; j < 10; j++) {
				score.push_back((rand() % 400 + 600) / 10.f);
			}
			sort(score.begin(), score.end());
			score.pop_back();
			score.pop_front();
			sp_avg_score.insert(make_pair(accumulate(score.begin(), score.end(), 0) / score.size() * 1.f, this->m_v2speakers_index[i]));
		}
		int j = 0;
		for (multimap<double, int, greater<double>>::iterator it = sp_avg_score.begin();j<3;it++,j++) {
			this->m_victories_index.push_back(it->second);
		}
		cout << "�÷֣�" << endl;
		for (multimap<double, int, greater<double>>::iterator it = sp_avg_score.begin(); it != sp_avg_score.end(); it++) {//��ӡ�ɼ�
			cout << "��ţ�" << it->second << "      ������" << this->m_speakers_info.find(it->second)->second.m_name
				<< "      �ڶ����ɼ���" << it->first << endl;
		}
		//����ڶ����ɼ�
		for (multimap<double, int, greater<double>>::iterator it = sp_avg_score.begin(); it != sp_avg_score.end(); it++) {
			save_score[1].insert(make_pair(it->first, it->second));
		}
		cout << "\n\n\n";
		system("pause");
		cout << "\n";
	}
	this->SaveScore(save_score);
}
void SpeechManager:: SaveScore(multimap<double, int, greater<double>>save_score[2])
{
	map<int, Speaker>::iterator msp = this->m_speakers_info.begin();
	for (multimap<double, int, greater<double>>::iterator it1 = save_score[0].begin(); it1 != save_score[0].end(); it1++) {
		this->m_speakers_info.find(it1->second)->second.m_score[0] = it1->first;
	}
	for (multimap<double, int, greater<double>>::iterator it2 = save_score[1].begin(); it2 != save_score[1].end(); it2++) {
		this->m_speakers_info.find(it2->second)->second.m_score[1] = it2->first;
	}
}
void SpeechManager:: PrintSpeakerInfo(map<int, Speaker>&speakers_info)
{
	for (map<int, Speaker>::iterator sp = speakers_info.begin(); sp != speakers_info.end();sp++) {
		cout << "��ţ�" << sp->first << "      ������" << sp->second.m_name
			<< "      ��һ���ɼ���" << sp->second.m_score[0] << "      �ڶ����ɼ���" << sp->second.m_score[1] << endl;
	}
	cout << "\n";
	system("pause");

}
void SpeechManager::Exit()
{
	system("cls");
	cout << "exited" << endl;
	system("pause");
	
}