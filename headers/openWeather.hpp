#ifndef ___OPEN_Weather___
#define ___OPEN_Weather___

#include "simpleCurl.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class openWeather : private simpleCurl{
    std::string city;
    std::string api_key = "dfefcda6e03767b59db85935bcf221f0";
    std::string request_url;
    double temperature;
    double windSpeed;
    double humidity;
    
    void getDataFromJSON(){
        std::stringstream stream(simpleCurl::getResponce());
        try{
            boost::property_tree::ptree pt;
            boost::property_tree::read_json(stream, pt);
            temperature = pt.get<double>("main.temp") - 273.15;
            windSpeed = pt.get<double>("wind.speed");
            humidity = pt.get<double>("main.humidity");
        } catch (...){
            std::cerr << "oshibka\n" << 
            stream.str() << '\n';
        }

    }
    
    public:
    void init(std::string cityName){
            city = cityName;
            request_url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&APPiD=" + api_key;
            simpleCurl::init(request_url);
            getDataFromJSON();
    }

    
        openWeather(std::string cityName):city(cityName){
            init(cityName);
        }
        openWeather(){}
    
    std::string getResponce(){
        std::string resp = simpleCurl::getResponce();
        return resp;
    }
    
    void reinit(std::string cityName){
        city = cityName;
        request_url = "http://api.openweathermap.org/data/2.5/weather?q=" + cityName + "&APPiD=" + api_key;
        simpleCurl::close();
        simpleCurl::init(request_url);
        getDataFromJSON();
    }
    
    double getTemperature(){
        return temperature;
    }
    
    double getWindSpeed(){
        return windSpeed;
    }
    
    double getHumidity(){
        return humidity;
    }
};

#endif