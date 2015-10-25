#include "openWeather.hpp"
#include "list.hpp"

class openWeatherList : public MY::List{
    
    public:
        void showTemperatureList(){
            for(struct{
                    openWeather *ow; 
                    MY::Node *temp;
                } ts = { new openWeather , (MY::Node*)*((long long*)this) };
                (&ts)->temp; //(Node*)*((long long*)&ts+1); 
                (&ts)->ow->reinit((&ts)->temp->value),
                (&ts)->ow->tellMe(),
                (&ts)->temp=(&ts)->temp->next);
        }
};