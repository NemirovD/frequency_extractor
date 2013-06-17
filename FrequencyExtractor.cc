#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tchar.h>

//do we want to keep time data?sure

typedef struct _Data{
	_Data::_Data();
	_Data::_Data(double time, double value);
	double time;
	double value;
} Data;

_Data::_Data(){
	this->time = NULL;
	this->value = NULL;
}

_Data::_Data(double time, double value){
	this->time = time;
	this->value = value;
}


//first step create a vector of vectors that stores the data
std::vector<std::vector<Data>> getData(TCHAR * filename){

	std::ifstream fin;
	std::string line;
	Data tData;
	float tTime, tValue;
	std::vector<Data> tVector;
	std::vector<std::vector<Data>> toReturn;
	
	fin.open(filename);
	
	if(!fin.is_open()){
		std::cout<< "could not open file" << std::endl;
		std::cout << filename << std::endl;
		return std::vector<std::vector<Data>>();
	}

	while(fin.good()){
		std::getline(fin,line);
		if(line.compare("END")==0){
			toReturn.push_back(tVector);
			tVector = std::vector<Data>();
		}else{
			sscanf(line.c_str(), "%f %f", &tTime, &tValue);
			tData = Data(tTime, tValue);
			tVector.push_back(tData);
		}
	}

	return toReturn;
}

double getAverage(std::vector<Data> data){
	double avg = 0;
	
	for(int i = 0; i < data.size(); ++i){
		avg+= data[i].value;
	}
	avg/=data.size();
	
	return avg;
}

double getVariance(std::vector<Data> data){
	double avg = getAverage(data);
	double var = 0;
	
	for(int i = 0; i < data.size(); ++i){
		var+= (data[i].value - avg)*(data[i].value - avg);
	}
	
	var/=data.size();
	
	return var;
}

double getFreq(std::vector<Data> data){
	
	int cycles=0;

	for(int i = 1; i < data.size(); ++i){
		if(data[i].value < 1 && data[i-1].value > 1){
			cycles++;
		}
	}
	
	return cycles/data[data.size()-1].time;
}

int main(int argc, TCHAR * args[]){

	std::vector<std::vector<Data>> data;
	data = getData(args[1]);
	double max = 0;
	
	for(int i = 0; i < data.size(); ++i){
		max = std::max<double>(max,getVariance(data[i])); 
	}
	
	for(int i = 0; i < data.size(); ++i){
		if(getVariance(data[i]) == max){
		
			std::cout << "Frequency of the blinking light is "
				<< getFreq(data[i]) << "hz" <<std::endl;
		}
	}

	return 0;
}