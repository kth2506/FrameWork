#include "Object.h"

Object::Object()  : pBridge(nullptr) , Hp(0){  }

Object::Object(Transform _Info) : TransInfo(_Info), pBridge(nullptr) {}

Object::~Object() {  }
