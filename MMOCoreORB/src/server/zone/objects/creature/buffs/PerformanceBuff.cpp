/*
 *	server/zone/objects/creature/buffs/PerformanceBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "PerformanceBuff.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/buffs/PowerBoostBuffDurationEvent.h"

/*
 *	PerformanceBuffStub
 */

enum {RPC_ACTIVATE__BOOL_ = 6,RPC_GETBUFFSTRENGTH__,RPC_DEACTIVATE__BOOL_};

PerformanceBuff::PerformanceBuff(CreatureObject* creo, unsigned int buffCRC, float value, int duration, int typeOfBuff) : Buff(DummyConstructorParameter::instance()) {
	PerformanceBuffImplementation* _implementation = new PerformanceBuffImplementation(creo, buffCRC, value, duration, typeOfBuff);
	_impl = _implementation;
	_impl->_setStub(this);
}

PerformanceBuff::PerformanceBuff(DummyConstructorParameter* param) : Buff(param) {
}

PerformanceBuff::~PerformanceBuff() {
}



void PerformanceBuff::activate(bool applyModifiers) {
	PerformanceBuffImplementation* _implementation = static_cast<PerformanceBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ACTIVATE__BOOL_);
		method.addBooleanParameter(applyModifiers);

		method.executeWithVoidReturn();
	} else
		_implementation->activate(applyModifiers);
}

float PerformanceBuff::getBuffStrength() {
	PerformanceBuffImplementation* _implementation = static_cast<PerformanceBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBUFFSTRENGTH__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getBuffStrength();
}

void PerformanceBuff::deactivate(bool removeModifiers) {
	PerformanceBuffImplementation* _implementation = static_cast<PerformanceBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEACTIVATE__BOOL_);
		method.addBooleanParameter(removeModifiers);

		method.executeWithVoidReturn();
	} else
		_implementation->deactivate(removeModifiers);
}

DistributedObjectServant* PerformanceBuff::_getImplementation() {

	_updated = true;
	return _impl;
}

void PerformanceBuff::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	PerformanceBuffImplementation
 */

PerformanceBuffImplementation::PerformanceBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


PerformanceBuffImplementation::~PerformanceBuffImplementation() {
}


void PerformanceBuffImplementation::finalize() {
}

void PerformanceBuffImplementation::_initializeImplementation() {
	_setClassHelper(PerformanceBuffHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void PerformanceBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<PerformanceBuff*>(stub);
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* PerformanceBuffImplementation::_getStub() {
	return _this;
}

PerformanceBuffImplementation::operator const PerformanceBuff*() {
	return _this;
}

void PerformanceBuffImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PerformanceBuffImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PerformanceBuffImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PerformanceBuffImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PerformanceBuffImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PerformanceBuffImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PerformanceBuffImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PerformanceBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("PerformanceBuff");

}

void PerformanceBuffImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(PerformanceBuffImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool PerformanceBuffImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuffImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "PerformanceBuff.strength") {
		TypeInfo<float >::parseFromBinaryStream(&strength, stream);
		return true;
	}

	if (_name == "PerformanceBuff.type") {
		TypeInfo<int >::parseFromBinaryStream(&type, stream);
		return true;
	}


	return false;
}

void PerformanceBuffImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = PerformanceBuffImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int PerformanceBuffImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = BuffImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "PerformanceBuff.strength";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&strength, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "PerformanceBuff.type";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&type, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return _count + 2;
}

PerformanceBuffImplementation::PerformanceBuffImplementation(CreatureObject* creo, unsigned int buffCRC, float value, int duration, int typeOfBuff) : BuffImplementation(creo, buffCRC, duration, BuffType::PERFORMANCE) {
	_initializeImplementation();
	// server/zone/objects/creature/buffs/PerformanceBuff.idl():  		strength = value;
	strength = value;
	// server/zone/objects/creature/buffs/PerformanceBuff.idl():  		type = typeOfBuff;
	type = typeOfBuff;
}

float PerformanceBuffImplementation::getBuffStrength() {
	// server/zone/objects/creature/buffs/PerformanceBuff.idl():  		return strength;
	return strength;
}

/*
 *	PerformanceBuffAdapter
 */

PerformanceBuffAdapter::PerformanceBuffAdapter(PerformanceBuff* obj) : BuffAdapter(obj) {
}

Packet* PerformanceBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ACTIVATE__BOOL_:
		activate(inv->getBooleanParameter());
		break;
	case RPC_GETBUFFSTRENGTH__:
		resp->insertFloat(getBuffStrength());
		break;
	case RPC_DEACTIVATE__BOOL_:
		deactivate(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PerformanceBuffAdapter::activate(bool applyModifiers) {
	(static_cast<PerformanceBuff*>(stub))->activate(applyModifiers);
}

float PerformanceBuffAdapter::getBuffStrength() {
	return (static_cast<PerformanceBuff*>(stub))->getBuffStrength();
}

void PerformanceBuffAdapter::deactivate(bool removeModifiers) {
	(static_cast<PerformanceBuff*>(stub))->deactivate(removeModifiers);
}

/*
 *	PerformanceBuffHelper
 */

PerformanceBuffHelper* PerformanceBuffHelper::staticInitializer = PerformanceBuffHelper::instance();

PerformanceBuffHelper::PerformanceBuffHelper() {
	className = "PerformanceBuff";

	Core::getObjectBroker()->registerClass(className, this);
}

void PerformanceBuffHelper::finalizeHelper() {
	PerformanceBuffHelper::finalize();
}

DistributedObject* PerformanceBuffHelper::instantiateObject() {
	return new PerformanceBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* PerformanceBuffHelper::instantiateServant() {
	return new PerformanceBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PerformanceBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PerformanceBuffAdapter(static_cast<PerformanceBuff*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

