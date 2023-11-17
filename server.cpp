#include "server.h"

using namespace com::example;

std::string HelloAdaptor::SayHello(const std::string& greeting)
{
    std::cout << "received: " << greeting << std::endl;
    std::string response = "Hello, Proxy !";
    std::cout << "response: " << response << std::endl;
    return response;
}


DBus::BusDispatcher dispatcher;
int main()
{
    DBus::default_dispatcher = &dispatcher;                   ///< 设置dispatcher
    DBus::_init_threading();                                  ///< 初始化线程
    DBus::Connection conn  = DBus::Connection::SessionBus();  ///< 创建连接
    conn.request_name("com.example.hello");                   ///< 注册服务
    HelloAdaptor adaptor(conn);                               ///< 创建adaptor对象
    dispatcher.enter();                                       ///< 进入事件循环
    return 0;
}