#include "z.hpp"

vector<int> z_function(string s) {
	vector<int> z(s.size());
	int len_s = s.size();
	int left = 0, right = 0;
	for (int i = 1; i < s.size(); i++) {
		int min = z[i - left] < right - i ? z[i - left] : right - i;
		z[i] = 0 > min ? 0 : min;
		while (i + z[i] < len_s && s[z[i]] == s[i + z[i]])z[i] += 1;
		if (i + z[i] > right) {
			left = i;
			right = i + z[i];
		}
	}

	//Псевдокод
	/*for (int i = 0; i < s.size(); i++) {
		while (i + z[i] < len_s && s[z[i]] == s[z[i] + i]) { z[i]++; }
	}*/
	return z;
}

void z_program(string str, bool show) {
	int len = str.size();
	char ch;
	vector<int> res = z_function(str);
	if (show) {
		for (int i = 0; i < len; i++) {
			cout << "Поиск максильманого префикса подстроки:\n";
			prints_str(str, 0, len);
			cout << endl;
			prints_str(str, i, len);
			cin.get(ch);
			cout << "Максильманый префикс подстроки: " << res[i];
			cin.get(ch);
			system("cls");
		}
	}
	system("cls");
	cout << "Результат: \n";
	prints_str(str, 0, len);
	cout << endl;
	prints_vct(res, 0, res.size());
	cout << endl;
	cin.get(ch);
	system("cls");
	
	string sub_str;
	cout << "Введите подстроку для поиска в строке:\n\n>>";
	cin >> sub_str;
	system("cls");

	vector<int> shifts = z_find(str, sub_str);
	if (!shifts.size()) {
		cout << "Подстроки нет :(";
	}
	else {
		if (shifts.size() == 1)one_enter(str, sub_str, shifts[0]);
		else a_lot_enter(str, sub_str, shifts);
	}
	
}

void prints_str(string str, int start_ind, int end_ind) {
	for (int i = start_ind; i < end_ind; i++) {
		cout << str[i] << " ";
	}
}

void prints_vct(vector<int> vct, int start_ind, int end_ind) {
	for (int i = start_ind; i < end_ind; i++) {
		cout << vct[i] << " ";
	}
}

vector <int> z_find(string str, string substr) {
	vector<int> finds;
	int str_len = str.size();
	int substr_len = substr.size();
	vector<int> ind = z_function(substr + "?" + str);

	for (int i = substr_len + 1; i < str_len + substr_len + 1; i++) { 
		if (ind[i] == substr_len)finds.push_back(i - substr.size() - 1);
	}
	return finds;
}


void one_enter(string str, string substr, int shift) {
	int len = str.size();
	cout << endl;
	prints_str(str, 0, len);
	cout << endl;
	for (int i = 0; i < shift; i++) { cout << " " << " "; }
	prints_str(substr, 0, substr.size());
	cout << endl << endl;
	cout << "Подстрока '" << substr << "' встречается на позиции: " << shift << endl;
	cout << endl;
}

void a_lot_enter(string str, string substr, vector<int> shifts) {
	int len = str.size();
	cout << endl;
	for (int j = 0; j < shifts.size(); j++) {
		prints_str(str, 0, len);
		cout << endl;
		for (int i = 0; i < shifts[j]; i++) { cout << " " << " "; }
		prints_str(substr, 0, substr.size());
		cout << endl << endl;
	}
	cout << "Подстрока '" << substr << "' встречается на позициях : " << endl;
	for (int i = 0; i < shifts.size(); i++) {
		cout << shifts[i] << " ";
	}
	cout << endl;
}