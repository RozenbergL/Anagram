#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector <char> alph;
	for (int i = 0; i < s.length(); i++) {
		if (find(alph.begin(), alph.end(), s[i]) == alph.end()) {
			alph.push_back(s[i]);
		}
	}
	sort(alph.begin(), alph.end());
	int k1 = 0;
	int k2 = 10000000;
	int i = s.length() - 1;
	int count = 0;
	while (true) {
		k2 = distance(alph.begin(), find(alph.begin(), alph.end(), s[i]));
		if (k2 < k1) {
			break;
		}else{
			i--;
			k1 = k2;
			count++;
		}
	}
	count = s.length() - count - 1;
	int ind = distance(alph.begin(), find(alph.begin(), alph.end(), s[count]));
	string head = s.substr(0, count);
	string tail = s.substr(count + 1, s.length() - count);
	int mini = 100000000;
	int pos = 0;
	for (int i = 0; i < tail.length(); i++) {
		int x = distance(alph.begin(), find(alph.begin(), alph.end(), tail[i]));
		if ((x - ind > 0) && (x - ind < mini)) {
			pos = i;
			mini = x - ind;
		}
	}
	char sym = tail[pos];
	tail = tail.substr(0, pos) + tail.substr(pos + 1, tail.length() - pos) + s[count];
	sort(tail.begin(), tail.end());
	string answer = head + sym + tail;
	cout << answer;
}