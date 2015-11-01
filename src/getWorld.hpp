#include "boost_json.hpp"
#include <string>


namespace uskorenie{
    
    using boost::property_tree::ptree;

    class worldBoostPoweredJSONparser : private simpleBoostPoweredJSONparser{
    public:
            worldBoostPoweredJSONparser(std::stringstream ss):simpleBoostPoweredJSONparser(std::stringstream(ss.str())){}
            worldBoostPoweredJSONparser(std::string dir):simpleBoostPoweredJSONparser(std::ifstream(dir)){}
            worldBoostPoweredJSONparser(const char *dir):simpleBoostPoweredJSONparser(std::ifstream(dir)){}
                        
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
