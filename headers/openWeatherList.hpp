#include "openWeather.hpp"
#include "list.hpp"

class openWeatherList : public MY::List{
    
    public:
        void showTemperatureList(){
            for(struct{
                    openWeather *ow; 
                    Node *temp;
                } ts = { new openWeather , (Node*)*((long long*)this) };
                (&ts)->temp; //(Node*)*((long long*)&ts+1); 
                (&ts)->ow->reinit((&ts)->temp->value),
                std::cout << (&ts)->temp->value << ": " << (&ts)->ow->getTemperature() << 
                " C. Wind speed is " << (&ts)->ow->getWindSpeed() << " m/s. Humidity: " <<
                (&ts)->ow->getHumidity() << "%\n",
                (&ts)->temp=(&ts)->temp->next);
        }
};