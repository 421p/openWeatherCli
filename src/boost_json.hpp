#ifndef ___SIMPLE_BOOST_JSON_PARSER_INCLUDED___
#define ___SIMPLE_BOOST_JSON_PARSER_INCLUDED___

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <sstream>

namespace uskorenie{

    class simpleBoostPoweredJSONparser{
        boost::property_tree::ptree pt;
        std::stringstream jsonStream;
        
        public:
            simpleBoostPoweredJSONparser(std::string json_str):jsonStream(json_str){boost::property_tree::read_json(jsonStream, pt);}
            simpleBoostPoweredJSONparser(const char* json_str):jsonStream(json_str){boost::property_tree::read_json(jsonStream, pt);}
            simpleBoostPoweredJSONparser(std::ifstream in){boost::property_tree::read_json(in, pt);}
            simpleBoostPoweredJSONparser(std::stringstream in){boost::property_tree::read_json(in, pt);}
		   	virtual ~simpleBoostPoweredJSONparser(){}
            
            double parseDouble(const char*);
            int parseInt(const char*);
            std::string parseString(const char*);
            boost::property_tree::ptree* cheat();
    };


    double simpleBoostPoweredJSONparser::parseDouble(const char *selector){
        return pt.get<double>(selector);
    }
    
    int simpleBoostPoweredJSONparser::parseInt(const char *selector){
        return (int)pt.get<int>(selector);
    }
    
    std::string simpleBoostPoweredJSONparser::parseString(const char *selector){
        return pt.get<std::string>(selector);
    }
    
    boost::property_tree::ptree* simpleBoostPoweredJSONparser::cheat(){
        return &pt;
    }
    
}

#endif
