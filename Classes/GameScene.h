/*
 * GameScene.h
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"
#include "SneakyJoystick.h"
#include "BulletCache.h"
#include "DogEntity.h"

class GameScene: public cocos2d::Layer {
public:
	cocos2d::Point *trendocVelocity;
	cocos2d::Sprite *trendoc;
	cocos2d::Sprite *virus;
	int nextInactiveBullet = 0;
	SneakyJoystick *joystick;
	int GameSceneNodeTagBulletDogBulletStart = 100;

	enum LayerTag {GameSceneLayerTagGame,GameSceneLayerTagInput};

	static cocos2d::Scene*scene();
	static GameScene* getSharedGameScene();
	virtual bool init();

	void update(float delta);
	void initBackground();
	void initVirus();
	void initBullet();
	void updateVirus(float delta);
	void checkForCollision();

	BulletCache* getBullet();
	DogEntity* getDog();
	int getDogBulletTag();
	void addDogBulletTag();

	CREATE_FUNC(GameScene);
private:
	int GameSceneNodeTagEnemyCache = 1;
	int GameSceneNodeTagDog = 2;
	int GameSceneNodeTagBulletCache = 3;
	int GameSceneNodeTagBulletDogBullet = 100;
};



#endif /* GAMESCENE_H_ */
