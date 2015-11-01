all: gcc

gcc:
	g++ -std=c++11 main.cc -o openWeatherCli -lboost_system
	
project:	
	clang++ -std=c++11 main.cc -o openWeathercli -lboost_system
run:
	./openWeatherCl
