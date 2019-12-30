#include <iostream>
using namespace std;

#define GRAVITY 9.806

enum myEvent {
	event_start_fall,
};

enum archivements {
	ACHIEVMENT_FELL_OFF_BRIDGE,
};

class Entity {
public:
	void accelerate(float _acceleration) {
		cout << "물체 가속 : " << _acceleration << endl;
	}
	void update() {
		//doSomething
	}
	bool isOnSurface() {
		return false;
	}
	bool isHero() const {
		return true;
	}
	bool isHero() {
		return true;
	}
};


//이때 옵저버는 인터페이스로서 특정 시스템에 상속시키면,
//옵저버가 된다.
class Observer {
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity& entity, myEvent _event) = 0;
};

//즉 옵저버 클래스는 단지 인터페이스 클래스에 지나지 않는다.
class Achivements : public Observer {
private:
	int archiveState;

	virtual void onNotify(const Entity& entity, myEvent _event) {

		switch (_event)
		{
		case event_start_fall:
			if (entity.isHero() && entity.isOnSurface) {
				unlockAchivements(ACHIEVMENT_FELL_OFF_BRIDGE);
			}
			break;

			//... 그외의 이벤트를 처리
		}
	}

	void unlockAchivements(archivements _archive) {
		if (!archiveState & _archive) {
			switch (_archive)
			{
			case ACHIEVMENT_FELL_OFF_BRIDGE:
				archiveState |= ACHIEVMENT_FELL_OFF_BRIDGE;
				//doSomting
				break;
				//... 그외의 이벤트 처리
			}
		}
	}
};

//알림 메서드는 관찰당하는 객체가 호출한다.
//이때 이러한 객체를 'subject'라고 하며, 2가지 임무가 부여된다.
//첫번째는 관찰자 목록을 지니고 있는것이다.
//두번째는 옵저버에 알림을 보내는 것이다.
const int limitObserverNum = 100;
class Subject {
private:
	Observer* observers[limitObserverNum];
	int numObserver;

public:
	void addObserver(Observer* observer) {
		if (numObserver < limitObserverNum)
			observers[numObserver++];
	}
	void removeObserver(Observer* target_observer) {
		for (int i = 0; i < numObserver; ++i) {
			if (observers[i] == target_observer) {
				//삭제 알고리즘 적용
			}
		}
	}
	//위 두함수를 통해 subject는 알림을 전해줄 옵저버를 관리할수 있다.

protected:
	void notify(const Entity& entity, myEvent _event) {
		for (int i = 0; i < numObserver; ++i) {
			observers[i]->onNotify(entity, _event);
		}
	}
	//위 함수를 통해 subject는 옵저버들에게 알림을 전달한다.
};

class Physics :
	public Subject 
{
	//상속된 notify 메서드
	//void notify(Entity& entity, myEvent _event) {
		//옵저버 객체들에 알림을 전파한다.
		//이때 물리를 관장하는 본 객체는 무엇이 전파 되었는지 알필요가 없다.
		//확인은 옵저버 객체가 전파한 이벤트로, 다른시스템에서 확인한다.
	//}

	void updateEntity(Entity& entity) {
		bool wasOnSurface = entity.isOnSurface();
		entity.accelerate(GRAVITY);
		entity.update();

		if (wasOnSurface && !entity.isOnSurface()) {
			notify(entity, event_start_fall);
		}
	}
};