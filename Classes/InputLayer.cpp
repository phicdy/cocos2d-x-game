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
#include "DogEntity.h"
#include "Bullet.h"

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

		DogEntity* trendoc = game->getDog();
		Point trendocPos = CCPointMake(trendoc->getPosition().x + trendoc->getContentSize().width * 0.5f, trendoc->getPosition().y);
		float spread = (CCRANDOM_0_1() - 0.5f) * 0.5f;
		Point velocity = CCPointMake(15, 0);

		Bullet *bullet = Bullet::initWithBulletForDoc();
		bullet->setTag(100);
		game->addChild(bullet);

		bullet->shootBulletAt(trendocPos, velocity, "bullet.png");
	}

	if (!fireButton->getIsActive()) {
		nextShotTime = 0;
	}

	DogEntity *trendoc = game->getDog();
	Point velocity = ccpMult(joystick->getVelocity(), 200);
	if (velocity.x != 0 && velocity.y != 0) {
		float newX = trendoc->getPosition().x + velocity.x * delta;
		float newY = trendoc->getPosition().y + velocity.y * delta;

		float halfWidth = trendoc->getContentSize().width * 0.5f;
		float halfHeight = trendoc->getContentSize().height * 0.5f;
		Size screensize = Director::getInstance()->getVisibleSize();

		if (newX < halfWidth) {
			newX = halfWidth;
		}else if (newX > (screensize.width - halfWidth)) {
			newX = screensize.width - halfWidth;
		}

		if (newY < halfHeight) {
			newY = halfHeight;
		}else if (newY > (screensize.height - halfHeight)) {
			newY = screensize.height - halfHeight;
		}

		trendoc->setPosition(newX, newY);
	}

}


