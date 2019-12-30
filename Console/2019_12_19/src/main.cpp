#include "mainGame.h"
using namespace std;
#define INPUT_MODE 1  // 0 - kbhit, 1 - cin

int main() {
	mainGame mg;
	mg.init(INPUT_MODE);
	mg.run(INPUT_MODE);
	return 0;
}