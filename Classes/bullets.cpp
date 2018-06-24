#include"bullets.h"
#include"soldier.h"

//__Array * bulletArray;


Bullet* Bullet::createBullet(const char *spriteFrameName)
{
	Bullet *bullet = new Bullet();  //实例化building对象
	bullet->initWithFile(spriteFrameName);
	/*switch (building->buildingTypes)
	{
	case FactoryPG:
	{
		bullet->createAircraftBullet(point);
		break;
	}
	case AircraftZ:
	{
		bullet->createAircraftBullet(point);
		break;
	}
	/*case TankG:
	{
		bullet->createTankBullet(point);
		break;
	}
	case TankZ:
	{
		bullet->createTankBullet(point);
		break;
	}
	default:
		break;
	}*/
	return bullet;
	CC_SAFE_RELEASE(bullet);
}

/*Bullet* Bullet::createBullets(Soldier* soldier, Point point, float a)
{
	Bullet*bullet = new Bullet(soldier, point, a);
	switch (soldier->soldierType)
	{
	case SoldierG:
	{
		bullet->createTankBullet(point);
		break;
	}
	case SoldierZ:
	{
		bullet->createTankBullet(point);
		break;
	}
	case TankG:
	{
		bullet->createTankBullet(point);
		break;
	}
	case TankZ:
	{
		bullet->createTankBullet(point);
		break;
	}
	}
	return bullet;
}*/

void Bullet::createAircraftBullet(Point point)
{
	//bulletArray->retain();
	position = point;

	//CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	//cache->addSpriteFramesWithFile("aircraft_bullet.plist");
	this->initWithFile("aircraft_bullet.png");
	this->setPosition(Vec2(point.x + 10, point.y + 10));
	this->setScale(0.5);
	//bulletArray->addObject(this);//把子弹添加到数组里
	float distance = 500 - this->getPosition().x;
	float time = distance / BulletSpeedRatio;
	
	//MoveTo* moveTo = MoveTo::create(time, Vec2(200, this->getPosition().y));
	//this->runAction(moveTo);
	//RepeatForever * repeatforever = RepeatForever::create(moveTo);
	//this->runAction(repeatforever);
	//ActionInterval *ac = (ActionInterval*)this->runAction(CCMoveTo::create(time, Vec2(500, this->getPosition().y)));
	//this->runAction(RepeatForever::create(ac));
}

void Bullet::createTankBullet(Point point)
{
	//bulletArray->retain();
	position = point;

	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("tank_bullet.plist");
	this->initWithFile("tank_bullet.png");
	this->setPosition(ccp(point.x + 10, point.y + 10));
	this->setScale(0.5);
	//bulletArray->addObject(this);//把子弹添加到数组里
	//layer->addChild(this);//加入场景
	float distance = 500 - this->getPosition().x;
	float time = distance / BulletSpeedRatio;
	CCMoveTo *moveTo = CCMoveTo::create(time, ccp(500, this->getPosition().y));
	this->runAction(moveTo);
}

void Bullet::shoot(Soldier* soldier,Vec2 enemyPosition)
{
	this->setPosition(soldier->getPosition() + Vec2(soldier->getContentSize().width / 2, 0));
	p = enemyPosition;
	this->unscheduleUpdate();
	this->scheduleUpdate();        //开始更新游戏循环
}

void Bullet::update(float dt)
{
	Vec2 soldierPosition = this->getPosition();
	Vec2 sub = p - soldierPosition;
	float dis = sub.length();
	sub.normalize();
	if (dis > 3)
	{
		this->setPosition(Vec2(soldierPosition + sub));
	}
	else
	{
		this->unscheduleUpdate();
		this->removeFromParent();
	}
}

Bullet::~Bullet()
{

}