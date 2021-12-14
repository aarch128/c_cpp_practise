#define _CRT_SECURE_NO_WARNINGS
#include"SpeechManager.h"
using namespace std;
int main()
{
	cout.precision(3);
	SpeechManager s;
	while (1) {
		
		int option = 1;
		system("cls");
		s.Menu();
		cout << ":>";
		cin >> option;
		switch (option) {
		case MenuOptions::start_contast: {
			s.StartSpeech();
			break;
		}
		case MenuOptions::print_records: {
			s.PrintSpeakerInfo(s.m_speakers_info);
			break;
		}
		case MenuOptions::clear_records: {
			break;
		}
		case MenuOptions::exit_contest: {
			s.Exit();
			return 0;
			break;
		}
		default: {
			system("cls");
		}
		}
		clock_t cl1=clock();

		if (cl1/CLOCKS_PER_SEC > 3) {
			srand((unsigned int)rand());
		}
		else{
			srand((unsigned int)time(NULL));
		}
	}
	return 0;
}