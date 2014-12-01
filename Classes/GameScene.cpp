/*
 * GameScene.cpp
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#include "GameScene.h"

USING_NS_CC;

Scene *GameScene::scene()
//static cocos2d::Scene*scene();
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init()) {
		return false;
	}

	initBackground();
	initVirus();

	trendoc = Sprite::create("trendoc.png");
	trendoc->setTag(2);

	auto director = Director::getInstance();
	Size screensize = director->getWinSize();

	trendoc->setPosition(
			Vec2(trendoc->getContentSize().width / 2,
					trendoc->getContentSize().height / 2));
	this->addChild(trendoc, 0);

	// Enable touch
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	auto dip = Director::getInstance()->getEventDispatcher();
	dip->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();

	return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {

	auto virus = this->getChildByTag(1);
	virus->setPosition(virus->getPosition().x + 10,
			virus->getPosition().y + 10);
	return true;

}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {

	//繧ｿ繝�メ荳ｭ縺ｮ蜃ｦ逅�

}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {

	//繧ｿ繝�メ縺檎ｵゅｏ縺｣縺滓凾縺ｮ蜃ｦ逅�

}

void GameScene::update(float delta) {

	Vec2 position = trendoc->getPosition();
	position.x += 5;

	trendoc->setPosition(position);
}

void GameScene::initBackground() {

	//　背景
	Size winSize = Director::getInstance()->getVisibleSize();

	auto _bg = LayerColor::create(Color4B::WHITE, winSize.width,
			winSize.height);
	this->addChild(_bg);
}

void GameScene::initVirus() {
	virus = Sprite::create("virus.png");
	virus->setTag(1);
	virus->setPosition(Vec2(screensize.width / 2, screensize.height / 2));
	this->addChild(virus);
}

void GameScene::updateVirus(float delta) {

}
