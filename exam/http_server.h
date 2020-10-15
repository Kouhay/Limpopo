#include "thread_safe_socket_queue.h"
#include <string>
#include <thread>
#include <vector>

class HttpServer {
public:
    HttpServer(const std::string& ip, const std::string& port, const std::string& directory, unsigned fluxnumber);~HttpServer();

    void __attribute__((noreturn)) run();

private:
    void __attribute__((noreturn)) handle_clients();

    std::vector<std::thread> workers{};
    ThreadSafeSocketQueue socketQueue{};
    std::string m_address;
    std::string m_port;
};
