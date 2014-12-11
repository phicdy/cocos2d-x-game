#ifndef ENEMYENTITY_H_
#define ENEMYENTITY_H_

#include "cocos2d.h"
#include "Entity.h"

class EnemyEntity : public Entity {
public:
	enum EnemyTypes {EnemyTypeVirus=0, EnemyTypeBoss, EnemyType_MAX};

	static EnemyEntity* enemyWithType(EnemyTypes enemyType);
	static int getSpawnFrequencyForEnemyType(EnemyTypes enemyType);
	static void spawn(EnemyEntity *entity);

	CREATE_FUNC(EnemyEntity);
private:
	static void initSpawnFrequency(EnemyEntity *entity);
	static EnemyTypes type;
};

#endif
