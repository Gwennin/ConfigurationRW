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

	ConfigurationNmspc::Configuration conf("YourConfigFilePath");
	vector<string> items = conf["YourWantedKey"];

That's all!
