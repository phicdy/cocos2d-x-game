#include "EnemyEntity.h"
#include "GameScene.h"
#include "StandardShootComponent.h"

USING_NS_CC;

EnemyEntity* EnemyEntity::enemyWithType(int enemyType) {
	std::string frameName;
	std::string bulletFrameName;
	int shootFrequency = 300;
	switch (enemyType) {
		case EnemyTypeVirus:
			frameName = "virus.png";
			bulletFrameName = "f5.png";
			break;
//		case EnemyTypeBoss:
////			frameName = @"monster-c.png";
////			bulletFrameName = @"blackhole.png";
//			shootFrequency = 100;
//			break;

		default:
			break;
	}

	auto enemy = Entity::initWithFilename(frameName);
	EnemyEntity *enemyEntity = (EnemyEntity*)enemy;
	enemyEntity->type = enemyType;
	if (enemyEntity) {
		// Create the game logic components
//		[self addChild:[StandardMoveComponent node]];
//
		StandardShootComponent *shootComponent = StandardShootComponent::create();
		shootComponent->shootFrequency = shootFrequency;
		shootComponent->bulletFrameName = bulletFrameName;
		enemyEntity->addChild(shootComponent);

		// enemies start invisible
		enemyEntity->setVisible(false);

		initSpawnFrequency(enemyEntity);
	}

	return enemyEntity;
}

static CCArray *spawnFrequency;

void EnemyEntity::initSpawnFrequency(EnemyEntity *entity) {
	// initialize how frequent the enemies will spawn
	if (!spawnFrequency) {
		spawnFrequency = CCArray::create();
		spawnFrequency->insertObject(CCInteger::create(80), EnemyTypeVirus);
//		spawnFrequency->insertObject(CCInteger::create(1500), EnemyTypeBoss);

		// spawn one enemy immediately
		spawn(entity);
	}

}

int EnemyEntity::getSpawnFrequencyForEnemyType(int enemyType) {
	CCInteger *tmp = (CCInteger*)spawnFrequency->getObjectAtIndex(enemyType);
	return tmp->getValue();
}

void EnemyEntity::spawn(EnemyEntity *entity) {
	// Select a spawn location just outside the right side of the screen, with random y position
	Size screenSize = GameScene::getSharedGameScene()->getContentSize();
	Size spriteSize = entity->getContentSize();
	float xPos = screenSize.width + spriteSize.width * 0.5f;
	float yPos = CCRANDOM_0_1() * (screenSize.height - spriteSize.height) + spriteSize.height * 0.5f;
	entity->setPosition(xPos, yPos);

	// Finally set yourself to be visible, this also flag the enemy as "in use"
	entity->setVisible(true);
}


