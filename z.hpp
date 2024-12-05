#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> z_function(string s);
void z_program(string str, bool show);
void prints_str(string str, int start_ind, int end_ind);
void prints_vct(vector<int> vct, int start_ind, int end_ind);
vector <int> z_find(string str, string substr);

void one_enter(string str, string substr, int shift);
void a_lot_enter(string str, string substr, vector<int> shifts);