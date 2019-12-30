#include <Windows.h>
#include <cmath>
#include <vector>
#define PI 3.141592
using namespace std;
//�޸𸮻� �Ҵ�Ǿ� �������� ���α׷� �ڵ�
HINSTANCE m_hInstance;
//������ �ڵ�
//��󳢸� �����ϱ� ���� ����Ѵ�.
HWND m_hWnd;
//������ Ŭ���� �̸�
LPTSTR m_lpszClass = TEXT("���� ���α׷��� 18��");
float rad = PI * 1 / 12;

struct POSITION {
	double x;
	double y;

	POSITION()
	{}
	POSITION(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//hInst - �ν��Ͻ� �ڵ�,
//hPrevInstance : ������ ����� �ν��Ͻ� �ڵ�
//hpszcmdparam : wndmain ����� �μ�
//nCmdshow : ���α׷��� ���۵� ����
//�������� ��Ȱ
//1. ������â ������ ȭ�鿡 ����
//2. �޼��� ����
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdParam, int nCmdShow) {

	//������ API�� winMain, WndProc �ΰ��� �Լ��� �̷�����ִ�.
	//������ ���ν����� �����쿡�� �̷������ ���� - �޼����� ó���Ѵ�.
	m_hInstance = hInst;
	
	//������ â�� ������ �����ϱ� ���� ����ü
	//������ â ����ü ������ �ʱ�ȭ
	WNDCLASS wndClass;
	//������ Ŭ�������� ����ϰ��� �ϴ� ������ �޸𸮾��� ����Ʈ ������ ����
	wndClass.cbClsExtra = 0;
	//���� �����쿡�� ����ϰ��� �ϴ� ������ �޸𸮾��� ����
	wndClass.cbWndExtra = 0;
	//������ �۾������� ĥ�� ��� �귯��
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//Ŀ������
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//Ÿ��Ʋ�� �»���� ������
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInst;
	//�޼��� ó�� �Լ�
	wndClass.lpfnWndProc = (WNDPROC)wndProc;

	wndClass.lpszClassName = m_lpszClass;
	wndClass.lpszMenuName = NULL;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//������ Ŭ���� ���
	//����� ������ Ŭ������ Ư���� �����ϴ� wndClass ����ü
	RegisterClass(&wndClass);
	m_hWnd = CreateWindow(
		m_lpszClass,			
		m_lpszClass, 
		WS_OVERLAPPEDWINDOW,
		100, 
		100, 
		1024, 
		768, 
		NULL,					//�θ� �ڵ�
		(HMENU)NULL,			//�޴� �ڵ�
		hInst, 
		NULL
	);
	ShowWindow(m_hWnd, nCmdShow);

	//�ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
	MSG message;
	//GetMessage - ������
	while (GetMessage(&message, 0, 0, 0)) {
		//Ű���� �Է¸޼��� ó��
		TranslateMessage(&message);
		//������ ���ν����� ���޵� �޼����� ���� �����쿡 ����
		DispatchMessage(&message);
	}
	
	return message.wParam;
}

void rotateVertex(int* x, int* y, int r, float degree) {
	int newX = *x * cos(degree) - *y * sin(degree);
	int newY = *x * sin(degree) + *y * cos(degree);
	*x = newX;
	*y = newY;
}

void drawFilledCircle(int x, int y, int r, const HDC& hdc, int _r, int _g, int _b) {
	for (r; r >= 0; r -= 1) {
		for (float theta = 0; theta <= 2 * PI; theta += PI / 1024) {
			SetPixel(hdc, x + r * cos(theta), y - r * sin(theta), RGB(_r, _g, _b));
		}
	}
}

void drawFilledCircleSetAngleY(int x, int y, int r, float StartAngle, float EndAngle, const HDC& hdc, int _r, int _g, int _b) {
	const int firstPosY = y - r * sin(StartAngle);
	for (r; r >= 0; r -= 1) {
		for (float theta = StartAngle; theta <= EndAngle; theta += PI / 1024) {
			int xPos = x + r * cos(theta);
			int yPos = y - r * sin(theta);
			if (yPos <= firstPosY) {
				SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
			}
		}
	}
}

void drawFilledCircleSetAngleYDown(int x, int y, int r, float StartAngle, float EndAngle, const HDC& hdc, int _r, int _g, int _b) {
	const int firstPosY = y - r * sin(StartAngle);
	for (r; r >= 0; r -= 1) {
		for (float theta = StartAngle; theta <= EndAngle; theta += PI / 1024) {
			int xPos = x + r * cos(theta);
			int yPos = y - r * sin(theta);
			if (yPos >= firstPosY) {
				SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
			}
		}
	}
}

void drawFilledCircleSetAngleXRotate(int x, int y, int r, float StartAngle, float EndAngle, const HDC& hdc, int _r, int _g, int _b) {
	const int firstPosX = r * cos(StartAngle);

	float degree90 = PI / 2.f;
	float degree270 = PI * 3 / 2.f;

	if ((degree90 <= StartAngle) && (StartAngle <= degree270)) {
		for (r; r >= 0; r -= 1) {
			for (float theta = StartAngle; theta <= EndAngle; theta += PI / 1024) {
				int xPos = r * cos(theta);
				int yPos = r * sin(theta);
				if (xPos <= firstPosX) {
					rotateVertex(&xPos, &yPos, r, PI / 6);
					xPos += x;
					yPos += y;
					SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
				}
			}
		}
	}
	else {
		for (r; r >= 0; r -= 1) {
			for (float theta = EndAngle; theta >= StartAngle; theta -= PI / 1024) {
				int xPos = r * cos(theta);
				int yPos = r * sin(theta);
				if (xPos >= firstPosX) {
					rotateVertex(&xPos, &yPos, r, PI / 6);
					xPos += x;
					xPos -= 25;
					yPos += y;
					yPos -= 15;
					SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
				}
			}
		}
	}	
}

void drawFilledCircleSetAngleX(int x, int y, int r, float StartAngle, float EndAngle, const HDC& hdc, int _r, int _g, int _b, int offset) {
	const int firstPosX = r * cos(StartAngle);

	float degree90 = PI / 2.f;
	float degree270 = PI * 3 / 2.f;

	if ((degree90 <= StartAngle) && (StartAngle <= degree270)) {
		for (r; r >= 0; r -= 1) {
			for (float theta = StartAngle; theta <= EndAngle; theta += PI / 1024) {
				int xPos = r * cos(theta);
				int yPos = r * sin(theta);
				if (xPos <= firstPosX) {
					xPos += x;
					yPos += y;
					SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
				}
			}
		}
	}
	else {
		for (r; r >= 0; r -= 1) {
			for (float theta = EndAngle; theta >= StartAngle; theta -= PI / 1024) {
				int xPos = r * cos(theta);
				int yPos = r * sin(theta);
				if (xPos >= firstPosX) {
					xPos += x;
					yPos += y;
					SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
				}
			}
		}
	}
}

void drawFilledCircleSetAngleXCut(int x, int y, int r, float StartAngle, float EndAngle, const HDC& hdc, int _r, int _g, int _b, int y1, int y2) {
	const int firstPosX = r * cos(StartAngle);

	float degree90 = PI / 2.f;
	float degree270 = PI * 3 / 2.f;

	if ((degree90 <= StartAngle) && (StartAngle <= degree270)) {
		for (r; r >= 0; r -= 1) {
			for (float theta = StartAngle; theta <= EndAngle; theta += PI / 1024) {
				int xPos = r * cos(theta);
				int yPos = r * sin(theta);
				if (xPos <= firstPosX) {
					xPos += x;
					yPos += y;
					if((y1 <= yPos) && (yPos <= y2))
						SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
				}
			}
		}
	}
	else {
		for (r; r >= 0; r -= 1) {
			for (float theta = EndAngle; theta >= StartAngle; theta -= PI / 1024) {
				int xPos = r * cos(theta);
				int yPos = r * sin(theta);
				if (xPos >= firstPosX) {
					xPos += x;
					yPos += y;
					if ((y1 <= yPos) && (yPos <= y2))
						SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
				}
			}
		}
	}
}

void drawFilledEllipse(int x, int y, int a, int b, const HDC& hdc, int _r, int _g, int _b) {
	while(1){
		for (float theta = 0.f; theta <= 2 * PI; theta += PI / 1024) {
			int xPos = x + a * cos(theta);
			int yPos = y - b * sin(theta);
			SetPixel(hdc, xPos, yPos, RGB(_r, _g, _b));
		}
	}
}

void drawRect(int x1, int y1, int x2, int y2, const HDC& hdc, int _r, int _g, int _b) {
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			SetPixel(hdc, j, i, RGB(_r, _g, _b));
		}
	}
}

