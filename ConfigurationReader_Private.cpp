
#include <iostream>
#include <sstream>
#include <string>

#include "ConfigurationReader_Private.h"

using namespace ConfigurationNmspc;
using namespace std;

ConfigurationReader::ConfigurationReader() {}

ConfigurationReader::ConfigurationReader(std::string filePath) {
	
	_filePath = filePath;
	
	_file = new ifstream();
	_file->open(_filePath.c_str());
	
	readConfigurationFile();
}

void ConfigurationReader::readConfigurationFile() {
	
	if (_file->is_open() && _file->good()) {
		
		_file->seekg(ifstream::beg);
		
		string line;
		
		while (getline(*_file, line)) {
			
			stringstream trimmer;
			trimmer << line;
			trimmer >> line;
			
			if (line[0] != '#') {
				
				string value;
				
				while (trimmer >> value) {
					_configuration.insert(pair<string, string>(line, value));
				}
			}
		}
	}
}

std::multimap<std::string, std::string> ConfigurationReader::getConfiguration() {
	return _configuration;
}

ConfigurationReader::~ConfigurationReader() {

	_file->close();
	_file = 0;
}
