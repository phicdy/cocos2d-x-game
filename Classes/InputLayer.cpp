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
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"

USING_NS_CC;

bool InputLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	this->addFireButton();
	this->addJoyStick();
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

void InputLayer::addJoyStick() {
	float stickRadius = 50;

	joystick = new SneakyJoystick();
	joystick->initWithRect(CCRectMake(0, 0, 100.0f, 100.0f));
	joystick->setAutoCenter(true);
	joystick->setHasDeadzone(true);
	joystick->setDeadRadius(10);

	SneakyJoystickSkinnedBase *skinjoystick = SneakyJoystickSkinnedBase::create();
	skinjoystick->setPosition(stickRadius * 1.5f, stickRadius * 1.5f);
	skinjoystick->setBackgroundSprite(Sprite::create("button-disabled.png"));
	skinjoystick->getBackgroundSprite()->setColor(ccMAGENTA);
	skinjoystick->setThumbSprite(Sprite::create("button-disabled.png"));
	skinjoystick->getThumbSprite()->setScale(0.5f);
	skinjoystick->setJoystick(joystick);

	this->addChild(skinjoystick);
}

void InputLayer::update(float delta) {
	GameScene *game = GameScene::getSharedGameScene();
	totalTime += delta;
	if (fireButton->getIsActive() && totalTime > nextShotTime) {
		nextShotTime = totalTime + 0.5f;

		game->shootBulletFromTrendoc(game->trendoc);
		CCLOG("Fire!");
	}

	if (!fireButton->getIsActive()) {
		nextShotTime = 0;
	}

	Sprite *trendoc = game->trendoc;
	Point velocity = ccpMult(joystick->getVelocity(), 200);
	CCLOG("joystick velocity.x: %c",joystick->getVelocity().x);
	CCLOG("joystick velocity.y: %c",joystick->getVelocity().y);
	if (velocity.x != 0 && velocity.y != 0) {
		trendoc->setPosition(trendoc->getPosition().x + velocity.x * delta, trendoc->getPosition().y + velocity.y * delta);
	}

}


