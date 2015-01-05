#include "StandardMoveComponent.h"
#include "Entity.h"
#include "GameScene.h"

USING_NS_CC;

bool StandardMoveComponent::init() {
	if (!Sprite::init()) {
		return false;
	}

	velocity = CCPointMake(-1, 0);

	this->schedule(schedule_selector(StandardMoveComponent::updateMoveComponent));
	return true;
}

void StandardMoveComponent::updateMoveComponent(float delta) {
	if (this->getParent()->isVisible()) {
		Node* entity = this->getParent();
//		if (entity->getPosition().x > GameScene::getSharedGameScene()->getContentSize().width * 0.5f) {
//			entity->setPosition(ccpAdd(entity->getPosition(), velocity));
//		}
		auto position = entity->getPosition();
		position.x -= 1;
		entity->setPosition(position);
		if (position.x < 0) {
			entity->setVisible(false);
		}
	}
}
