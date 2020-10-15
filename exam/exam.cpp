#include "http_server.h"
#include <boost/program_options.hpp>
#include <iostream>

namespace theboost = boost::program_options;

int main(int argc, char** argv)
{
    theboost::options_description desc("Available options");
    desc.add_options()
        ("ip,h", theboost::value<std::string>(), "address to listen on")
        ("port,p", theboost::value<std::string>(), "port number")
        ("directory,d", theboost::value<std::string>(), "root directory of server");

    theboost::variables_map vm;
    theboost::store(theboost::parse_command_line(argc, argv, desc), vm);
    theboost::notify(vm);
    
    if (!vm.count("ip") || !vm.count("directory") || !vm.count("port")) {
        std::cerr << "Missed arguments\n" << desc << "\n";
        return 1;
    }

    const auto ip = vm["ip"].as<std::string>();
    const auto port = vm["port"].as<std::string>();
    const auto directory = vm["directory"].as<std::string>();
    const unsigned fluxnumber = 5;

    HttpServer server{ ip, port, directory, fluxnumber };
    server.run();
}
