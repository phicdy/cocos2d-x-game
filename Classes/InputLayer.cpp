/*
 * InputLayer.cpp
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#include "GameScene.h"
#include "InputLayer.h"
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"

USING_NS_CC;

bool InputLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	this->addFireButton();
	this->scheduleUpdate();
	return true;
}

void InputLayer::addFireButton() {
	float buttonRadius = 50;
	Size screensize = Director::getInstance()->getVisibleSize();

	fireButton = new SneakyButton();
	fireButton->initWithRect(Rect::ZERO);
	fireButton->setIsHoldable(true);

	SneakyButtonSkinnedBase *skinFireButton = SneakyButtonSkinnedBase::create();
	skinFireButton->setPosition(screensize.width - buttonRadius, buttonRadius);
	skinFireButton->setDefaultSprite(Sprite::create("button-default.png"));
	skinFireButton->setActivatedSprite(Sprite::create("button-default.png"));
	skinFireButton->setPressSprite(Sprite::create("button-pressed.png"));
	skinFireButton->setButton(fireButton);

	this->addChild(skinFireButton);
}

void InputLayer::update(float delta) {
	totalTime += delta;
	if (fireButton->getIsActive() && totalTime > nextShotTime) {
		nextShotTime = totalTime + 0.5f;

		GameScene *game = GameScene::getSharedGameScene();
		game->shootBulletFromTrendoc(game->trendoc);
		CCLOG("Fire!");
	}

	if (!fireButton->getIsActive()) {
		nextShotTime = 0;
	}
}


