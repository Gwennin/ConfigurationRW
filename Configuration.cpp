
#include <iostream>

#include "ConfigurationReader_Private.h"

#include "Configuration.h"

using namespace ConfigurationNmspc;
using namespace std;

Configuration::Configuration() {}

Configuration::Configuration(string fileConfigurationPath) {
	
	_fileConfigurationPath = fileConfigurationPath;
	
	ConfigurationReader reader(_fileConfigurationPath);
	
	_configurationContainer = reader.getConfiguration();
}

vector<string> Configuration::operator[] (string key) {
	
	vector<string> result;
	
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> value;
	value = _configurationContainer.equal_range(key);
	
	for (multimap<string, string>::iterator it = value.first; it != value.second; it++) {
		result.push_back(it->second);
	}
	
	return result;
}
