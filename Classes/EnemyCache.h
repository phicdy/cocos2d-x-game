#ifndef ENEMYCACHE_H_
#define ENEMYCACHE_H_

#include "cocos2d.h"
#include "EnemyEntity.h"

class EnemyCache : public cocos2d::Node {
public:

	cocos2d::SpriteBatchNode* batch;
	cocos2d::CCArray *enemies;
	int updateCount;

	virtual bool init();
	void initEnemies();
	void update(float delta);
	void spawnEnemyOfType(EnemyEntity::EnemyTypes enemyType);

	CREATE_FUNC(EnemyCache);
};

#endif
