#include "EnemyEntity.h"

USING_NS_CC;

EnemyEntity* EnemyEntity::enemyWithType(EnemyTypes enemyType) {
	type = enemyType;

	std::string frameName;
	std::string bulletFrameName;
	int shootFrequency = 300;
	switch (type) {
		case EnemyTypeVirus:
			frameName = "virus.png";
			bulletFrameName = "f5.png";
			break;
		case EnemyTypeBoss:
//			frameName = @"monster-c.png";
//			bulletFrameName = @"blackhole.png";
			shootFrequency = 100;
			break;

		default:
			break;
	}

	auto enemy = Entity::initWithFilename(frameName);
	if (enemy) {
		// Create the game logic components
//		[self addChild:[StandardMoveComponent node]];
//
//		StandardShootComponent* shootComponent = [StandardShootComponent node];
//		shootComponent.shootFrequency = shootFrequency;
//		shootComponent.bulletFrameName = bulletFrameName;
//		this->addChild(shootComponent);

		// enemies start invisible
		this->setVisible(false);

		initSpawnFrequency();
	}

	return (EnemyEntity*)enemy;
}

void EnemyEntity::initSpawnFrequency() {

}

