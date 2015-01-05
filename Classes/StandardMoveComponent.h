#ifndef STANDARDMOVECOMPONENT_H_
#define STANDARDMOVECOMPONENT_H_

#include "cocos2d.h"

class StandardMoveComponent : public cocos2d::Sprite {
public:
	virtual bool init();
	void updateMoveComponent(float delta);
	CREATE_FUNC(StandardMoveComponent);
private:
	cocos2d::Point velocity;

};

#endif
