#ifndef ENEMYENTITY_H_
#define ENEMYENTITY_H_

#include "cocos2d.h"
#include "Entity.h"

class EnemyEntity : public Entity {
public:
	enum EnemyTypes {EnemyTypeVirus, EnemyTypeBoss, EnemyType_MAX};

	void enemyWithType(EnemyTypes enemyType);
	void initSpawnFrequency();
	CREATE_FUNC(EnemyEntity);
private:
	EnemyTypes type;
};

#endif
