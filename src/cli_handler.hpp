#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include "openWeatherList.hpp"
#include "openWeather.hpp"
#include "configurator.hpp"

using namespace std;

enum string_code {
    EXIT,
    UNKNOWN,
    COMPARE,
    CHECK,
    HELP,
    LIST
};

class cliHandler{
    std::string buffer;
    openWeather *ow;
    configurator conf;
    
    std::string helpContent = conf.getValue("cliHandler.helpContent");
    
        string_code hashIt(std::string const& inString);
        std::vector<std::string> explode(std::string const & s, char delim);
        
        public:
        void compare(std::string city_1, std::string city_2);
        void check (std::string city);
        void citylist(std::string dir);
        void initMainFrame();
        cliHandler():ow(new openWeather), conf("config/settings.json"){}
        ~cliHandler(){delete ow;}

    
};

std::vector<std::string> cliHandler::explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); result.push_back(std::move(token)));

    return result;
}


string_code cliHandler::hashIt(std::string const& inString) {
    if (inString == "exit" || inString == "EXIT" || inString == "quit" || inString == "QUIT") return EXIT;
    if (inString == "check" || inString == "CHECK") return CHECK;
    if (inString == "compare" || inString == "COMPARE") return COMPARE;
    if (inString == "help" || inString == "HELP") return HELP;
    if (inString == "list" || inString == "LIST") return LIST;
    
    return UNKNOWN;
}

void cliHandler::citylist(std::string dir){
    ifstream ifs(dir);
    openWeatherList *ls = new openWeatherList;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    for(char* buff = new char[64];ifs >> buff;ls->add(buff));
    ls->showTemperatureList();
}
    
void cliHandler::check(std::string city){
    ow->init(city); 
    ow->tellMe(); 
}
    
void cliHandler::compare(std::string city_1, std::string city_2){
    
    ow->init(city_1);
    ow->tellMe();
    struct{ std::string name; double temperature, windSpeed, humidity; } firstCity = { city_1, ow->getTemperature(), ow->getWindSpeed(), ow->getHumidity()};
    ow->init(city_2); 
    ow->tellMe();
    struct{ std::string name; double temperature, windSpeed, humidity; } secondCity = { city_2, ow->getTemperature(), ow->getWindSpeed(), ow->getHumidity()};

    std::cout << std::endl;
    
    if(firstCity.temperature > secondCity.temperature) 
        std:: cout << "Temperature in " << firstCity.name << " higher than in " <<
        secondCity.name << " by " << firstCity.temperature - secondCity.temperature << " degrees. ";
    else
        std:: cout << "Temperature in " << secondCity.name << " higher than in " <<
        firstCity.name << " by " << secondCity.temperature - firstCity.temperature << " degrees. ";
        if(firstCity.windSpeed > secondCity.windSpeed) 
        std:: cout << "Wind speed in " << firstCity.name << " higher than in " <<
        secondCity.name << " by " << firstCity.windSpeed - secondCity.windSpeed << " m/s. ";
    else
        std:: cout << "Wind speed in " << secondCity.name << " higher than in " <<
        firstCity.name << " by " << secondCity.windSpeed - firstCity.windSpeed << " m/s. ";
        
    if(firstCity.humidity > secondCity.humidity) 
        std:: cout << "Humidity in " << firstCity.name << " higher than in " <<
        secondCity.name << " by " << firstCity.humidity - secondCity.humidity << "%. ";
    else
        std:: cout << "Humidity in " << secondCity.name << " higher than in " <<
        firstCity.name << " by " << secondCity.humidity - firstCity.humidity << "%. ";
}

void cliHandler::initMainFrame(){
    
        
    conf.showValue("cliHandler.welcomeMessage");
    
    while(true){
        cout << "\n> "; getline(cin, buffer);
        auto vc = explode(buffer, ' ');
        switch(hashIt(vc[0])){
            case EXIT : cout << "bye!\n";return;
            break;
            case UNKNOWN : cout << "unknown command.";
            break;
            case CHECK : check(vc[1]);
            break;
            case COMPARE : compare(vc[1], vc[2]);
            break;
            case LIST: citylist(vc[1]);
            break;
            case HELP : cout << helpContent;
            break;
        }
    }
}
