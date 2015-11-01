#include "src/cli_handler.hpp"
#include "src/getWorld.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace std;

int main(){
	cliHandler ch;


    ch.initMainFrame();
    
//    long start = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();    
//
//    uskorenie::worldBoostPoweredJSONparser wtf("data/countriesToCities.json");
//    cout << wtf.showMeCountry("Ukraine") << endl;
//    
//    long end = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
//    
//    cout << end - start << endl;
    return 0;
}


    
