/*
 *	server/zone/objects/intangible/ControlDevice.cpp generated by engine3 IDL compiler 0.61
 */

#include "ControlDevice.h"

#include "server/zone/objects/creature/VehicleObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

/*
 *	ControlDeviceStub
 */

ControlDevice::ControlDevice() : IntangibleObject(DummyConstructorParameter::instance()) {
	ControlDeviceImplementation* _implementation = new ControlDeviceImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

ControlDevice::ControlDevice(DummyConstructorParameter* param) : IntangibleObject(param) {
}

ControlDevice::~ControlDevice() {
}


void ControlDevice::updateToDatabaseAllObjects(bool startTask) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(startTask);

		method.executeWithVoidReturn();
	} else
		_implementation->updateToDatabaseAllObjects(startTask);
}

void ControlDevice::storeObject(PlayerCreature* player) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->storeObject(player);
}

void ControlDevice::generateObject(PlayerCreature* player) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->generateObject(player);
}

void ControlDevice::setControlledObject(CreatureObject* object) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->setControlledObject(object);
}

CreatureObject* ControlDevice::getControlledObject() {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return (CreatureObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getControlledObject();
}

bool ControlDevice::isControlDevice() {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isControlDevice();
}

DistributedObjectServant* ControlDevice::_getImplementation() {
	return _impl;}

void ControlDevice::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	ControlDeviceImplementation
 */

ControlDeviceImplementation::ControlDeviceImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


ControlDeviceImplementation::~ControlDeviceImplementation() {
}


void ControlDeviceImplementation::finalize() {
}

void ControlDeviceImplementation::_initializeImplementation() {
	_setClassHelper(ControlDeviceHelper::instance());

	_serializationHelperMethod();
}

void ControlDeviceImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ControlDevice*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ControlDeviceImplementation::_getStub() {
	return _this;
}

ControlDeviceImplementation::operator const ControlDevice*() {
	return _this;
}

void ControlDeviceImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ControlDeviceImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ControlDeviceImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ControlDeviceImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ControlDeviceImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ControlDeviceImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ControlDeviceImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ControlDeviceImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("ControlDevice");

	addSerializableVariable("controlledObject", &controlledObject);
}

ControlDeviceImplementation::ControlDeviceImplementation() {
	_initializeImplementation();
	// server/zone/objects/intangible/ControlDevice.idl(61):  		controlledObject = null;
	controlledObject = NULL;
	// server/zone/objects/intangible/ControlDevice.idl(63):  		Logger.setLoggingName("ControlDevice");
	Logger::setLoggingName("ControlDevice");
	// server/zone/objects/intangible/ControlDevice.idl(64):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/intangible/ControlDevice.idl(65):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

void ControlDeviceImplementation::updateToDatabaseAllObjects(bool startTask) {
	// server/zone/objects/intangible/ControlDevice.idl(75):  
	if (controlledObject != NULL){
	// server/zone/objects/intangible/ControlDevice.idl(76):  			controlledObject.updateToDatabaseWithoutChildren();
	controlledObject->updateToDatabaseWithoutChildren();
	// server/zone/objects/intangible/ControlDevice.idl(78):  			super.updateToDatabaseAllObjects(startTask);
	IntangibleObjectImplementation::updateToDatabaseAllObjects(startTask);
}

	else {
	// server/zone/objects/intangible/ControlDevice.idl(80):  			super.updateToDatabaseAllObjects(startTask);
	IntangibleObjectImplementation::updateToDatabaseAllObjects(startTask);
}
}

void ControlDeviceImplementation::storeObject(PlayerCreature* player) {
	// server/zone/objects/intangible/ControlDevice.idl(85):  		Logger.error("called storeObject on an abstract method");
	Logger::error("called storeObject on an abstract method");
}

void ControlDeviceImplementation::generateObject(PlayerCreature* player) {
	// server/zone/objects/intangible/ControlDevice.idl(89):  		Logger.error("called generateObject on an abstract method");
	Logger::error("called generateObject on an abstract method");
}

void ControlDeviceImplementation::setControlledObject(CreatureObject* object) {
	// server/zone/objects/intangible/ControlDevice.idl(93):  		controlledObject = object;
	controlledObject = object;
}

CreatureObject* ControlDeviceImplementation::getControlledObject() {
	// server/zone/objects/intangible/ControlDevice.idl(97):  		return controlledObject;
	return controlledObject;
}

bool ControlDeviceImplementation::isControlDevice() {
	// server/zone/objects/intangible/ControlDevice.idl(101):  		return true;
	return true;
}

/*
 *	ControlDeviceAdapter
 */

ControlDeviceAdapter::ControlDeviceAdapter(ControlDeviceImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* ControlDeviceAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		updateToDatabaseAllObjects(inv->getBooleanParameter());
		break;
	case 7:
		storeObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case 8:
		generateObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case 9:
		setControlledObject((CreatureObject*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(getControlledObject()->_getObjectID());
		break;
	case 11:
		resp->insertBoolean(isControlDevice());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ControlDeviceAdapter::updateToDatabaseAllObjects(bool startTask) {
	((ControlDeviceImplementation*) impl)->updateToDatabaseAllObjects(startTask);
}

void ControlDeviceAdapter::storeObject(PlayerCreature* player) {
	((ControlDeviceImplementation*) impl)->storeObject(player);
}

void ControlDeviceAdapter::generateObject(PlayerCreature* player) {
	((ControlDeviceImplementation*) impl)->generateObject(player);
}

void ControlDeviceAdapter::setControlledObject(CreatureObject* object) {
	((ControlDeviceImplementation*) impl)->setControlledObject(object);
}

CreatureObject* ControlDeviceAdapter::getControlledObject() {
	return ((ControlDeviceImplementation*) impl)->getControlledObject();
}

bool ControlDeviceAdapter::isControlDevice() {
	return ((ControlDeviceImplementation*) impl)->isControlDevice();
}

/*
 *	ControlDeviceHelper
 */

ControlDeviceHelper* ControlDeviceHelper::staticInitializer = ControlDeviceHelper::instance();

ControlDeviceHelper::ControlDeviceHelper() {
	className = "ControlDevice";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ControlDeviceHelper::finalizeHelper() {
	ControlDeviceHelper::finalize();
}

DistributedObject* ControlDeviceHelper::instantiateObject() {
	return new ControlDevice(DummyConstructorParameter::instance());
}

DistributedObjectServant* ControlDeviceHelper::instantiateServant() {
	return new ControlDeviceImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ControlDeviceHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ControlDeviceAdapter((ControlDeviceImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

