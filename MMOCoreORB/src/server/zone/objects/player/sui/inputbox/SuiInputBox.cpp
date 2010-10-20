/*
 *	server/zone/objects/player/sui/inputbox/SuiInputBox.cpp generated by engine3 IDL compiler 0.61
 */

#include "SuiInputBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	SuiInputBoxStub
 */

SuiInputBox::SuiInputBox(PlayerCreature* player, unsigned int windowType, int inputtype) : SuiBox(DummyConstructorParameter::instance()) {
	SuiInputBoxImplementation* _implementation = new SuiInputBoxImplementation(player, windowType, inputtype);
	_impl = _implementation;
	_impl->_setStub(this);
}

SuiInputBox::SuiInputBox(DummyConstructorParameter* param) : SuiBox(param) {
}

SuiInputBox::~SuiInputBox() {
}


BaseMessage* SuiInputBox::generateMessage() {
	SuiInputBoxImplementation* _implementation = (SuiInputBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return _implementation->generateMessage();
}

void SuiInputBox::setMaxInputSize(int size) {
	SuiInputBoxImplementation* _implementation = (SuiInputBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(size);

		method.executeWithVoidReturn();
	} else
		_implementation->setMaxInputSize(size);
}

void SuiInputBox::setDefaultInput(const String& text) {
	SuiInputBoxImplementation* _implementation = (SuiInputBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(text);

		method.executeWithVoidReturn();
	} else
		_implementation->setDefaultInput(text);
}

bool SuiInputBox::isFilterBox() {
	SuiInputBoxImplementation* _implementation = (SuiInputBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isFilterBox();
}

bool SuiInputBox::isInputBox() {
	SuiInputBoxImplementation* _implementation = (SuiInputBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isInputBox();
}

DistributedObjectServant* SuiInputBox::_getImplementation() {
	return _impl;}

void SuiInputBox::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	SuiInputBoxImplementation
 */

SuiInputBoxImplementation::SuiInputBoxImplementation(DummyConstructorParameter* param) : SuiBoxImplementation(param) {
	_initializeImplementation();
}


SuiInputBoxImplementation::~SuiInputBoxImplementation() {
}


void SuiInputBoxImplementation::finalize() {
}

void SuiInputBoxImplementation::_initializeImplementation() {
	_setClassHelper(SuiInputBoxHelper::instance());

	_serializationHelperMethod();
}

void SuiInputBoxImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SuiInputBox*) stub;
	SuiBoxImplementation::_setStub(stub);
}

DistributedObjectStub* SuiInputBoxImplementation::_getStub() {
	return _this;
}

SuiInputBoxImplementation::operator const SuiInputBox*() {
	return _this;
}

void SuiInputBoxImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SuiInputBoxImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SuiInputBoxImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SuiInputBoxImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SuiInputBoxImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SuiInputBoxImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SuiInputBoxImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SuiInputBoxImplementation::_serializationHelperMethod() {
	SuiBoxImplementation::_serializationHelperMethod();

	_setClassName("SuiInputBox");

	addSerializableVariable("maxInputSize", &maxInputSize);
	addSerializableVariable("defaultInput", &defaultInput);
	addSerializableVariable("inputType", &inputType);
}

SuiInputBoxImplementation::SuiInputBoxImplementation(PlayerCreature* player, unsigned int windowType, int inputtype) : SuiBoxImplementation(player, windowType, SuiBox::INPUTBOX) {
	_initializeImplementation();
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(66):  		maxInputSize = 25;
	maxInputSize = 25;
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(68):  		inputType = inputtype;
	inputType = inputtype;
}

void SuiInputBoxImplementation::setMaxInputSize(int size) {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(74):  		maxInputSize = size;
	maxInputSize = size;
}

void SuiInputBoxImplementation::setDefaultInput(const String& text) {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(78):  		defaultInput = text;
	defaultInput = text;
}

bool SuiInputBoxImplementation::isFilterBox() {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(82):  		return inputType == FILTER;
	return inputType == FILTER;
}

bool SuiInputBoxImplementation::isInputBox() {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(86):  		return true;
	return true;
}

/*
 *	SuiInputBoxAdapter
 */

SuiInputBoxAdapter::SuiInputBoxAdapter(SuiInputBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiInputBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(generateMessage()->_getObjectID());
		break;
	case 7:
		setMaxInputSize(inv->getSignedIntParameter());
		break;
	case 8:
		setDefaultInput(inv->getAsciiParameter(_param0_setDefaultInput__String_));
		break;
	case 9:
		resp->insertBoolean(isFilterBox());
		break;
	case 10:
		resp->insertBoolean(isInputBox());
		break;
	default:
		return NULL;
	}

	return resp;
}

BaseMessage* SuiInputBoxAdapter::generateMessage() {
	return ((SuiInputBoxImplementation*) impl)->generateMessage();
}

void SuiInputBoxAdapter::setMaxInputSize(int size) {
	((SuiInputBoxImplementation*) impl)->setMaxInputSize(size);
}

void SuiInputBoxAdapter::setDefaultInput(const String& text) {
	((SuiInputBoxImplementation*) impl)->setDefaultInput(text);
}

bool SuiInputBoxAdapter::isFilterBox() {
	return ((SuiInputBoxImplementation*) impl)->isFilterBox();
}

bool SuiInputBoxAdapter::isInputBox() {
	return ((SuiInputBoxImplementation*) impl)->isInputBox();
}

/*
 *	SuiInputBoxHelper
 */

SuiInputBoxHelper* SuiInputBoxHelper::staticInitializer = SuiInputBoxHelper::instance();

SuiInputBoxHelper::SuiInputBoxHelper() {
	className = "SuiInputBox";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SuiInputBoxHelper::finalizeHelper() {
	SuiInputBoxHelper::finalize();
}

DistributedObject* SuiInputBoxHelper::instantiateObject() {
	return new SuiInputBox(DummyConstructorParameter::instance());
}

DistributedObjectServant* SuiInputBoxHelper::instantiateServant() {
	return new SuiInputBoxImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiInputBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiInputBoxAdapter((SuiInputBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

