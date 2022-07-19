#include "Object.h"

Object::Object()  : pBridge(nullptr) ,Color(15) {  }

Object::Object(Transform _Info) : TransInfo(_Info), pBridge(nullptr), Color(15) {}

Object::~Object() {  }
