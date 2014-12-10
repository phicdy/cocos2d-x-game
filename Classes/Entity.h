#ifndef ENTITY_H_
#define ENTITY_H_

#include "cocos2d.h"

class Entity : public cocos2d::Sprite {
public:
	void setPosition(float x, float y);
	CREATE_FUNC(Entity);
};

#endif
