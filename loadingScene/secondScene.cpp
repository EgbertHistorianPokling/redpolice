#include"secondScene.h"

USING_NS_CC;

Scene* secondScene::createScene()
{
	auto scene = Scene::create();
	auto layer = secondScene::create();
	scene->addChild(layer);
	return scene;
}

bool secondScene::init()
{
	Texture2D * texture = TextureCache::sharedTextureCache()->textureForKey("HelloWorld.png");
	Sprite * m_sprite = Sprite::createWithTexture(texture);

	m_sprite->setPosition(ccp(200, 200));
	this->addChild(m_sprite);

	Texture2D * texture1 = TextureCache::sharedTextureCache()->textureForKey("CloseSelected.png");
	Sprite * m_sprite1 = Sprite::createWithTexture(texture1);
	m_sprite1->setPosition(ccp(100, 100));
	this->addChild(m_sprite1);

	Texture2D * texture2 = TextureCache::sharedTextureCache()->textureForKey("USA_building.png");
	Sprite * m_sprite2 = Sprite::createWithTexture(texture2);
	m_sprite2->setPosition(ccp(200, 200));
	this->addChild(m_sprite2);

	Texture2D * texture3 = TextureCache::sharedTextureCache()->textureForKey("USA tank.png");
	Sprite * m_sprite3 = Sprite::createWithTexture(texture3);
	m_sprite3->setPosition(ccp(300, 300));
	this->addChild(m_sprite3);

	Texture2D * texture4 = TextureCache::sharedTextureCache()->textureForKey("USA building3.png");
	Sprite * m_sprite4 = Sprite::createWithTexture(texture4);
	m_sprite4->setPosition(ccp(400, 400));
	this->addChild(m_sprite4);

	Texture2D * texture5 = TextureCache::sharedTextureCache()->textureForKey("USA building4.png");
	Sprite * m_sprite5 = Sprite::createWithTexture(texture5);
	m_sprite5->setPosition(ccp(50, 50));
	this->addChild(m_sprite5);

	Texture2D * texture6 = TextureCache::sharedTextureCache()->textureForKey("USA building5.png");
	Sprite * m_sprite6 = Sprite::createWithTexture(texture6);
	m_sprite6->setPosition(ccp(100, 100));
	this->addChild(m_sprite6);

	Texture2D * texture7 = TextureCache::sharedTextureCache()->textureForKey("CloseSelected.png");
	Sprite * m_sprite7 = Sprite::createWithTexture(texture7);
	m_sprite7->setPosition(ccp(100, 100));
	this->addChild(m_sprite7);

	Texture2D * texture8 = TextureCache::sharedTextureCache()->textureForKey("USSR ship.png");
	Sprite * m_sprite8 = Sprite::createWithTexture(texture8);
	m_sprite8->setPosition(ccp(100, 100));
	this->addChild(m_sprite8);

	Texture2D * texture9 = TextureCache::sharedTextureCache()->textureForKey("USSR ship2.png");
	Sprite * m_sprite9 = Sprite::createWithTexture(texture9);
	m_sprite9->setPosition(ccp(100, 100));
	this->addChild(m_sprite9);

	Texture2D * texture10 = TextureCache::sharedTextureCache()->textureForKey("USA soldier.png");
	Sprite * m_sprite10 = Sprite::createWithTexture(texture10);
	m_sprite10->setPosition(ccp(100, 100));
	this->addChild(m_sprite10);


	return true;
}
//图片极其大所以需要去弄小一点