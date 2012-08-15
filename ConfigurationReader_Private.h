
#ifndef ConfigurartionReader_ConfigurationReader_h
#define ConfigurartionReader_ConfigurationReader_h

#include <fstream>
#include <map>

namespace ConfigurationNmspc {
	
	class ConfigurationReader {
		
	private:
		std::ifstream* _file;
		std::string _filePath;
		std::multimap<std::string, std::string> _configuration;
		
	protected:
		ConfigurationReader();
		
		void readConfigurationFile();
		
	public:
		ConfigurationReader(std::string filePath);
		
		std::multimap<std::string, std::string> getConfiguration();
		
		~ConfigurationReader();
	};
}

#endif
