ConfigurationReader
===================

A little C++ configuration "key value" file reader.

##Configuration File example

	# comment line
	Key Value

A Single Key can have multiple values, but it must define a single value per line :

	Key Value1
	Key Value2

Keys and values ar key sensitive.

##Using

Include the "Configuration.h" file and use it like that :

	ConfigurationNmspc::Configuration conf("SomeConfigFilePath");
	vector<string> items = conf["SomeKey"];		// Get all entries for key "SomeKey"
	
	conf.addValue("SomeKey", "SomeValue");		// Append the entry "SomeValue" with key "SomeKey"
	conf.setValue("SomeKey", "SomeValue");		// Replace the entry who have the first occurence of the key "SomeKey" with the entry "SomeValue"
	conf.removeValue("SomeKey", "SomeValue");	// Remove the entry "SomeValue" with key "SomeKey"
	conf.purgeKey("SomeKey");				// Remove all entries with key "SomeKey"

That's all!
