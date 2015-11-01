#ifndef ___RX_JSON_INCLUDED___
#define ___RX_JSON_INCLUDED___

#include <iostream>
#include <regex>
#include <string>

namespace rxjson{

class openWeatherJSONregexParserReturnableData{
public:
    std::string sky;
    std::string humidity;
    std::string temp;
    std::string wind;
};

class openWeatherJSONregexParser{
    std::regex skyPattern;
    std::regex humidityPattern;
    std::regex tempPattern;
    std::regex windPattern;
    std::string jsonData;        
    std::smatch resultate;
    openWeatherJSONregexParserReturnableData data;
public:
    openWeatherJSONregexParser(std::string str):skyPattern("\"description\":\"([A-z\\s]+)\""), humidityPattern("\"humidity\":(\\d*[.]?\\d+)"),
    tempPattern("\"temp\":(\\d*[.]?\\d+)"), windPattern("\"speed\":(\\d*[.]?\\d+)"), jsonData(str){}
    openWeatherJSONregexParser(const char* str):skyPattern("\"description\":\"([A-z\\s]+)\""), humidityPattern("\"humidity\":(\\d*[.]?\\d+)"),
    tempPattern("\"temp\":(\\d*[.]?\\d+)"), windPattern("\"speed\":(\\d*[.]?\\d+)"), jsonData(str){}
    
    openWeatherJSONregexParserReturnableData parse(){            
            if(regex_search(jsonData, resultate, skyPattern))
                data.sky = resultate.str(1);
            if(regex_search(jsonData, resultate, humidityPattern))
                data.humidity = resultate.str(1);
            if(regex_search(jsonData, resultate, windPattern))
                data.wind = resultate.str(1);
            if(regex_search(jsonData, resultate, tempPattern))
                data.temp = resultate.str(1);
                
                return data;
        }
        
    };    
    
}

#endif