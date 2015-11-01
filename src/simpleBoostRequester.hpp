#ifndef ___SIMPLE_BOOST_REQUEST_INCLUDED___
#define ___SIMPLE_BOOST_REQUEST_INCLUDED___

#include <boost/asio.hpp>
#include <sstream>
#include <string>

using namespace boost::asio;

namespace uskorenie{

    class simpleRequest{
        
         boost::system::error_code ec;
         io_service svc;
        
         std::string request;
         std::string response;
         ip::address host;
        
        public:
        
        void sendRequest(){
            response = "";
            ip::tcp::socket sock(svc);
            sock.connect({ host, 80 });
            sock.send(buffer(request));
    
            do {
                char buf[1024];
                std::size_t bytes_transferred = sock.receive(buffer(buf), {}, ec);
                if (!ec) 
                response.append(buf, buf + bytes_transferred);
            } while (!ec);
    
        }
        
        std::string sendRequest(std::string h, std::string request){
            response = "";
            this->host = ip::address::from_string(h);
            this->request = request;
            ip::tcp::socket sock(svc);
            sock.connect({ host, 80 });
            sock.send(buffer(request));
    
            do {
                char buf[1024];
                std::size_t bytes_transferred = sock.receive(buffer(buf), {}, ec);
                if (!ec) 
                response.append(buf, buf + bytes_transferred);
            } while (!ec);
            
            return response;
    
        }
        
        simpleRequest():host(ip::address::from_string("162.243.58.21")){}
        simpleRequest(std::string host, std::string request):host(ip::address::from_string(host)), request(request){}
        simpleRequest(const char* host, const char* request):host(ip::address::from_string(host)), request(request){}
        
        virtual ~simpleRequest(){} 
        
        std::string getResponse(){
            return std::string(response);
        }
        
    };
    
}

#endif
