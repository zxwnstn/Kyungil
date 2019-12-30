#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<int, string> map;
	/*map.insert(make_pair(3, "hi"));
	map.insert(make_pair(4, "HI"));
	map.insert(make_pair(5, "fuck"));
	map.insert(make_pair(2, "bb"));
	map.insert(make_pair(1, "cc"));*/

	map.emplace(5, "sdlk");
	map.emplace(5, "we");
	map.emplace(5, "zxc");
	cout << map.size() << endl;
	auto it = map.begin();
	for (it; it != map.end(); ++it) {
		cout << it->second << endl;
	}



	for (it; it != map.end(); ++it) {
		cout << it->second << endl;
	}
	cout << map.size() << endl;
	it = map.find(7);
	cout << map.size() << endl;
	if (it == map.end())
		cout << "not find" << endl;
	else
		cout << it->second << endl;
	

}