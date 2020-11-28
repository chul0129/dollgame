#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
using namespace bangtal;

int main(void) {
	
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	auto scene= Scene::create("Othello", "Images/배경.jpg");
	auto rabbit1 = Object::create("Images/마시마로.jfif",scene, 300, 110);
	auto rabbit2= Object::create("Images/마시마로.jfif", scene, 560, 110);
	auto rabbit3 = Object::create("Images/마시마로.jfif", scene, 690, 110);
	auto child2 = Object::create("Images/짱구.jpg", scene, 820, 110);

	auto child = Object::create("Images/짱구.jpg", scene, 300, 240);
	auto lion = Object::create("Images/라이언.jpg", scene, 300, 370);
	auto bear = Object::create("Images/곰돌이.jpg", scene, 430,110);
	auto zip = Object::create("Images/뽑기.jpg", scene, 0, 540);
	auto push = Object::create("Images/그림5.png", scene, 840, 20);

	startGame(scene);


	return 0;
}