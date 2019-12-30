#include "Core/Core.h"

int main() {
	if (!Core::GetInst()->init()) {
		Core::GetInst()->Destroy();
		return -1;
	}
	int iRev = Core::GetInst()->run();
	Core::GetInst()->Destroy();
	return iRev;
}