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
