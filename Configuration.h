
#ifndef ConfigurationReader_Configuration_h
#define ConfigurationReader_Configuration_h

#include <string>
#include <map>
#include <vector>
#include "ConfigurationRW_Private.h"

namespace ConfigurationNmspc {
	
	class Configuration {
		
	private:
		std::string _fileConfigurationPath;
		ConfigurationRW* _configurationContainer;
		
	protected:
		Configuration();
		
	public:
		Configuration(std::string fileConfigurationPath);
		
		std::vector<std::string> operator[] (std::string key);
		
		void setValue(std::string key, std::string value);
		void addValue(std::string key, std::string value);
		void removeValue(std::string key, std::string value);
		void purgeKey(std::string key);
		
	};
}

#endif

