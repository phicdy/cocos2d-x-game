#ifndef ENEMYCACHE_H_
#define ENEMYCACHE_H_

#include "cocos2d.h"

class EnemyCache : public cocos2d::Node {
public:
	cocos2d::SpriteBatchNode* batch;
	cocos2d::CCArray *enemies;
	void initEnemies();
	CREATE_FUNC(EnemyCache);
};

#endif
