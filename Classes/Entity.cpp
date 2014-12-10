#include "Entity.h"

USING_NS_CC;

void Entity::setPosition(float x, float y) {

	if (GameScene::getSharedGameScene()->getBoundingBox().intersectsRect(this->getBoundingBox())) {
		Size screensize = Director::getInstance()->getVisibleSize();
		float halfWidth = this->getContentSize().width * 0.5f;
		float halfHeight = this->getContentSize().height * 0.5f;

		if (x < halfWidth) {
			x = halfWidth;
		}else if (x > (screensize.width - halfWidth)) {
			x = screensize.width - halfWidth;
		}

		if (y < halfHeight) {
			y = halfHeight;
		}else if (y > (screensize.height - halfHeight)) {
			y = screensize.height - halfHeight;
		}
	}
	Sprite::setPosition(x, y);
}
