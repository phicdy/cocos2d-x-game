#ifndef ENEMYENTITY_H_
#define ENEMYENTITY_H_

#include "cocos2d.h"
#include "Entity.h"

class EnemyEntity : public Entity {
public:
	enum EnemyTypes {EnemyTypeVirus, EnemyTypeBoss, EnemyType_MAX};

	EnemyEntity* enemyWithType(EnemyTypes enemyType);
	void initSpawnFrequency();
	int getSpawnFrequencyForEnemyType(EnemyTypes enemyType);
	void spawn();

	CREATE_FUNC(EnemyEntity);
private:
	EnemyTypes type;
};

#endif
