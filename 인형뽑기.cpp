#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace bangtal;
using namespace std;


ObjectPtr doll[3][5];
int main(void) {
	srand(time(NULL));
	int dollnum[3][5];
	int k = 0;
	int zip_x = 0, zip_y = 540;
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	auto scene= Scene::create("뽑기", "Images/배경.jpg");
	auto zip = Object::create("Images/뽑기.jpg", scene, zip_x, zip_y);
	auto push = Object::create("Images/그림5.png", scene, 840, 20);
	auto start = Object::create("Images/시작버튼.png", scene, 508, 20);
	auto timer = Timer::create(0.2f);
	auto timer2 = Timer::create(0.2f);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int a = rand() % 4;
			string filename = "images/" + to_string(a+ 1) + ".jpg";
			doll[i][j] =Object::create(filename, scene, 300+130*j,110+130*i);
			dollnum[i][j] = a + 1;	
		}
	}

	start->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer->set(0.2f);
		timer->start();
		return true;
		});

	timer->setOnTimerCallback([&](TimerPtr timer)->bool {
		zip_x += 50;
		zip->locate(scene, zip_x, zip_y);
		push->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			k = 1;
			return true; });
		if (k == 1)
			Sleep(200);
		
			timer->set(0.2f);
			timer->start();
			if (zip_x > 900)
				zip_x = 0;
		
		return true;
		});

	timer2->setOnTimerCallback([&](TimerPtr timer)->bool {

		timer->start();

		return true;
		});


	

	startGame(scene);


	return 0;
}