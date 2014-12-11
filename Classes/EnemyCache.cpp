#include "EnemyCache.h"
#include "EnemyEntity.h"

USING_NS_CC;
void EnemyCache::initEnemies() {

	// create the enemies array containing further arrays for each type
	enemies = CCArray::create();
	enemies->initWithCapacity(EnemyEntity::EnemyType_MAX);

	// create the arrays for each type
	for (int i = 0; i < EnemyEntity::EnemyType_MAX; i++) {
		// depending on enemy type the array capacity is set to hold the desired number of enemies
		int capacity;
		switch (i) {
		case EnemyEntity::EnemyTypeVirus:
			capacity = 3;
			break;
		case EnemyEntity::EnemyTypeBoss:
			capacity = 1;
			break;

		default:
			break;
		}

		// no alloc needed since the enemies array will retain anything added to it
		CCArray* enemiesOfType = CCArray::create();
		enemiesOfType->createWithCapacity(capacity);
		enemies->addObject(enemiesOfType);
	}

	for (int i = 0; i < EnemyEntity::EnemyType_MAX; i++) {
		CCArray* enemiesOfType = (CCArray*)enemies->objectAtIndex(i);
		int numEnemiesOfType = enemiesOfType->capacity();

		for (int j = 0; j < numEnemiesOfType; j++) {
			EnemyEntity* enemy = EnemyEntity::enemyWithType((EnemyEntity::EnemyTypes)i);
			batch->addChild(enemy, 0, i);
			enemiesOfType->addObject(enemy);
		}
	}
}
