#ifndef ENTITY_H_
#define ENTITY_H_

#include "cocos2d.h"

class Entity : public cocos2d::Sprite {
public:
	void setPosition(float x, float y);
	static Entity* initWithFilename(std::string filename);
	CREATE_FUNC(Entity);
};

#endif
