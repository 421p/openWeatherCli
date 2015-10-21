#include <curl/curl.h>
#include <sstream>
#include <string>
#include <iostream>

class simpleCurl{
    CURL *geter;
    CURLcode res;
    
    std::string request_url;
    std::stringstream stream;
    
    static size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
        std::ostringstream *stream = (std::ostringstream*)userdata;
        size_t count = size * nmemb;
        stream->write(ptr, count);
        return count;
    }
    
        public:
    
    void init(const char *request){
        geter = curl_easy_init();
        curl_easy_setopt(geter, CURLOPT_URL, request);
        curl_easy_setopt(geter, CURLOPT_WRITEDATA, &stream);
        curl_easy_setopt(geter, CURLOPT_WRITEFUNCTION, write_data);
        res = curl_easy_perform(geter);
    }
    
    void init(std::string request){
        geter = curl_easy_init();
        curl_easy_setopt(geter, CURLOPT_URL, request.c_str());
        curl_easy_setopt(geter, CURLOPT_WRITEDATA, &stream);
        curl_easy_setopt(geter, CURLOPT_WRITEFUNCTION, write_data);
        res = curl_easy_perform(geter);
    }
    
    void close() { curl_easy_cleanup(geter); stream.str(""); }
    
    simpleCurl(){}
    
    simpleCurl(std::string request){
        init(request);
    }
    
    simpleCurl(const char *request){
        init(request);
    }
    
    virtual ~simpleCurl(){ close(); } 
    
    std::string getResponce(){
        std::string resp = stream.str();
        return resp;
    }
    
};