#ifndef ___MY_CONFOIGURATOR_FOR_THAT___
#define ___MY_CONFOIGURATOR_FOR_THAT___

#include "boost_json.hpp"
#include <string>
#include <fstream>

class configurator : private uskorenie::simpleBoostPoweredJSONparser{
	public:
		configurator(std::string configDirectory):simpleBoostPoweredJSONparser(std::ifstream(configDirectory)){}
		configurator(const char *configDirectory):simpleBoostPoweredJSONparser(std::ifstream(configDirectory)){}
        
        std::string getValue(std::string selector){
            return simpleBoostPoweredJSONparser::parseString(selector.c_str());
        }
        
        std::string getValue(const char* selector){
            return simpleBoostPoweredJSONparser::parseString(selector);
        }
        
        void showValue(std::string selector){
            std::cout << simpleBoostPoweredJSONparser::parseString(selector.c_str()) << '\n';
        }
        
        void showValue(const char* selector){
            std::cout << simpleBoostPoweredJSONparser::parseString(selector) << '\n';
        }
};

#endif

