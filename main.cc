#include "src/cli_handler.hpp"
#include "src/getWorld.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	cliHandler ch;
	
	argc<2?ch.initMainFrame():ch.initArgumentsHandler(argv);
    
    return 0;
}


    
