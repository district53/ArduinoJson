// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "JsonVariant.hpp"

namespace ARDUINOJSON_NAMESPACE {

class JsonKey {
 public:
  JsonKey(Slot* slot) : _slot(slot) {}

  operator const char*() const {
    return c_str();
  }

  const char* c_str() const {
    return _slot ? _slot->key : 0;
  }

  bool isNull() const {
    return _slot == 0 || _slot->key == 0;
  }

  bool isStatic() const {
    return _slot ? _slot->value.keyIsStatic : true;
  }

  friend bool operator==(JsonKey lhs, const char* rhs) {
    if (lhs.isNull()) return rhs == 0;
    return rhs ? !strcmp(lhs, rhs) : false;
  }

 private:
  Slot* _slot;
};

// A key value pair for JsonObjectData.
class JsonPair {
 public:
  JsonPair(MemoryPool* memoryPool, Slot* slot) : _key(slot) {
    if (slot) {
      _value = JsonVariant(memoryPool, &slot->value);
    }
  }

  JsonKey key() const {
    return _key;
  }

  JsonVariant value() const {
    return _value;
  }

 private:
  JsonKey _key;
  JsonVariant _value;
};
}  // namespace ARDUINOJSON_NAMESPACE
