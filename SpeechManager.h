#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<deque>

#include<ctime>
#include<time.h>
#include"Speaker.h"
#define DEF_NUM 12
using namespace std;
enum MenuOptions
{
	start_contast = 1,
	print_records,
	clear_records,
	exit_contest
};
class SpeechManager
{
public:
	vector<int>m_v1speakers_index;
	vector<int>m_v2speakers_index;
	vector<int>m_victories_index;
	map<int, Speaker>m_speakers_info;
	int contest_times;
	SpeechManager();
	~SpeechManager();
	void InitSpeech();
	void Menu();
	void CreateSpeaker(int num= DEF_NUM);
	void StartSpeech();
	void SpeechLottery();
	void SpeechContest();
	void SaveScore(multimap<double, int, greater<double>> save_score[2]);
	void PrintSpeakerInfo(map<int, Speaker>&speakers_info);
	void Exit();

};