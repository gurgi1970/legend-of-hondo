/*
 *	server/zone/objects/tangible/consumable/Food.h generated by engine3 IDL compiler 0.61
 */

#ifndef FOOD_H_
#define FOOD_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/tangible/consumable/Consumable.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace consumable {

class Food : public Consumable {
public:
	Food();

	void initializeTransientMembers();

	void initializePrivateData();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	Food(DummyConstructorParameter* param);

	virtual ~Food();

	friend class FoodHelper;
};

} // namespace consumable
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::consumable;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace consumable {

class FoodImplementation : public ConsumableImplementation {

public:
	FoodImplementation();

	FoodImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void initializePrivateData();

	Food* _this;

	operator const Food*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~FoodImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class Food;
};

class FoodAdapter : public ConsumableAdapter {
public:
	FoodAdapter(FoodImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void initializePrivateData();

};

class FoodHelper : public DistributedObjectClassHelper, public Singleton<FoodHelper> {
	static FoodHelper* staticInitializer;

public:
	FoodHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FoodHelper>;
};

} // namespace consumable
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::consumable;

#endif /*FOOD_H_*/
