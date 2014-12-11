#ifndef ENEMYENTITY_H_
#define ENEMYENTITY_H_

#include "cocos2d.h"
#include "Entity.h"

class EnemyEntity : public Entity {
public:
	enum EnemyTypes {EnemyTypeVirus, EnemyTypeBoss, EnemyType_MAX};

	static EnemyEntity* enemyWithType(EnemyTypes enemyType);
	int getSpawnFrequencyForEnemyType(EnemyTypes enemyType);

	CREATE_FUNC(EnemyEntity);
private:
	static void initSpawnFrequency(EnemyEntity *entity);
	static void spawn(EnemyEntity *entity);
	static EnemyTypes type;
};

#endif