void drawLeaf(int x1, int y1, int r, int rotateAngle, const HDC& hdc) {
	drawFilledCircleSetAngleXRotate(x1, y1, r, PI * 4 / 6, PI * 8 / 6, hdc, 36, 117, 0);
	float start = float(PI * 2) - float(PI * 2 / 6);
	float end = float(PI * 2) + float(PI * 2 / 6);
	drawFilledCircleSetAngleXRotate(x1, y1, r, start, end, hdc, 36, 117, 0);
}

void drawBody(const HDC& hdc) {
	//���� �ʷ�
	drawFilledCircleSetAngleY(445, 290, 63, PI * 1 / 4, PI * 3 / 4, hdc, 36, 117, 0);
	drawFilledCircleSetAngleY(525, 290, 63, PI * 1 / 4, PI * 3 / 4, hdc, 36, 117, 0);
	drawFilledCircleSetAngleXCut(478, 303, 98, PI * 4 / 5, PI * 9 / 6, hdc, 36, 117, 0, 245, 260);
	drawFilledCircleSetAngleXCut(490, 303, 98, 2 * PI - PI * 1 / 4 , 2 * PI + PI * 1 / 5, hdc, 36, 117, 0, 245, 260);
	drawRect(400, 245, 570, 260, hdc, 36, 117, 0);

	//���
	//drawFilledCircleSetAngleXCut(500, 314, 98, PI * 4 / 5, PI * 9 / 6, hdc, 255, 155, 15, 260, 280,);
	drawFilledCircleSetAngleXCut(478, 303, 98, PI * 4 / 5, PI * 9 / 6, hdc, 255, 155, 15, 260, 280);
	drawFilledCircleSetAngleXCut(490, 303, 98, 2 * PI - PI * 1 / 4, 2 * PI + PI * 1 / 5, hdc, 255, 155, 15, 260, 280);
	drawRect(400, 260, 570, 280, hdc, 255, 155, 15);

	//��Ȳ
	drawFilledCircleSetAngleXCut(478, 303, 98, PI * 4 / 5, PI * 9 / 6, hdc, 252, 68, 8, 280, 300);
	drawFilledCircleSetAngleXCut(490, 303, 98, 2 * PI - PI * 1 / 4, 2 * PI + PI * 1 / 5, hdc, 252, 68, 8, 280, 300);
	drawRect(400, 280, 570, 300, hdc, 252, 68, 8);

	//����
	drawFilledCircleSetAngleXCut(478, 303, 98, PI * 4 / 5, PI * 9 / 6, hdc, 248, 44, 19, 300, 320);
	drawFilledCircleSetAngleXCut(490, 303, 98, 2 * PI - PI * 1 / 4, 2 * PI + PI * 1 / 5, hdc, 248, 44, 19, 300, 320);
	drawRect(400, 300, 570, 320, hdc, 248, 44, 19);

	//����
	drawFilledCircleSetAngleXCut(478, 303, 98, PI * 4 / 5, PI * 9 / 6, hdc, 145, 23, 84, 320, 340);
	drawFilledCircleSetAngleXCut(490, 303, 98, 2 * PI - PI * 1 / 4, 2 * PI + PI * 1 / 5, hdc, 145, 23, 84, 320, 340);
	drawRect(400, 320, 570, 340, hdc, 145, 23, 84);

	//�Ķ�
	drawFilledCircleSetAngleXCut(478, 303, 98, PI * 4 / 5, PI * 9 / 6, hdc, 18, 146, 253, 340, 360);
	drawFilledCircleSetAngleXCut(490, 303, 98, 2 * PI - PI * 1 / 4, 2 * PI + PI * 1 / 5, hdc, 18, 146, 253, 340, 360);
	
	drawFilledCircleSetAngleYDown(443, 315, 63, PI + PI * 1 / 4, PI + PI * 3 / 4, hdc, 18, 146, 253);
	drawFilledCircleSetAngleYDown(525, 315, 63, PI + PI * 1 / 4, PI + PI * 3 / 4, hdc, 18, 146, 253);
	drawRect(400, 340, 570, 360, hdc, 18, 146, 253);
}

