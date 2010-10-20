/*
 *	server/zone/objects/creature/Creature.cpp generated by engine3 IDL compiler 0.61
 */

#include "Creature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	CreatureStub
 */

Creature::Creature() : AiAgent(DummyConstructorParameter::instance()) {
	CreatureImplementation* _implementation = new CreatureImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

Creature::Creature(DummyConstructorParameter* param) : AiAgent(param) {
}

Creature::~Creature() {
}


bool Creature::isCreature() {
	CreatureImplementation* _implementation = (CreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCreature();
}

DistributedObjectServant* Creature::_getImplementation() {
	return _impl;}

void Creature::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	CreatureImplementation
 */

CreatureImplementation::CreatureImplementation(DummyConstructorParameter* param) : AiAgentImplementation(param) {
	_initializeImplementation();
}


CreatureImplementation::~CreatureImplementation() {
}


void CreatureImplementation::finalize() {
}

void CreatureImplementation::_initializeImplementation() {
	_setClassHelper(CreatureHelper::instance());

	_serializationHelperMethod();
}

void CreatureImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Creature*) stub;
	AiAgentImplementation::_setStub(stub);
}

DistributedObjectStub* CreatureImplementation::_getStub() {
	return _this;
}

CreatureImplementation::operator const Creature*() {
	return _this;
}

void CreatureImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void CreatureImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void CreatureImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void CreatureImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void CreatureImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void CreatureImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void CreatureImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void CreatureImplementation::_serializationHelperMethod() {
	AiAgentImplementation::_serializationHelperMethod();

	_setClassName("Creature");

}

CreatureImplementation::CreatureImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/Creature.idl(55):  		Logger.setLoggingName("Creature");
	Logger::setLoggingName("Creature");
	// server/zone/objects/creature/Creature.idl(56):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/creature/Creature.idl(57):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

bool CreatureImplementation::isCreature() {
	// server/zone/objects/creature/Creature.idl(61):  		return true;
	return true;
}

/*
 *	CreatureAdapter
 */

CreatureAdapter::CreatureAdapter(CreatureImplementation* obj) : AiAgentAdapter(obj) {
}

Packet* CreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(isCreature());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool CreatureAdapter::isCreature() {
	return ((CreatureImplementation*) impl)->isCreature();
}

/*
 *	CreatureHelper
 */

CreatureHelper* CreatureHelper::staticInitializer = CreatureHelper::instance();

CreatureHelper::CreatureHelper() {
	className = "Creature";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureHelper::finalizeHelper() {
	CreatureHelper::finalize();
}

DistributedObject* CreatureHelper::instantiateObject() {
	return new Creature(DummyConstructorParameter::instance());
}

DistributedObjectServant* CreatureHelper::instantiateServant() {
	return new CreatureImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CreatureHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CreatureAdapter((CreatureImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

