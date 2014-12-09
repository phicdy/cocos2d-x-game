/*
 * InputLayer.cpp
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#include "InputLayer.h"

USING_NS_CC;

bool InputLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	this->addFireButton();

	return true;
}

void InputLayer::addFireButton() {
	float buttonRadius = 80;
	Size screensize = Director::getInstance()->getVisibleSize();

	fireButton = SneakyButton::initWithRect(Rect::ZERO);
	fireButton.radius = buttonRadius;
	fireButton->setPosition(screensize.width - buttonRadius, buttonRadius);

	this->addChild(fireButton);
}

