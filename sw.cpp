#include <graphics.h>

// 圆形按钮
struct CircleButton
{
	int x, y;		/* 圆心*/
	int radius;		/* 半径*/
};

// 判断点(x, y)是否在按钮点击区域内部
bool insideButton(const CircleButton* button, int x, int y);

// 绘制所有按钮
void drawCircleButton(const CircleButton buttonArray[], int length);

// 查找 (x, y) 所在的按钮，返回按钮ID, 没有返回 -1
int searchButton(int x, int y, const CircleButton buttonArray[], int length);

// 绘制
void draw();

#define BUTTON_SIZE 8
#define BUTTON_ID_NONE -1

//定义按钮，确定区域
CircleButton buttonArray[BUTTON_SIZE];

// 按下按钮ID
int clickButtonId = BUTTON_ID_NONE;

int main()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	ege_enable_aa(true);
	
	for (int i = 0; i < BUTTON_SIZE; i++) {
		buttonArray[i].x = (i % 2 * 2 + 1) * 640 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 60;
		buttonArray[i].radius = 50;
	}
	
	clickButtonId = BUTTON_ID_NONE;
	
	bool redraw = true;
	int btnId = BUTTON_ID_NONE;
	
	for (; is_run(); delay_fps(60)) {
		
		while (mousemsg()) {
			mouse_msg msg = getmouse();
			
			// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域
			// 抬起则解除按下状态
			if (msg.is_left()) {
				if (msg.is_down()) {
					// 检查是否有按钮被按下
					btnId = searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE);
				}
				else {
					//左键抬起，判断是否有被点击的按钮，有则执行动作
					if (btnId != BUTTON_ID_NONE) {
						
					}
					
					//这里记录点击按钮ID并要求界面重绘
					if (btnId != clickButtonId) {
						clickButtonId = btnId;
						redraw = true;
					}
					
					btnId = BUTTON_ID_NONE;
				}
			}
		}
		
		// 判断是否需要重绘，减少不必要的绘制操作
		if (redraw) {
			cleardevice();
			draw();
			redraw = false;
		}
	}
	
	return 0;
}


bool insideButton(const CircleButton* button, int x, int y)
{
	int dx = x - button->x, dy = y - button->y;
	return (dx * dx + dy * dy) <= (button->radius * button->radius);
}

void drawCircleButton(const CircleButton buttonArray[], int length)
{
	setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setfont(36, 0, "");
	
	for (int i = 0; i < length; i++) {
		//高级绘图函数
		ege_fillellipse(buttonArray[i].x - buttonArray[i].radius,
			buttonArray[i].y - buttonArray[i].radius,
			2 * buttonArray[i].radius,
			2 * buttonArray[i].radius);
		xyprintf(buttonArray[i].x, buttonArray[i].y, "%d", i);
	}
}

int searchButton(int x, int y, const CircleButton buttonArray[], int length)
{
	int buttonId = BUTTON_ID_NONE;
	
	for (int i = 0; i < length; i++) {
		if (insideButton(&buttonArray[i], x, y)) {
			buttonId = i;
			break;   //退出，已经检测到，后面的按钮不再检测
		}
	}
	
	return buttonId;
}

void draw()
{
	//绘制
	drawCircleButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(24, 0, "");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(240, 360, "点击按钮ID:%d", clickButtonId);
}

