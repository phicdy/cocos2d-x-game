#include "StandardShootComponent.h"
#include "GameScene.h"

USING_NS_CC;

bool StandardShootComponent::init() {
	if (!Sprite::init()) {
		return false;
	}

	this->scheduleUpdate();

	return true;
}

void StandardShootComponent::update(float delta) {
	Node *parent = this->getParent();
	if (parent->isVisible()) {
		updateCount++;

		if (updateCount >= shootFrequency) {
			//CCLOG(@"enemy %@ shoots!", self.parent);
			updateCount = 0;

			GameScene* game = GameScene::getSharedGameScene();
			Point startPos = ccpSub(parent->getPosition(),
					CCPointMake(parent->getContentSize().width * 0.5f, 0));
//		[game.bulletCache shootBulletFrom:startPos velocity:CGPointMake(-2, 0) frameName:bulletFrameName];
	}
}

}
