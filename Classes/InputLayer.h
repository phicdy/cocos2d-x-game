/*
 * InputLayer.h
 *
 *  Created on: 2014/11/25
 *      Author: pluea
 */

#ifndef INPUTLAYER_H_
#define INPUTLAYER_H_

#include "cocos2d.h"
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"

class InputLayer: public cocos2d::Layer {
public:
	SneakyButton *fireButton;

	virtual bool init();
	void addFireButton();
	void update(float delta);

	CREATE_FUNC(InputLayer);
};



#endif
