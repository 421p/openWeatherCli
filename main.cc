#include "headers/openWeatherList.hpp"
#include "headers/openWeather.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); result.push_back(std::move(token)));

    return result;
}

enum string_code {
    EXIT,
    UNKNOWN,
    COMPARE,
    CHECK,
    HELP,
    LIST
};

string_code hashIt(std::string const& inString) {
    if (inString == "exit" || inString == "EXIT" || inString == "quit" || inString == "QUIT") return EXIT;
    if (inString == "check" || inString == "CHECK") return CHECK;
    if (inString == "compare" || inString == "COMPARE") return COMPARE;
    if (inString == "help" || inString == "HELP") return HELP;
    if (inString == "list" || inString == "LIST") return LIST;
    
    return UNKNOWN;
}

int main()
{
    std::string buffer;
    openWeather *ow = new openWeather;
    
    std::string helpContent = "\ncheck %cityname% - for check city.\ncompare %cityname_1% %cityname_2% - for compare 2 cities.\n";
    
    auto citylist = [](std::string dir) -> void{

        ifstream ifs(dir);
        openWeatherList *ls = new openWeatherList;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        for(char* buff = new char[64];ifs >> buff;ls->add(buff));
        ls->showTemperatureList();
    };
    
    auto check = [&ow](std::string city) -> void {
        ow->reinit(city); 
        ow->tellMe(); 
    };
    
    auto compare = [&ow](std::string city_1, std::string city_2) -> void{
        
        ow->reinit(city_1);
        ow->tellMe();
        struct{ std::string name; double temperature, windSpeed, humidity; } firstCity = { city_1, ow->getTemperature(), ow->getWindSpeed(), ow->getHumidity()};
        ow->reinit(city_2); 
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
        
    };
    
    cout << "\nWelcome to the openWeather cli v0.01a.\nType \"help\" for help.\n";
    
    while(true){
        cout << "\n> "; getline(cin, buffer);
        auto vc = explode(buffer, ' ');
        switch(hashIt(vc[0])){
            case EXIT : cout << "bye!\n";return 0;
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
    