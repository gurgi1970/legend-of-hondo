/*
 *	server/zone/objects/installation/generator/GeneratorObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "GeneratorObject.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	GeneratorObjectStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_SYNCHRONIZEDUILISTEN__SCENEOBJECT_INT_,RPC_SYNCHRONIZEDUISTOPLISTEN__SCENEOBJECT_INT_,RPC_ISGENERATOROBJECT__};

GeneratorObject::GeneratorObject() : InstallationObject(DummyConstructorParameter::instance()) {
	GeneratorObjectImplementation* _implementation = new GeneratorObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

GeneratorObject::GeneratorObject(DummyConstructorParameter* param) : InstallationObject(param) {
}

GeneratorObject::~GeneratorObject() {
}



void GeneratorObject::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	GeneratorObjectImplementation* _implementation = static_cast<GeneratorObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int GeneratorObject::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	GeneratorObjectImplementation* _implementation = static_cast<GeneratorObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void GeneratorObject::synchronizedUIListen(SceneObject* player, int value) {
	GeneratorObjectImplementation* _implementation = static_cast<GeneratorObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SYNCHRONIZEDUILISTEN__SCENEOBJECT_INT_);
		method.addObjectParameter(player);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->synchronizedUIListen(player, value);
}

void GeneratorObject::synchronizedUIStopListen(SceneObject* player, int value) {
	GeneratorObjectImplementation* _implementation = static_cast<GeneratorObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SYNCHRONIZEDUISTOPLISTEN__SCENEOBJECT_INT_);
		method.addObjectParameter(player);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->synchronizedUIStopListen(player, value);
}

bool GeneratorObject::isGeneratorObject() {
	GeneratorObjectImplementation* _implementation = static_cast<GeneratorObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISGENERATOROBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGeneratorObject();
}

DistributedObjectServant* GeneratorObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void GeneratorObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	GeneratorObjectImplementation
 */

GeneratorObjectImplementation::GeneratorObjectImplementation(DummyConstructorParameter* param) : InstallationObjectImplementation(param) {
	_initializeImplementation();
}


GeneratorObjectImplementation::~GeneratorObjectImplementation() {
}


void GeneratorObjectImplementation::finalize() {
}

void GeneratorObjectImplementation::_initializeImplementation() {
	_setClassHelper(GeneratorObjectHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void GeneratorObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<GeneratorObject*>(stub);
	InstallationObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GeneratorObjectImplementation::_getStub() {
	return _this;
}

GeneratorObjectImplementation::operator const GeneratorObject*() {
	return _this;
}

void GeneratorObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void GeneratorObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void GeneratorObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void GeneratorObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void GeneratorObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void GeneratorObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void GeneratorObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void GeneratorObjectImplementation::_serializationHelperMethod() {
	InstallationObjectImplementation::_serializationHelperMethod();

	_setClassName("GeneratorObject");

}

void GeneratorObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(GeneratorObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool GeneratorObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (InstallationObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void GeneratorObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = GeneratorObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int GeneratorObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = InstallationObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint16 _totalSize;

	return _count + 0;
}

GeneratorObjectImplementation::GeneratorObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/installation/generator/GeneratorObject.idl():  		Logger.setLoggingName("GeneratorObject");
	Logger::setLoggingName("GeneratorObject");
}

bool GeneratorObjectImplementation::isGeneratorObject() {
	// server/zone/objects/installation/generator/GeneratorObject.idl():  		return true;
	return true;
}

/*
 *	GeneratorObjectAdapter
 */

GeneratorObjectAdapter::GeneratorObjectAdapter(GeneratorObject* obj) : InstallationObjectAdapter(obj) {
}

Packet* GeneratorObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		break;
	case RPC_SYNCHRONIZEDUILISTEN__SCENEOBJECT_INT_:
		synchronizedUIListen(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getSignedIntParameter());
		break;
	case RPC_SYNCHRONIZEDUISTOPLISTEN__SCENEOBJECT_INT_:
		synchronizedUIStopListen(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getSignedIntParameter());
		break;
	case RPC_ISGENERATOROBJECT__:
		resp->insertBoolean(isGeneratorObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

int GeneratorObjectAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<GeneratorObject*>(stub))->handleObjectMenuSelect(player, selectedID);
}

void GeneratorObjectAdapter::synchronizedUIListen(SceneObject* player, int value) {
	(static_cast<GeneratorObject*>(stub))->synchronizedUIListen(player, value);
}

void GeneratorObjectAdapter::synchronizedUIStopListen(SceneObject* player, int value) {
	(static_cast<GeneratorObject*>(stub))->synchronizedUIStopListen(player, value);
}

bool GeneratorObjectAdapter::isGeneratorObject() {
	return (static_cast<GeneratorObject*>(stub))->isGeneratorObject();
}

/*
 *	GeneratorObjectHelper
 */

GeneratorObjectHelper* GeneratorObjectHelper::staticInitializer = GeneratorObjectHelper::instance();

GeneratorObjectHelper::GeneratorObjectHelper() {
	className = "GeneratorObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void GeneratorObjectHelper::finalizeHelper() {
	GeneratorObjectHelper::finalize();
}

DistributedObject* GeneratorObjectHelper::instantiateObject() {
	return new GeneratorObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* GeneratorObjectHelper::instantiateServant() {
	return new GeneratorObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GeneratorObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GeneratorObjectAdapter(static_cast<GeneratorObject*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

