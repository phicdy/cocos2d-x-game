/*
 * GameScene.h
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"


class GameScene: public cocos2d::Layer {
public:
	cocos2d::Point *trendocVelocity;
	cocos2d::Sprite *trendoc;
	cocos2d::Sprite *virus;

	static cocos2d::Scene*scene();
	virtual bool init();

	bool onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void update(float delta);
	void initBackground();
	void initVirus();
	void updateVirus(float delta);

	CREATE_FUNC(GameScene);

};



#endif /* GAMESCENE_H_ */