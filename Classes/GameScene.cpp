/*
 * GameScene.cpp
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#include "GameScene.h"
#include "InputLayer.h"
#include "Bullet.h"
#include "EnemyCache.h"
#include "DogEntity.h"
#include "SimpleAudioEngine.h"

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
	Point pos1 = background1->getPosition();
	Point pos2 = background2->getPosition();

	pos1.x -= 5.0f;
	pos2.x -= 5.0f;

	auto director = Director::getInstance();
	Size screensize = director->getWinSize();
	if(pos1.x <=-(screensize.width*0.5f) )
	{
		pos1.x = pos2.x + screensize.width;
	}

	if(pos2.x <=-(screensize.width*0.5f) )
	{
		pos2.x = pos1.x + screensize.width;
	}

	background1->setPosition(pos1);
	background2->setPosition(pos2);

//	checkForCollision();
}

void GameScene::initBackground() {
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	//マルチレゾリューション
//	Point origin = Director::getInstance()->getVisibleOrigin();
//
//	auto background = Sprite::create("background.jpg");
//	//中央に表示されるように座標を設定
//	background->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//	//画像を追加　第2引数は表示する順番（背景だから一番下つまり0）
//	this->addChild(background);
//
	background1 = Sprite::create("background.jpg");
	background2 = Sprite::create("background.jpg");

	auto director = Director::getInstance();
	Size screensize = director->getWinSize();
	background1->setPosition(screensize.width*0.5f,screensize.height*0.5f);
	addChild(background1);

	background2->setPosition(screensize.width+screensize.width*0.5f,screensize.height*0.5f);
	addChild(background2);

	//これをCCParallaxNodeクラスで利用します。
//	ParallaxNode* prallNode = ParallaxNode::create();
//	prallNode->setPosition(Point(-100,0));
//	prallNode->addChild(sprite1, 1, Point(3,0), Point(240,200));
//	prallNode->addChild(sprite2, 2, Point(1,0), Point(240,110));
//	this->addChild(prallNode);
}

void GameScene::initVirus() {
	EnemyCache *enemyCache = EnemyCache::create();
	CCLog("create enemyCache!");
	enemyCache->setTag(GameSceneNodeTagEnemyCache);
	CCLog("setTag!");
	this->addChild(enemyCache);
	CCLog("addChild!");
}

void GameScene::updateVirus(float delta) {
}
//
void GameScene::checkForCollision() {

}
//	if(nextInactiveBullet == 0) {
//		return;
//	}
//	BulletCache *bullets = this->getBullet();
//	Node *node = this->getChildByTag(GameSceneNodeTagBulletCache);
//	EnemyCache* enemyCache = (EnemyCache*)node;
//
//	for (i = 0; i < 50; ++i) {
//		Node *a = enemyCache->get
//		for (var = GameSceneNodeTagBulletDogBulletStart; var < GameSceneNodeTagBulletDogBullet; ++var) {
//			Node *tmp = this->getChildByTag(var);
//			Bullet *bulletOfDog = (Bullet*)tmp;
//
//			node = bulletsArray.at(nextInactiveBullet-1);
//			if (virus->getBoundingBox().intersectsRect(bulletOfDog->getBoundingBox())) {
//				CCLog("Collision!");
//				virus->unscheduleAllCallbacks();
//
//				//collision
//			}
//		}
//	}
//}

void GameScene::initBullet() {
	BulletCache *bulletCache = BulletCache::create();
	bulletCache->setTag(GameSceneNodeTagBulletCache);
	this->addChild(bulletCache);

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

int GameScene::getDogBulletTag() {
	return GameSceneNodeTagBulletDogBullet;
}

void GameScene::addDogBulletTag() {
	GameSceneNodeTagBulletDogBullet++;
}
