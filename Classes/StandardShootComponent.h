#ifndef STANDARDSHOOTCOMPONENT_H_
#define STANDARDSHOOTCOMPONENT_H_

#include "cocos2d.h"

class StandardShootComponent : public cocos2d::Sprite {
public:
	int updateCount;
	int shootFrequency;
	std::string bulletFrameName;

	virtual bool init();
	void update(float delta);
	CREATE_FUNC(StandardShootComponent);
};

#endif
