#ifndef ___OPEN_Weather___
#define ___OPEN_Weather___

#include "simpleBoostRequester.hpp"
#include "weatherParser.hpp"
#include <string>
#include <exception>

#include <boost/foreach.hpp>

class openWeather : private uskorenie::simpleRequest{
    std::string city;
    std::string api_key = "dfefcda6e03767b59db85935bcf221f0";
    std::string request_host = "162.243.58.21";
    std::string request_url;
    double temperature;
    double windSpeed;
    double humidity;
    std::string sky;
    
    std::string removeHeader(std::string json){
                size_t found = json.find_first_of("{");
                json.erase(json.begin(), json.begin() + found);
                return std::string(json);
    }
    
    void getDataFromJSON(std::string in_str){
        //std::stringstream stream();
        try{
            // boost::property_tree::ptree pt;
            // boost::property_tree::read_json(stream, pt);
            
            // temperature = pt.get<double>("main.temp") - 273.15;
            // windSpeed = pt.get<double>("wind.speed");
            // humidity = pt.get<double>("main.humidity");
            
            // for(auto child : pt.get_child("weather")){
            //     sky = child.second.get<std::string>("description"); 
            // }
            
            uskorenie::weatherBoostPoweredJSONparser parser(removeHeader(in_str));
            
            auto data = parser.parse();
            
            temperature = data.temperature;
            windSpeed = data.windSpeed;
            humidity = data.humidity;
            sky = data.sky;
            
        } catch (std::exception &e){
            std::cerr << e.what() << '\n';
            //stream.str() << '\n';
        }

    }
    
    public:
    void init(std::string cityName){
            city = cityName;
            request_url = "GET /data/2.5/weather?q=" + city + "&APPiD=" + api_key + " HTTP/1.0\r\n\r\n";
            
            getDataFromJSON(simpleRequest::sendRequest(request_host, request_url));
    }

    
        openWeather(std::string cityName):city(cityName){
            init(cityName);
        }
        openWeather(){}
    
    std::string getResponse(){
        return std::string(simpleRequest::getResponse());
    }
    
    void tellMe(){
       std::cout << city << ": " << sky << ", temperature is " << temperature <<
                " C. Wind speed is " << windSpeed << " m/s. Humidity: " <<
                humidity << "%.\n";
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