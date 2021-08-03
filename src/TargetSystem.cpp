#include "pch.h"
#include "TargetSystem.h"


TargetSystem::TargetSystem() : number(0), multiply(0), result(0), index(0)
{
}


TargetSystem::~TargetSystem()
{
}


bool TargetSystem::initialize(sf::Texture* texture) {
	std::srand(time(0));

	if (!font.loadFromFile("res/fonts/pixelFont.ttf")) {
		std::cerr << "Load font int TragetSystem failed\n";
		return false;
	}

	//Targets initialization
	//-------------------------------------------------------------------------------------------------------
	Target localTarget;
	localTarget.initialize(texture, sf::IntRect(TILE_SIZE * 3, TILE_SIZE, TILE_SIZE, TILE_SIZE), font);
	localTarget.initializeText(resizer(30, 20), sf::Color::Black);
	localTarget.setScale(resizer(4.0f, 3.0f));
	localTarget.setStringNumber();
	
	const float POS_Y = static_cast<float>(GameWindow::getWindowSize().y / 3);
	sf::Vector2f position(
		GameWindow::getWindowSize().x - localTarget.getRect().width, 
		POS_Y - resizer(300.0f, 200.0f));
	localTarget.setPosition(position);

	for (int i = 0; i < 3; i++) {
		targets.push_back(localTarget);
	}

	for (int i = 1; i < targets.size(); i++) {
		position.y += POS_Y;
		targets.at(i).setPosition(position);
	}


	//Game logic initialization
	//-------------------------------------------------------------------------------------------------------
	random();
	operation.setFont(font);
	operation.setString(std::to_string(number) + " * " + std::to_string(multiply) + " = ?");
	operation.setCharacterSize(resizer(60, 40));
	operation.setFillColor(sf::Color::Green);
	operation.setPosition(sf::Vector2f(
		GameWindow::getWindowSize().x / 2 - operation.getGlobalBounds().width / 2,
		resizer(40.0f, 30.0f)
	));

	//Sounds initialization
	//-------------------------------------------------------------------------------------------------------
	if (!arrowCollisionBuffer.loadFromFile("res/sounds/arrow-collision.wav"))
		std::cerr << "Load arrow-fly.wav failed!\n";
	arrowCollisionSound.setBuffer(arrowCollisionBuffer);

	return true;
}


void TargetSystem::draw() {
	for (auto target : targets)
		target.draw();

	GameWindow::draw(operation);
}


void TargetSystem::update(Player* player, WeaponSystem* weaponSystem) {
	for (auto& arrow : weaponSystem->getArrows()) {
		for (auto& target : targets) {
			if (Collision::collisionAABB(arrow.getRect(), target.getRect())) {
				arrowCollisionSound.play();
				if (target.getNumber() == result) {
					targets.at(index - 1).setTextColor(sf::Color::Black);
					random();
					player->addScore(10);
					arrow.setState(BulletState::NOT_SHOOT);
				}
				else {
					player->deincrementChances();
					targets.at(index - 1).setTextColor(sf::Color::Green);
					arrow.setState(BulletState::NOT_SHOOT);
				}
			}
		}
	}
}


void TargetSystem::random() {
	for (auto& target : targets) {
		int randomNumber = std::rand() % 100 + 1;
		target.setNumber(randomNumber);
	}

	index = std::rand() % 3 + 1;
	number = std::rand() % 10 + 1;
	multiply = std::rand() % 10 + 1;
	result = number * multiply;
	targets.at(index - 1).setNumber(result);
	operation.setString(std::to_string(number) + " * " + std::to_string(multiply) + " = ?");

	for (auto& target : targets) {
		if (result >= 100) target.setTextSize(resizer(20, 15));
		else target.setTextSize(resizer(30, 20));
		target.setStringNumber();
	}
}
