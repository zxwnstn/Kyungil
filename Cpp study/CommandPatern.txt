#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int keyState = 0;

class Actor {

public:
	virtual void jump() = 0;
	virtual void run() = 0;
	virtual void shot() = 0;
	virtual void curve() = 0;
};

class Player : public Actor {
	virtual void jump() override {
		cout << "플레이어 점프!" << endl;
	}
	virtual void run() override {
		cout << "플레이어 런!" << endl;
	}
	virtual void shot() override {
		cout << "플레이어 슛!" << endl;
	}
	virtual void curve() override {
		cout << "플레이어 커브!" << endl;
	}
};

class Monster : public Actor {
	virtual void jump() override {
		cout << "몬스터 점프!" << endl;
	}
	virtual void run() override {
		cout << "몬스터 런!" << endl;
	}
	virtual void shot() override {
		cout << "몬스터 슛!" << endl;
	}
	virtual void curve() override {
		cout << "몬스터 커브!" << endl;
	}
};

class Command {
public:
	virtual ~Command() {}
	virtual void excute(Actor& actor) = 0;
};

class JumpCommand : public Command {
	void excute(Actor& actor) override {
		actor.jump();
	}
};

class RunCommand : public Command {
	void excute(Actor& actor) override {
		actor.run();
	}
};

class ShotCommand : public Command {
	void excute(Actor& actor) override {
		actor.shot();
	}
};

class CurveCommand : public Command {
	void excute(Actor& actor) override {
		actor.curve();
	}
};

enum Button {
	BUTTON_X = 0b0001,
	BUTTON_Y = 0b0010,
	BUTTON_A = 0b0100,
	BUTTON_B = 0b1000
};


class InputHandler {
private:
	void getInput() {
		char a;
		cin >> a;
		if (a == 'a') {
			keyState |= (int)BUTTON_X;
		}
		if (a == 'd') {
			keyState |= (int)BUTTON_X;
		}
		if (a == 'w') {
			keyState |= (int)BUTTON_A;
		}
		if (a == 'l') {
			keyState |= (int)BUTTON_B;
		}
	}
	bool isPressed(Button _button) {
		if (keyState & (int)_button) {
			keyState ^= (int)_button;
			return true;
		}
		return false;
	}

public:
	Command* handleInput() {
		Command* cmd;
		getInput();
		if (isPressed(BUTTON_A))
			return cmd = new JumpCommand();
		else if (isPressed(BUTTON_B))
			return cmd = new ShotCommand();
		else if (isPressed(BUTTON_X))
			return cmd = new RunCommand();
		else if (isPressed(BUTTON_Y))
			return cmd = new CurveCommand();
		return nullptr;
	}
	Command* handleMonsterInput() {
		int mInput = rand() % 4;
		switch (mInput)
		{
		case 0:
			return nullptr;
		case 1:
			return new ShotCommand();
		case 2:
			return new JumpCommand();
		case 3:
			return new CurveCommand();
		}
	}
};


int main() {
	srand(time(NULL));
	InputHandler inputHandler;
	Actor* player = new Player;
	Actor* monster = new Monster;
	while (1) {
		Command* pCmd = inputHandler.handleInput();
		Command* mCmd = inputHandler.handleMonsterInput();
		if (pCmd != nullptr)
			pCmd->excute(*player);
		if (mCmd != nullptr)
			mCmd->excute(*monster);
		delete mCmd;
		delete pCmd;
	}
}