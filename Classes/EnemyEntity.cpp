#include "EnemyEntity.h"
#include "GameScene.h"
#include "StandardShootComponent.h"
#include "StandardMoveComponent.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

USING_NS_CC;

EnemyEntity* EnemyEntity::enemyWithType(int enemyType) {
	std::string frameName;
	std::string bulletFrameName;
	int shootFrequency = 100;
	switch (enemyType) {
		case EnemyTypeVirus:
			frameName = "virus.png";
			bulletFrameName = "ffive.png";
			break;
//		case EnemyTypeBoss:
////			frameName = @"monster-c.png";
////			bulletFrameName = @"blackhole.png";
//			shootFrequency = 100;
//			break;

		default:
			break;
	}

	auto enemy = Entity::initWithFilename(frameName);
	EnemyEntity *enemyEntity = (EnemyEntity*)enemy;
	enemyEntity->type = enemyType;
	if (enemyEntity) {
		// Create the game logic components
//		[self addChild:[StandardMoveComponent node]];
		enemyEntity->addChild(StandardMoveComponent::create());
//
		StandardShootComponent *shootComponent = StandardShootComponent::create();
		shootComponent->shootFrequency = shootFrequency;
		shootComponent->bulletFrameName = bulletFrameName;
		enemyEntity->addChild(shootComponent);

		// enemies start invisible
		enemyEntity->setVisible(false);

		initSpawnFrequency(enemyEntity);
	}

	return enemyEntity;
}

static CCArray *spawnFrequency;

void EnemyEntity::initSpawnFrequency(EnemyEntity *entity) {
	// initialize how frequent the enemies will spawn
	if (!spawnFrequency) {
		spawnFrequency = CCArray::create();
		spawnFrequency->insertObject(CCInteger::create(80), EnemyTypeVirus);
//		spawnFrequency->insertObject(CCInteger::create(1500), EnemyTypeBoss);

		// spawn one enemy immediately
//		spawn(entity);
	}

}

int EnemyEntity::getSpawnFrequencyForEnemyType(int enemyType) {
	CCInteger *tmp = (CCInteger*)spawnFrequency->getObjectAtIndex(enemyType);
	return tmp->getValue();
}

void EnemyEntity::spawn(EnemyEntity *entity) {
	// Select a spawn location just outside the right side of the screen, with random y position
	Size screenSize = GameScene::getSharedGameScene()->getContentSize();
	Size spriteSize = entity->getContentSize();
	float xPos = screenSize.width - spriteSize.width * 0.5f;
	float yPos = CCRANDOM_0_1() * (screenSize.height - spriteSize.height) + spriteSize.height * 0.5f;
	entity->setPosition(xPos, yPos);

	// Finally set yourself to be visible, this also flag the enemy as "in use"
	entity->setVisible(true);
}

void EnemyEntity::gotHit() {
//	this->setPosition(-1,-1);
//	this->setVisible(false);
	this->unscheduleAllCallbacks();
	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5f);
	SimpleAudioEngine::getInstance()->playEffect("collision.mp3");

	Animation* animation = Animation::create();

	// 移動1 → 停止 → 移動2 → 停止の4コマアニメーション
	animation->addSpriteFrameWithFileName("explosion1.png");
	animation->addSpriteFrameWithFileName("explosion2.png");
	animation->addSpriteFrameWithFileName("explosion3.png");
	animation->addSpriteFrameWithFileName("explosion4.png");
	animation->addSpriteFrameWithFileName("explosion5.png");
	animation->addSpriteFrameWithFileName("explosion6.png");
	animation->addSpriteFrameWithFileName("explosion7.png");
	animation->addSpriteFrameWithFileName("explosion8.png");
	animation->addSpriteFrameWithFileName("explosion9.png");
	animation->addSpriteFrameWithFileName("explosion10.png");
	animation->addSpriteFrameWithFileName("explosion11.png");
	animation->addSpriteFrameWithFileName("explosion12.png");
	animation->addSpriteFrameWithFileName("explosion13.png");
	animation->addSpriteFrameWithFileName("explosion14.png");
	animation->addSpriteFrameWithFileName("explosion15.png");

//	for (int i = 1; i < 16; i++){
//		auto str = __String::createWithFormat("explosion%i.png",i);
//		Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(str->getCString());
//		Rect bounds = Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height);
//		SpriteFrame *sprite = SpriteFrame::createWithTexture(texture, bounds);
//		animation->addSpriteFrame(sprite);
//	 }
	//アニメーションの設定 1 : 1コマ0.1秒で切り替える。
	animation->setDelayPerUnit(0.1);
	//アニメーションの設定 2 : 5回ループさせる。
	//(4コマかける5回ループで2秒になり、移動同時に終了するようにしている)
	animation->setLoops(1);
	//4. アニメーションの実行
	Animate* animate = Animate::create(animation);
//		this->runAction(animate);
	CallFunc *compCallFunc = CallFunc::create([this](){
		this->setVisible(false);
		this->setPosition(-100,-100);
	 });

	 Sequence *sequence = Sequence::create(animate,compCallFunc,NULL);

	 GameScene* game = GameScene::getSharedGameScene();
	 game->addChild(this);
	 this->runAction(sequence);
}


