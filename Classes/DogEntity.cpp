#include "DogEntity.h"

USING_NS_CC;

bool DogEntity::init() {
}

DogEntity* DogEntity::dog() {
	return initWithDogImage();
}

DogEntity* DogEntity::initWithDogImage() {
	auto dog = Entity::initWithFilename("trendoc.png");
	if (dog) {

	}

	return (DogEntity*)dog;
}
