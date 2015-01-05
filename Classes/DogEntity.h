#ifndef DOGENTITY_H_
#define DOGENTITY_H_

#include "cocos2d.h"
#include "Entity.h"

class DogEntity : public Entity {
public:

	virtual bool init();
	static DogEntity* dog();
	CREATE_FUNC(DogEntity);
private:
	static DogEntity* initWithDogImage();
};

#endif
