/*
 * GameScene.cpp
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#include "GameScene.h"
#include "InputLayer.h"
#include "Bullet.h"
#include "SimpleAudioEngine.h"
#include "EnemyCache.h"
#include "DogEntity.h"

using namespace CocosDenshion;

USING_NS_CC;

static GameScene *instanceOfGameScene;

GameScene* GameScene::getSharedGameScene() {
	return instanceOfGameScene;
}

Scene *GameScene::scene()
//static cocos2d::Scene*scene();
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	auto inputLayer = InputLayer::create();

	// add layer as a child to scene
	scene->addChild(layer, 0, GameSceneLayerTagGame);
	scene->addChild(inputLayer, 1, GameSceneLayerTagInput);


	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init()) {
		return false;
	}

	instanceOfGameScene = this;

	initBackground();
	initVirus();
	initBullet();

	auto director = Director::getInstance();
	Size screensize = director->getWinSize();

	DogEntity* trendoc = DogEntity::dog();
	trendoc->setPosition(trendoc->getContentSize().width / 2,screensize.height / 2);
	trendoc->setTag(GameSceneNodeTagDog);
	this->addChild(trendoc);

	SimpleAudioEngine::getInstance()->preloadEffect("collision.mp3");

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float delta) {


	checkForCollision();
}

void GameScene::initBackground() {

	//　背景
	Size winSize = Director::getInstance()->getVisibleSize();

	auto _bg = LayerColor::create(Color4B::WHITE, winSize.width,
			winSize.height);
	this->addChild(_bg);
}

void GameScene::initVirus() {
	EnemyCache *enemyCache = EnemyCache::create();
	CCLog("create enemyCache!");
	enemyCache->setTag(GameSceneNodeTagEnemyCache);
	CCLog("setTag!");
	this->addChild(enemyCache, 0);
	CCLog("addChild!");
}

void GameScene::updateVirus(float delta) {
}

void GameScene::checkForCollision() {
	if(nextInactiveBullet == 0) {
		return;
	}
	BulletCache *bullets = this->getBullet();
	Vector<Node*> bulletsArray = bullets->getChildren();

	Node *node = bulletsArray.at(nextInactiveBullet-1);
	if (virus->getBoundingBox().intersectsRect(node->getBoundingBox())) {
		CCLog("Collision!");
		virus->unscheduleAllCallbacks();

		node->setPosition(-1,-1);
		node->setVisible(false);
		node->unscheduleAllCallbacks();
		SimpleAudioEngine::getInstance()->setEffectsVolume(0.5f);
		SimpleAudioEngine::getInstance()->playEffect("collision.mp3");

		CCAnimation* animation = CCAnimation::create();

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

		//アニメーションの設定 1 : 1コマ0.1秒で切り替える。
		animation->setDelayPerUnit(0.1);
		//アニメーションの設定 2 : 5回ループさせる。
		//(4コマかける5回ループで2秒になり、移動同時に終了するようにしている)
		animation->setLoops(1);
		//4. アニメーションの実行
		CCAnimate* animate = CCAnimate::create(animation);
//		virus->runAction(animate);
		CallFunc *compCallFunc = CallFunc::create([this](){
			virus->setVisible(false);
			virus->setPosition(-100,-100);
		 });

		 Sequence *sequence = Sequence::create(animate,compCallFunc,NULL);

		 virus->runAction(sequence);
	}
}

void GameScene::initBullet() {
	BulletCache *bulletCache = BulletCache::create();
	bulletCache->setTag(GameSceneNodeTagBulletCache);
	this->addChild(bulletCache, 1);

//	Bullet* tmp = Bullet::bullet();
//	SpriteFrame *frame = SpriteFrame::create("bullet.png", tmp->getBoundingBox());
	Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("bullet.png");
	Rect bounds = Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height);
	SpriteFrame *frame = SpriteFrame::createWithTexture(texture, bounds);

	SpriteFrameCache::getInstance()->addSpriteFrame(frame, "bullet.png");

//	Bullet* tmp2 = (Bullet*)Sprite::create("ffive.png");
//	SpriteFrame *frame2 = SpriteFrame::create("ffive.png", tmp2->getBoundingBox());
	Texture2D *texture2 = Director::getInstance()->getTextureCache()->addImage("ffive.png");
	Rect bounds2 = Rect(0, 0, texture2->getContentSize().width, texture2->getContentSize().height);
	SpriteFrame *frame2 = SpriteFrame::createWithTexture(texture2, bounds2);

	SpriteFrameCache::getInstance()->addSpriteFrame(frame2, "ffive.png");
}

BulletCache* GameScene::getBullet() {
	Node *node = this->getChildByTag(GameSceneNodeTagBulletCache);
	return (BulletCache*)node;
}

DogEntity* GameScene::getDog() {
	Node *node = this->getChildByTag(GameSceneNodeTagDog);
	return (DogEntity*)node;
}
