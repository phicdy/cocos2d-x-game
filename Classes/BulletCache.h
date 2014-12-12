#ifndef BULLETCACHE_H_
#define BULLETCACHE_H_

#include "cocos2d.h"

class BulletCache : public cocos2d::Node {
public:

	cocos2d::SpriteBatchNode* batch;
	int nextInactiveBullet;

	virtual bool init();
	void shootBulletFrom(cocos2d::Point startPosition, cocos2d::Point velocity, std::string frameName);

	CREATE_FUNC(BulletCache);
};

#endif
