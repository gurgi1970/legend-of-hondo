/*
 *	server/zone/managers/loot/lootgroup/LootObject.h generated by engine3 IDL compiler 0.61
 */

#ifndef LOOTOBJECT_H_
#define LOOTOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

#include "engine/lua/Lua.h"

#include "system/lang/ref/Reference.h"

namespace server {
namespace zone {
namespace managers {
namespace loot {
namespace lootgroup {

class LootObject : public ManagedObject {
public:
	LootObject(unsigned int loID, String& n, unsigned int tCRC, unsigned int lootG, int ch);

	void check(String& newName, unsigned int newTemplateCRC, int newChance);

	unsigned int getTemplateCRC();

	int getChance();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	LootObject(DummyConstructorParameter* param);

	virtual ~LootObject();

	friend class LootObjectHelper;
};

} // namespace lootgroup
} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot::lootgroup;

namespace server {
namespace zone {
namespace managers {
namespace loot {
namespace lootgroup {

class LootObjectImplementation : public ManagedObjectImplementation {
protected:
	unsigned int templateCRC;

	unsigned int lootGroup;

	String name;

	unsigned int lootObjectID;

	int chance;

public:
	LootObjectImplementation(unsigned int loID, String& n, unsigned int tCRC, unsigned int lootG, int ch);

	LootObjectImplementation(DummyConstructorParameter* param);

	void check(String& newName, unsigned int newTemplateCRC, int newChance);

	unsigned int getTemplateCRC();

	int getChance();

	LootObject* _this;

	operator const LootObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~LootObjectImplementation();

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

	friend class LootObject;
};

class LootObjectAdapter : public ManagedObjectAdapter {
public:
	LootObjectAdapter(LootObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void check(String& newName, unsigned int newTemplateCRC, int newChance);

	unsigned int getTemplateCRC();

	int getChance();

protected:
	String _param0_check__String_int_int_;
};

class LootObjectHelper : public DistributedObjectClassHelper, public Singleton<LootObjectHelper> {
	static LootObjectHelper* staticInitializer;

public:
	LootObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<LootObjectHelper>;
};

} // namespace lootgroup
} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot::lootgroup;

#endif /*LOOTOBJECT_H_*/
