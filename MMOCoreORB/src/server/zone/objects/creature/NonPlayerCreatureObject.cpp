/*
 *	server/zone/objects/creature/NonPlayerCreatureObject.cpp generated by engine3 IDL compiler 0.61
 */

#include "NonPlayerCreatureObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	NonPlayerCreatureObjectStub
 */

NonPlayerCreatureObject::NonPlayerCreatureObject() : AiAgent(DummyConstructorParameter::instance()) {
	NonPlayerCreatureObjectImplementation* _implementation = new NonPlayerCreatureObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

NonPlayerCreatureObject::NonPlayerCreatureObject(DummyConstructorParameter* param) : AiAgent(param) {
}

NonPlayerCreatureObject::~NonPlayerCreatureObject() {
}


bool NonPlayerCreatureObject::isNonPlayerCreature() {
	NonPlayerCreatureObjectImplementation* _implementation = (NonPlayerCreatureObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isNonPlayerCreature();
}

DistributedObjectServant* NonPlayerCreatureObject::_getImplementation() {
	return _impl;}

void NonPlayerCreatureObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	NonPlayerCreatureObjectImplementation
 */

NonPlayerCreatureObjectImplementation::NonPlayerCreatureObjectImplementation(DummyConstructorParameter* param) : AiAgentImplementation(param) {
	_initializeImplementation();
}


NonPlayerCreatureObjectImplementation::~NonPlayerCreatureObjectImplementation() {
}


void NonPlayerCreatureObjectImplementation::finalize() {
}

void NonPlayerCreatureObjectImplementation::_initializeImplementation() {
	_setClassHelper(NonPlayerCreatureObjectHelper::instance());

	_serializationHelperMethod();
}

void NonPlayerCreatureObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (NonPlayerCreatureObject*) stub;
	AiAgentImplementation::_setStub(stub);
}

DistributedObjectStub* NonPlayerCreatureObjectImplementation::_getStub() {
	return _this;
}

NonPlayerCreatureObjectImplementation::operator const NonPlayerCreatureObject*() {
	return _this;
}

void NonPlayerCreatureObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void NonPlayerCreatureObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void NonPlayerCreatureObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void NonPlayerCreatureObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void NonPlayerCreatureObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void NonPlayerCreatureObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void NonPlayerCreatureObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void NonPlayerCreatureObjectImplementation::_serializationHelperMethod() {
	AiAgentImplementation::_serializationHelperMethod();

	_setClassName("NonPlayerCreatureObject");

}

NonPlayerCreatureObjectImplementation::NonPlayerCreatureObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/NonPlayerCreatureObject.idl(55):  		Logger.setLoggingName("NonPlayerCreatureObject");
	Logger::setLoggingName("NonPlayerCreatureObject");
	// server/zone/objects/creature/NonPlayerCreatureObject.idl(56):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/creature/NonPlayerCreatureObject.idl(57):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

bool NonPlayerCreatureObjectImplementation::isNonPlayerCreature() {
	// server/zone/objects/creature/NonPlayerCreatureObject.idl(61):  		return true;
	return true;
}

/*
 *	NonPlayerCreatureObjectAdapter
 */

NonPlayerCreatureObjectAdapter::NonPlayerCreatureObjectAdapter(NonPlayerCreatureObjectImplementation* obj) : AiAgentAdapter(obj) {
}

Packet* NonPlayerCreatureObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(isNonPlayerCreature());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool NonPlayerCreatureObjectAdapter::isNonPlayerCreature() {
	return ((NonPlayerCreatureObjectImplementation*) impl)->isNonPlayerCreature();
}

/*
 *	NonPlayerCreatureObjectHelper
 */

NonPlayerCreatureObjectHelper* NonPlayerCreatureObjectHelper::staticInitializer = NonPlayerCreatureObjectHelper::instance();

NonPlayerCreatureObjectHelper::NonPlayerCreatureObjectHelper() {
	className = "NonPlayerCreatureObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void NonPlayerCreatureObjectHelper::finalizeHelper() {
	NonPlayerCreatureObjectHelper::finalize();
}

DistributedObject* NonPlayerCreatureObjectHelper::instantiateObject() {
	return new NonPlayerCreatureObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* NonPlayerCreatureObjectHelper::instantiateServant() {
	return new NonPlayerCreatureObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* NonPlayerCreatureObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new NonPlayerCreatureObjectAdapter((NonPlayerCreatureObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

