
#ifndef ConfigurartionReader_ConfigurationReader_h
#define ConfigurartionReader_ConfigurationReader_h

#include <fstream>
#include <map>

namespace ConfigurationNmspc {
	
	class ConfigurationRW {
		
	private:
		std::fstream* _file;
		std::string _filePath;
		std::multimap<std::string, std::string> _configuration;
		
	protected:
		ConfigurationRW();
		
	public:
		ConfigurationRW(std::string filePath);
		
		std::multimap<std::string, std::string> getValues(std::string key);
		
		void setValue(std::string key, std::string value);
		void addValue(std::string key, std::string value);
		void removeValue(std::string key, std::string value);
		
		void purgeKey(std::string key);
		
		~ConfigurationRW();
	};
}

#endif

