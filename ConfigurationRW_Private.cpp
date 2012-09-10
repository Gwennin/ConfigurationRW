
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

#include "ConfigurationRW_Private.h"

using namespace ConfigurationNmspc;
using namespace std;

ConfigurationRW::ConfigurationRW() {}

ConfigurationRW::ConfigurationRW(std::string filePath) {
	_filePath = filePath;
	
	_file = new fstream();
	_file->open(_filePath.c_str());
}

multimap<string, string> ConfigurationRW::getValues(string key) {

	_file->clear();
	_file->seekg(ifstream::beg);
	
	multimap<string, string> configuration;
	
	if (_file->is_open() && _file->good()) {
		
		_file->seekg(ifstream::beg);
		
		string line;
		
		while (getline(*_file, line)) {
			
			stringstream trimmer;
			trimmer << line;
			trimmer >> line;
			
			if (line[0] != '#') {
				
				string value;
				trimmer >> value;

				if (line == key)
					configuration.insert(pair<string, string>(line, value));
			}
		}
	}
	
	return configuration;
}

void ConfigurationRW::addValue(string key, string value) {
	
	_file->clear();
	_file->seekg(ifstream::beg);
	
	if (_file->is_open() && _file->good()) {
		_file->seekp(0, ios::end);
		(*_file) << endl << key << " " << value;
		
		_file->close();
		_file->open(_filePath.c_str());
	}
}

void ConfigurationRW::setValue(string key, string value) {
	
	_file->clear();
	_file->seekg(ifstream::beg);
			
	if (_file->is_open() && _file->good()) {

		ofstream tmpFile("tmpFile");
		
		bool setted = false;
	
		string line;
	
		while (getline(*_file, line)) {
		
			stringstream trimmer;
			string trimmedKey;
			trimmer << line;
			trimmer >> trimmedKey;
	
			if ((trimmedKey == key) && !setted) {
				tmpFile << endl << key << " " << value;
				setted = true;	
			}		
			else
				tmpFile << endl << line;
		}
		
		tmpFile.close();
		_file->close();
	
		remove(_filePath.c_str());
		rename("tmpFile", _filePath.c_str());
		
		_file->open(_filePath.c_str());
	}
}

void ConfigurationRW::removeValue(string key, string value) {
	
	_file->clear();
	_file->seekg(ifstream::beg);
	
	if (_file->is_open() && _file->good()) {
		
		ofstream tmpFile("tmpFile");
		bool passed = false;
		
		_file->seekg(ifstream::beg);
	
		string line;
	
		while (getline(*_file, line)) {
		
			stringstream trimmer;
			string trimmedKey;
			string trimmedValue;
			trimmer << line;
			trimmer >> trimmedKey;
			trimmer >> trimmedValue;
	
			if ((trimmedKey == key) && (trimmedValue == value) && !passed)
				passed = true;
			else
				tmpFile << endl << line;
		}
		
		tmpFile.close();
		_file->close();
	
		remove(_filePath.c_str());
		rename("tmpFile", _filePath.c_str());
		
		_file->open(_filePath.c_str());
	}
}

void ConfigurationRW::purgeKey(std::string key) {
	
	_file->clear();
	_file->seekg(ifstream::beg);
	
	if (_file->is_open() && _file->good()) {
	
		ofstream tmpFile("tmpFile");
	
		_file->seekg(ifstream::beg);
	
		string line;
	
		while (getline(*_file, line)) {
		
			stringstream trimmer;
			string trimmedKey;
			trimmer << line;
			trimmer >> trimmedKey;
		
			if (trimmedKey != key)
				tmpFile << endl << line;
		}
	
		tmpFile.close();
		_file->close();
	
		remove(_filePath.c_str());
		rename("tmpFile", _filePath.c_str());
		
		_file->open(_filePath.c_str());
	}
}

ConfigurationRW::~ConfigurationRW() {
	_file->close();
	delete _file;
	_file = 0;
}
