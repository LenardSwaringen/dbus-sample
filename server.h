#pragma once
#include <dbus-c++/dbus.h>
#include <iostream>
#include "dbus_hello_adaptor.h"

using namespace com::example;
class HelloAdaptor
        : public hello_adaptor,
          public DBus::IntrospectableAdaptor,
          public DBus::ObjectAdaptor
{
public:
    explicit HelloAdaptor(DBus::Connection &connection): DBus::ObjectAdaptor(connection, "/com/example") {}
    ~HelloAdaptor() = default;

public:
    std::string SayHello(const std::string& greeting) override;
};
