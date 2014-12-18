#include "EnemyCache.h"
#include "EnemyEntity.h"
#include "GameScene.h"
#include "Bullet.h";

USING_NS_CC;

bool EnemyCache::init() {

	if (!Node::init()) {
		return false;
	}

	batch = SpriteBatchNode::create("virus.png", 10);
	this->addChild(batch);

	initEnemies();
	this->scheduleUpdate();

	return true;
}

void EnemyCache::initEnemies() {

	// create the enemies array containing further arrays for each type
	enemies = CCArray::create();
	enemies->initWithCapacity(EnemyEntity::EnemyType_MAX);
	enemies->retain();

	// create the arrays for each type
	for (int i = 0; i < EnemyEntity::EnemyType_MAX; i++) {
		// depending on enemy type the array capacity is set to hold the desired number of enemies
		int capacity;
		switch (i) {
		case EnemyEntity::EnemyTypeVirus:
			capacity = 50;
			break;
//		case EnemyEntity::EnemyTypeBoss:
//			capacity = 1;
//			break;

		default:
			break;
		}

		// no alloc needed since the enemies array will retain anything added to it
		CCArray* enemiesOfType = CCArray::create();
		enemiesOfType->createWithCapacity(capacity);
		enemiesOfType->retain();
		enemies->insertObject(enemiesOfType, i);
	}

	for (int i = 0; i < EnemyEntity::EnemyType_MAX; i++) {
		CCArray* enemiesOfType = (CCArray*)enemies->objectAtIndex(i);
		int numEnemiesOfType = enemiesOfType->capacity();

		for (int j = 0; j < numEnemiesOfType; j++) {
			EnemyEntity* enemy = EnemyEntity::enemyWithType(i);
			batch->addChild(enemy, 0, i);
			enemiesOfType->addObject(enemy);
		}
	}
}

void EnemyCache::update(float delta) {
	updateCount++;

	for (int i = EnemyEntity::EnemyType_MAX - 1; i >= 0; i--) {
//		int spawnFrequency = EnemyEntity::getSpawnFrequencyForEnemyType(i);

		if (updateCount % 80 == 0) {
			spawnEnemyOfType(i);
			break;
		}
	}

	this->checkForBulletCollisions();
}

void EnemyCache::spawnEnemyOfType(int enemyType) {
	CCArray* enemiesOfType = (CCArray*)enemies->getObjectAtIndex(enemyType);

	Ref* enemy;
	CCARRAY_FOREACH(enemiesOfType, enemy) {
		EnemyEntity *entity = (EnemyEntity*)enemy;
		// find the first free enemy and respawn it
		if (!entity->isVisible()) {
			//CCLOG(@"spawn enemy type %i", enemyType);
			entity->spawn(entity);
			break;
		}
	}
}

void EnemyCache::checkForBulletCollisions() {
	for (auto node : batch->getChildren()) {
		EnemyEntity* enemy = (EnemyEntity*)node;
		if (enemy->isVisible()) {
			GameScene *game = GameScene::getSharedGameScene();
			int tag = game->getDogBulletTag();
			Bullet* bullet;
			for (int i = game->GameSceneNodeTagBulletDogBulletStart; i < tag; ++i) {
				bullet = (Bullet*)GameScene::getSharedGameScene()->getChildByTag(i);
				if (!bullet) {
					break;
				}
				if (!bullet->isVisible()) {
					continue;
				}

				if (enemy->getBoundingBox().intersectsRect(bullet->getBoundingBox())) {
					// This enemy got hit ...
					CCLog("hit!!");
					bullet->setVisible(false);
					enemy->gotHit();
				}
			}
		}
	}

}
