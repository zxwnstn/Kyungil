#include <iostream>
#include <vector>
using namespace std;

class some {
	static bool up;
	static bool down;

public:
	void setUp() {
		up = !up;
	}
	void setDown() {
		down = !down;
	}
	void show() {
		cout << boolalpha;
		cout << "up : " << up << " down : " << down << endl;
	}

	
};

bool some::up = false;
bool some::down = false;

int main() 
{

	some::someting();
	
}