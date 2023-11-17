#pragma once
#include <dbus-c++/dbus.h>
#include "dbus_hello_proxy.h"

using namespace com::example;

class HelloProxy : public hello_proxy,
                            public DBus::IntrospectableProxy,
                            public DBus::ObjectProxy
{
public:
    HelloProxy(DBus::Connection &connection, const char *adaptor_path, const char *adaptor_name)
                      : DBus::ObjectProxy(connection, adaptor_path, adaptor_name){}
    ~HelloProxy() = default;
};

