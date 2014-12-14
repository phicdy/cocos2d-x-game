#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::bullet() {
	return initWithBulletImage();
}

bool Bullet::init() {
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

Bullet* Bullet::initWithBulletImage() {
	auto bullet = Sprite::create("bullet.png");

	return (Bullet*)bullet;
}

void Bullet::shootBulletAt(Point startPosition, Point vel, std::string frameName) {
	velocity = vel;
	this->setPosition(startPosition);
	this->setVisible(true);

	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
	this->setSpriteFrame(frame);

	this->schedule(schedule_selector(Bullet::updateBullet));

	RotateBy *rotate = RotateBy::create(1, -360);
	RepeatForever *repeaat = RepeatForever::create(rotate);
	this->runAction(rotate);
}

void Bullet::shootBulletFromTrendoc(Sprite *trendoc) {
	float spread = (CCRANDOM_0_1()- 0.5f) * 0.5f;
	velocity = Point(1, spread);

	outsideScreen = Director::getInstance()->getWinSize().width;

	this->setPosition(Vec2(trendoc->getPosition().x + trendoc->getContentSize().width * 0.5f, trendoc->getPosition().y));
	this->setVisible(true);

	this->schedule(schedule_selector(Bullet::updateBullet));
}

void Bullet::updateBullet(float delta) {
	auto position = this->getPosition();
	position.x += 15;
	this->setPosition(position);

	if (this->getPosition().x > outsideScreen) {
		this->setVisible(false);
		this->unscheduleAllSelectors();
	}
}
