#include <iostream>
#include <boost/program_options.hpp>
#include "http_server.h"

namespace theboost = boost::program_options;

int main(int argc, char *argv[])
{  
	theboost::options_description opt_desc("Available options");
	desc.add_options()
	("address,h", theboost::value<std::string>(), "address")
	("port,p", theboost::value<std::string>(), "port")
    	("directory,d", theboost::value<std::string>(), "directory");
	theboost::variables_map varm;
   	theboost::store(theboost::parse_command_line(argc, argv, opt_desc), varm);
    	theboost::notify(varm);
	const auto directory = varm["directory"].as<std::string>();
    	const auto address = varm["address"].as<std::string>();
    	const auto port = varm["port"].as<std::string>();
	const unsigned fluxnum = 5; 
    	HttpServer server{ directory, address, port, fluxnum };
    	server.run();
}
