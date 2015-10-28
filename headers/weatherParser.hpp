#include <string>
#include <sstream>
#include "boost_json.hpp"

namespace uskorenie{

    struct weatherBoostPoweredJSONparserReturnableObject{
        double temperature;
        double humidity;
        double windSpeed;
        std::string sky;
    };
    
    class weatherBoostPoweredJSONparser : simpleBoostPoweredJSONparser{
        double temperature;
        double humidity;
        double windSpeed;
        std::string sky;
        std::string jsonString;
        
        public:
            weatherBoostPoweredJSONparser(const char *json_str):simpleBoostPoweredJSONparser(json_str){}
            weatherBoostPoweredJSONparser(std::string json_str):simpleBoostPoweredJSONparser(json_str){}
            weatherBoostPoweredJSONparserReturnableObject parse(){
                return {
                    simpleBoostPoweredJSONparser::parseDouble("main.temp") - 273.15,
                    simpleBoostPoweredJSONparser::parseDouble("main.humidity"),
                    simpleBoostPoweredJSONparser::parseDouble("wind.speed"),
                    [this]() -> std::string{
                        std::string localSky;
                        for(boost::property_tree::ptree::value_type & child : //we can use simpleBoostPoweredJSONparser::cheat()
                        ((boost::property_tree::ptree*)((long long)&*this + 8ll))->get_child("weather")){
                            localSky = child.second.get<std::string>("description"); 
                        }
                        return localSky;
                    }()
                };
            }
    };
}
    
   
