#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class SpiralOrder
{
public:
	void spiralOrder(vector<vector<int> >& matrix,vector<int>&save)
	{
		//vector<int>save;
		Solve(matrix, save);
		//return save;
	}
	void Solve(vector<vector<int>>& matrix, vector<int>& save)
	{
		int len = matrix.size();
		int thw = matrix[0].size();

		if (len <= 1 || thw <= 1) {
			if (1 == len && 1 == thw) {
				save.push_back(matrix[0][0]);
				return;
			}
			else if (1 == len) {
				for (int i = 0; i < thw; i++) {
					save.push_back(matrix[0][i]);
				}
				return;
			}
			else if (1 == thw) {
				for (int i = 0; i < len; i++) {
					save.push_back(matrix[i][0]);
				}
				return;
			}
			else {
				return;
			}
		}
		else {
			vector<int>tmp_endt;
			vector<int>tmp_endl;
			vector<int>tmp_begt;
			bool len_r = 0;
			bool len_l = 0;
			for (int i = 0; i < len; i++) {// 1 2 3 4 8 12 16 15 14 13 9 5
				for (int j = 0; j < thw; j++) {
					if (0 == i) {
						save.push_back(matrix[i][j]);//第一行,直接添加 1 2 3 4
					}
					if ((j == thw - 1) && (i > 0)) {
						tmp_endt.push_back(matrix[i][j]);//最后一列缓存 8 12 16
					}
					if ((i == len - 1) && (j < thw - 1)) {//缓存最后一行 13 14 15
						tmp_endl.push_back(matrix[i][j]);
					}
					if ((0 == j) && (i > 0) && (i < len - 1)) {//缓存第一列 5 9
						tmp_begt.push_back(matrix[i][j]);
					}
				}
			}
			for (vector<int>::iterator i = tmp_endt.begin(); i < tmp_endt.end(); i++) {
				save.push_back(*i);
			}
			for (int i = tmp_endl.size() - 1, j = 0; i >= 0; i--, j++) {
				save.push_back(tmp_endl[i]);
			}
			for (int i = tmp_begt.size() - 1, j = 0; i >= 0; i--, j++) {
				save.push_back(tmp_begt[i]);
			}

			if (2 == len || 2 == thw) {
				return;
			}
			vector<vector<int>>re;
			vector<int>v;
			for (int i = 1, j = 0; i < len - 1; i++, j++) {
				re.push_back(v);
				for (int k = 1; k < thw - 1; k++) {
					re[j].push_back(matrix[i][k]);
				}
			}

			Solve(re, save);
		}
	}
};