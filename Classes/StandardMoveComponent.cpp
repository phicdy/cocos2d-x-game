#include "StandardMoveComponent.h"
#include "Entity.h"
#include "GameScene.h"

USING_NS_CC;

bool StandardMoveComponent::init() {
	if (!Sprite::init()) {
		return false;
	}

	velocity = CCPointMake(-1, 0);

	this->scheduleUpdate();
	return true;
}

void StandardMoveComponent::update(float delta) {
	if (this->getParent()->isVisible()) {
		Entity* entity = (Entity*)this->getParent();
		if (entity->getPosition().x > GameScene::getSharedGameScene()->getContentSize().width * 0.5f) {
			entity->setPosition(ccpAdd(entity->getPosition(), velocity));
		}
	}
}