void drawApple(const HDC& hdc) {
	drawLeaf(510, 200, 30, 30.f, hdc);
	drawBody(hdc);
	drawFilledCircle(590, 280, 40, hdc, 255, 255, 255);
}

void drawName(const HDC& hdc) {
	//��
	MoveToEx(hdc, 520, 430, NULL);
	LineTo(hdc, 540, 430);

	MoveToEx(hdc, 540, 430, NULL);
	LineTo(hdc, 525, 448);

	MoveToEx(hdc, 547, 425, NULL);
	LineTo(hdc, 547, 450);

	MoveToEx(hdc, 547, 435, NULL);
	LineTo(hdc, 555, 435);

	Ellipse(hdc, 535, 455, 550, 470);

	//��
	MoveToEx(hdc, 580, 430, NULL);
	LineTo(hdc, 600, 430);

	MoveToEx(hdc, 600, 430, NULL);
	LineTo(hdc, 575, 445);

	MoveToEx(hdc, 590, 435, NULL);
	LineTo(hdc, 602, 446);

	MoveToEx(hdc, 570, 450, NULL);
	LineTo(hdc, 610, 450);

	MoveToEx(hdc, 590, 450, NULL);
	LineTo(hdc, 590, 460);

	MoveToEx(hdc, 580, 455, NULL);
	LineTo(hdc, 580, 470);

	MoveToEx(hdc, 580, 470, NULL);
	LineTo(hdc, 600, 470);

	//��
	MoveToEx(hdc, 650, 430, NULL);
	LineTo(hdc, 628, 445);

	MoveToEx(hdc, 640, 435, NULL);
	LineTo(hdc, 655, 446);

	MoveToEx(hdc, 640, 435, NULL);
	LineTo(hdc, 655, 446);

	MoveToEx(hdc, 625, 455, NULL);
	LineTo(hdc, 657, 455);

	MoveToEx(hdc, 641, 455, NULL);
	LineTo(hdc, 641, 470);
}

