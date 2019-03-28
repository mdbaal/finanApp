#ifndef SUMMARY_H
#define SUMMARY_H

#include <string>
#include <map>

class Summary{
public:
	Summary();
	virtual ~Summary();

	std::string name;
	void add(std::string s,float f);
	void remove(std::string s);
	std::map<std::string,float> getMap() { return values; }
	float getValue(std::string s);
private:
	std::map<std::string, float> values = std::map<std::string, float>();

};

#endif //SUMMARY_H