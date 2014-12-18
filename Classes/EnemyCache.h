#ifndef ENEMYCACHE_H_
#define ENEMYCACHE_H_

#include "cocos2d.h"

class EnemyCache : public cocos2d::Node {
public:

	cocos2d::SpriteBatchNode* batch;
	cocos2d::CCArray *enemies;
	int updateCount;

	virtual bool init();
	void initEnemies();
	void update(float delta);
	void spawnEnemyOfType(int enemyType);
	void checkForBulletCollisions();

	CREATE_FUNC(EnemyCache);
};

#endif
