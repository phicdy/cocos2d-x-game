#include "EnemyEntity.h"

USING_NS_CC;

void EnemyEntity::enemyWithType(EnemyTypes enemyType) {
	type = enemyType;

	String *frameName;
	String *bulletFrameName;
	int shootFrequency = 300;
	switch (type) {
		case EnemyTypeVirus:
			frameName = String::create("virus.png");
//			bulletFrameName = "candystick.png";
			break;
		case EnemyTypeBoss:
//			frameName = @"monster-c.png";
//			bulletFrameName = @"blackhole.png";
			shootFrequency = 100;
			break;

		default:
			break;
	}

	if (this = Entity::create(frameName)) {
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
}

void EnemyEntity::initSpawnFrequency() {

}

