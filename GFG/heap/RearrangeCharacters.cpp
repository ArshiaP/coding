#include <bits/stdc++.h>

using namespace std;

void rearrangeCharacters(string s) {
  unordered_map<char, int> map;

  for (auto c : s) {
    map[c]++;
  }

  vector<int> v;

  for (auto it = map.begin(); it != map.end(); it++) {
    v.push_back(it->second);
  }

  sort(v.begin(), v.end());

  auto front = v.begin();
  auto end = v.end() - 1;

  while (front < end) {
    if (*front > *end) {
      *front -= *end;
      end--;
    } else if (*front < *end) {
      *end -= *front;
      front++;
    } else {
      front++;
      end--;
    }
  }

  if (*front > 1) {
    cout << "0" << endl;
  } else {
    cout << "1" << endl;
  }
}

int main() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    rearrangeCharacters(s);
  }
  return 0;
}