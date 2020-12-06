#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace bangtal;
using namespace std;

int dollnum[3][5];
int r = 0;
int cnt = 0;
ObjectPtr doll[3][5];
struct point {
	int num;
	ObjectPtr ptr;
	int k;
};
struct point y[15];
int* check_blank(ScenePtr scene,ObjectPtr doll[3][5],int  status[3][5],int a)
{
	int p;
	if ((a >= 250) && (a <= 350))
		p = 0;
	else if ((a >= 380) && (a <= 480))
		p = 1;
	else if ((a >= 510) && (a <= 610))
		p = 2;
	else if ((a >= 640) && (a <= 740))
		p = 3;
	else if ((a >= 770) && (a <= 870))
		p = 4;
	else
		p = 5;
	
	switch (p)
	{
	case 0: {
		int i;
		for( i=2;i>=0;i--)
		{
			if (status[i][0] == 1)
			{
				status[i][0] = 0;
				doll[i][0]->locate(scene, 1100, r * 52);
				doll[i][0]->setScale(0.4f);
				y[r].ptr = doll[i][0];
				y[r].k = r;
				y[r].num = dollnum[i][0];
				r++;
				cnt++;
				return &status[i][0];
				break;
			}
		}
		
		break;
	}
	case 1: {
		for (int i = 2; i >= 0; i--)
		{
			if (status[i][1] == 1)
			{
				status[i][1] = 0;
				doll[i][1]->locate(scene, 1100, r * 52);
				doll[i][1]->setScale(0.4f);
				y[r].ptr = doll[i][1];
				y[r].k = r;
				y[r].num = dollnum[i][1];
				cnt++;

				r++;				
				return &status[i][1];
				break;
			}
		}
		break;
	}
	case 2: {
		for (int i = 2; i >= 0; i--)
		{
			if (status[i][2] == 1)
			{
				status[i][2] = 0;			
				doll[i][2]->setScale(0.4f);
				doll[i][2]->locate(scene, 1100, r * 52);
				y[r].ptr = doll[i][2];
				y[r].k = r;
				y[r].num = dollnum[i][2];
				cnt++;

				r++;
				return &status[i][2];
				break;
			}
		}
		break;
	}
	case 3: {
		for (int i = 2; i >= 0; i--)
		{
			if (status[i][3] == 1)
			{
				status[i][3] = 0;
				doll[i][3]->setScale(0.4f);
				doll[i][3]->locate(scene, 1100, r * 52);
				y[r].ptr = doll[i][3];
				y[r].k = r;
				y[r].num = dollnum[i][3];
				cnt++;
				r++;
				return &status[i][3];
				break;
			}
		}
		break;
	}

	case 4: {
		for (int i = 2; i >= 0; i--)
		{
			if (status[i][4] == 1)
			{
				status[i][4] = 0;
				doll[i][4]->setScale(0.4f);
				doll[i][4]->locate(scene, 1100, r * 52);
				y[r].ptr = doll[i][4];
				y[r].k = r;
				y[r].num = dollnum[i][4];
				cnt++;
				r++;
				return &status[i][4];

				break;
			}
		}
		break;
	}
		  
	default:	break;
		return NULL;
	}
	

}
int main(void) {
	srand(time(NULL));
	
	int doll_status[3][5];
	int k = 0;
	int score = 0;
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
	for (int i = 0; i < 15; i++)
	{
		int a = 6;
		y[i].num = a;
		a++;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int a = rand() % 4;
			string filename = "images/" + to_string(a+1) + ".jpg";
			doll[i][j] =Object::create(filename, scene, 300+130*j,110+130*i);
			dollnum[i][j] = a +1;	
			doll_status[i][j] = 1;
		
		}
	}

	start->setOnMouseCallback([&](ObjectPtr object, int x, int , MouseAction action)->bool {
		
		timer2->stop();
		timer->set(0.2f);
		
		timer->start();
		return true;
		});

	timer->setOnTimerCallback([&](TimerPtr timer)->bool {
		if (cnt >= 15)
		{
			string t_score = "최종점수" + to_string(score ) + "입니다";
			showMessage(t_score);

		}
		timer2->stop();
		zip_y = 540;
		zip_x += 50;
		zip->locate(scene, zip_x, zip_y);

			timer->set(0.2f);
			timer->start();
		
		if (zip_x > 900)
			zip_x = 0;
		
		return true;
		});

	push->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer->stop();
		timer2->start();
		return true; });


	timer2->setOnTimerCallback([&](TimerPtr timer)->bool {
		timer->stop();
		if (cnt >= 15)
		{
			string t_score = "최종점수" + to_string(score) + "입니다";
			showMessage(t_score);

		}
		zip_y -= 50;
		zip->locate(scene, zip_x, zip_y);
		
		if ((zip_y<240)&&(check_blank(scene, doll, doll_status, zip_x)!=NULL))
		{
			timer2->stop();
			zip_y = 540;
			zip->locate(scene, zip_x, zip_y);
			for (int i = 0; i <r; i++)
			{
				if (y[i].num == y[i + 1].num)
				{
					y[i].ptr->hide();
					y[i + 1].ptr->hide();
					r=r-2;
					y[i].num = 100;
					y[i + 1].num = 101;
					score += 100;
					break;
				}
			}
		}
		else {
			if (zip_y < 0)
			{
				timer->stop();
				zip->locate(scene, zip_x, 540);
			}
			timer2->set(0.2f);
			timer2->start();
		}
		


		return true;
		});


	

	startGame(scene);

	



	return 0;
}
