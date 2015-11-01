#include "openWeather.hpp"
#include "list.hpp"

class openWeatherList : public myList{
    
    public:
        void showTemperatureList(){
            for(struct{
                    openWeather *ow; 
                    myNode *temp;
                } ts = { new openWeather , (myNode*)*((long long*)this) };
                (&ts)->temp; //((myNode*)*((long long*)&ts+1))->temp; 
                (&ts)->ow->init((&ts)->temp->value),
                (&ts)->ow->tellMe(),
                (&ts)->temp=(&ts)->temp->next);
        }
};