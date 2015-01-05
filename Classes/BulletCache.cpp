#include "BulletCache.h"
#include "Bullet.h"

USING_NS_CC;

bool BulletCache::init() {
	if (!Node::init()) {
		return false;
	}

	batch = SpriteBatchNode::create("ffive.png", 10);
	this->addChild(batch);

	// Create a number of bullets up front and re-use them whenever necessary.
	for (int i = 0; i < 200; i++) {
		Bullet* bullet = Bullet::bullet();
		bullet->setVisible(false);
		batch->addChild(bullet);
	}

	return true;
}

void BulletCache::shootBulletFrom(cocos2d::Point startPosition,
	cocos2d::Point velocity, std::string frameName) {

	Vector<Node*> bullets = batch->getChildren();
	Node* node = bullets.at(nextInactiveBullet);

	Bullet* bullet = (Bullet*)node;
	bullet->shootBulletAt(startPosition, velocity, frameName);

	nextInactiveBullet++;
	if (nextInactiveBullet >= bullets.size())
	{
		nextInactiveBullet = 0;
	}

}
