
#ifndef ConfigurationReader_Configuration_h
#define ConfigurationReader_Configuration_h

#include <string>
#include <map>
#include <vector>

namespace ConfigurationNmspc {
	
	class Configuration {
		
	private:
		std::string _fileConfigurationPath;
		std::multimap<std::string, std::string> _configurationContainer;
		
	protected:
		Configuration();
		
	public:
		Configuration(std::string fileConfigurationPath);
		
		std::vector<std::string> operator[] (std::string key);
	};
}

#endif
