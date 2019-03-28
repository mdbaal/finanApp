#include "summary.h"

Summary::Summary(){

}

Summary::~Summary(){

}

void Summary::add(std::string s,float f) {
	float _f = f;
	if (values.count(s) == 1) {
		_f += values.at(s);
	}
	values.insert_or_assign(s, _f);
}
void Summary::remove(std::string s) {
	values.erase(s);
}

float Summary::getValue(std::string s) {
	try {
		return values.at(s);
	}
	catch (std::exception e) {
		return 0;
	}
}