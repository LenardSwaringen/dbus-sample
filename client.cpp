#include <iostream>
#include <dbus-c++/dbus.h>
#include "dbus_hello_proxy.h"
#include "client.h"

using namespace com::example;
DBus::BusDispatcher dispatcher;
int main()
{
    DBus::default_dispatcher = &dispatcher;                   ///< 设置调度器
    DBus::_init_threading();                                  ///< 初始化线程
    DBus::Connection bus = DBus::Connection::SessionBus();    ///<  连接到系统总线
    new DBus::DefaultTimeout(100, false, &dispatcher);        ///< 设置默认超时

    // 创建DBus代理对象
    HelloProxy proxy(bus, "/com/example", "com.example.hello");
    std::string response = proxy.SayHello("Hello, Adaptor !"); ///< 相当于进入到了adaptor端得进程内执行代码
    std::cout << "response : " << response << std::endl;
    dispatcher.enter();                                        /// 进入事件循环
    return 0;
}