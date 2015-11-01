#include "boost_json.hpp"
#include <string>


namespace uskorenie{
    
    using boost::property_tree::ptree;

    class worldBoostPoweredJSONparser : private simpleBoostPoweredJSONparser{
    public:
            worldBoostPoweredJSONparser(std::stringstream &ss):simpleBoostPoweredJSONparser(ss){}
            worldBoostPoweredJSONparser(std::string dir):simpleBoostPoweredJSONparser([&dir]()->std::ifstream&{std::ifstream *ret = new std::ifstream(dir); return *ret;}()){}
            worldBoostPoweredJSONparser(const char *dir):simpleBoostPoweredJSONparser([&dir]()->std::ifstream&{std::ifstream *ret = new std::ifstream(dir); return *ret;}()){}
                        
        void doThisAmazingThingCarefully(){
            auto world = simpleBoostPoweredJSONparser::cheat();
            
            for(auto country : *world){
                std::cout << country.first << ": \n";
                for(auto city : country.second){
                    std::cout << "__" << city.second.data() << "\n";
                }
            }
        }
        
        int showMeCountry(std::string strana){
            auto world = simpleBoostPoweredJSONparser::cheat();
            int cnt = 0;
            
            for(auto country : *world){
                if(country.first == strana){
                    for(auto city : country.second){
                        std::cout << "__" << city.second.data() << "\n";
                        cnt++;
                    }
                }
            }
            return cnt;
        }
        
        };
        
    }
