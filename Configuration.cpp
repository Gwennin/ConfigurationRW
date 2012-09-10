
#include <iostream>
#include <sstream>

#include "Configuration.h"

using namespace ConfigurationNmspc;
using namespace std;

Configuration::Configuration() {}

Configuration::Configuration(string fileConfigurationPath) {
	
	_fileConfigurationPath = fileConfigurationPath;
	_configurationContainer =  new ConfigurationRW(_fileConfigurationPath);
}

vector<string> Configuration::operator[] (string key) {
	
	vector<string> result;
	
	multimap<string, string> value;
	value = _configurationContainer->getValues(key);
	
	multimap<string, string>::const_iterator it = value.begin();

	for ( ; it != value.end(); it++) {
		result.push_back(it->second);
	}
	
	return result;
}

void Configuration::setValue(string key, string value) {
	stringstream trimmer;
	trimmer << key;
	trimmer >> key;
	
	trimmer.flush();
	trimmer << value;
	trimmer >> value;
	
	if ((key != "") && (value != ""))
		_configurationContainer->setValue(key, value);
}

void Configuration::addValue(string key, string value) {
	stringstream trimmer;
	trimmer << key;
	trimmer >> key;
	
	trimmer.flush();
	trimmer << value;
	trimmer >> value;
	
	if ((key != "") && (value != ""))
		_configurationContainer->addValue(key, value);
}

void Configuration::removeValue(string key, string value) {
	stringstream trimmer;
	trimmer << key;
	trimmer >> key;
	
	trimmer.flush();
	trimmer << value;
	trimmer >> value;
	
	if ((key != "") && (value != ""))
		_configurationContainer->removeValue(key, value);
}

void Configuration::purgeKey(string key) {
	stringstream trimmer;
	trimmer << key;
	trimmer >> key;

	if (key != "")
		_configurationContainer->purgeKey(key);
}

