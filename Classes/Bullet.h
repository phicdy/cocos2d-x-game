#ifndef BULLET_H_
#define BULLET_H_

#include "cocos2d.h"

class Bullet : public cocos2d::Sprite {
public:
	cocos2d::Point velocity;
	float outsideScreen;

	static Bullet* bullet();

	virtual bool init();
	static Bullet* initWithBulletImage();
	void shootBulletFromTrendoc(cocos2d::Sprite *trendoc);
	void updateBullet(float delta);

	CREATE_FUNC(Bullet);
};

#endif