inline void rotatePoint(double& x, double& y, double datumX, double datumY, float degree) {
	double dx = x - datumX;
	double dy = y - datumY;

	x = dx * cos(degree) + dy * sin(degree);
	y = dy * cos(degree) - dx * sin(degree);

	x += datumX;
	y += datumY;
}

void drawObj(vector<POSITION>& obj, const HDC& hdc, int _r, int _g, int _b) {
	for (auto& e : obj)
		SetPixel(hdc, e.x, e.y, RGB(_r, _g, _b));
}

void rotateObj(int datumX, int datumY, vector<POSITION>& obj, float rotateDegree) {
	for (auto& e : obj) 
		rotatePoint(e.x, e.y, datumX, datumY, rotateDegree);

}

void drawFlower(vector<POSITION>& obj, const HDC& hdc) {
	drawObj(obj, hdc, 150, 123, 220);

	for (int i = 0; i < 24; ++i) {
		rotateObj(300, 300, obj, rad);
		drawObj(obj, hdc, 150, 123, 220);
	}
}
//������ ���ν���, �޼����� �ü���� �����Ѵ�. ������ �ü���� ȣ����.
//hWnd : �����찡 �߻��� �޼������� ����
//iMessage : �޼��� ���й�ȣ
//wParam : ���콺 ��ư�� ����, Ű���� ����Ű�� ���¸� ���� unsigned int
//lParam : ���콺�� Ŭ����ǥ�� ����                        unsigned long
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC : device context, ��¿� ���� �ɼ��� ����Ʈ�� ����
	//HDC, DC�ڵ��� �̿��ϸ� GDI��⿡ ���� ���� �ȴ�.
	//GDIȭ�� ó���� �׷��� ���
	//HDC��¿� �ʿ��� ������ ������ ������ ����(��ǥ, ����, �� ��� ��¿� �ʿ��� ��� ����)
	//PAINTSTRUCT : ������ Ŭ���̾�Ʈ ������ �׸��µ� �̿�
	HDC hdc;
	PAINTSTRUCT ps;
	int pos_x = 100;
	int pos_y = 100;

	vector<POSITION> obj;
	for (int i = 100; i < 200; ++i) 
		for (int j = 100; j < 200; ++j) 
			obj.push_back(POSITION((double)j, (double)i));

	/*
		InvalidateRect : 
		�������� �Ϻκ��� ��ȿȭ �����ش�.
	*/

	switch (iMessage)
	{
	case WM_CREATE:  //������ ���۽� �ѹ��� ����
		break;
	case WM_PAINT: //�������� �۾������� �սǵǾ����� ����
		hdc = BeginPaint(hWnd, &ps);
	
		//TODO1 : ���� �ΰ� �׷�����
		//drawApple(hdc);

		//TODO2 : Line���� �̸� �׸���
		//drawName(hdc);

		//drawFlower(obj, hdc);



		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		break;
	case WM_KEYUP: //Ű�� �����ٰ� ������
		break;
	case WM_LBUTTONDOWN: //���콺
		
		break;
	case WM_LBUTTONUP:
		break;
	case WM_DESTROY: //������ ����� �ѹ��� ����
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}