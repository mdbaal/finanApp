#include "summary.h"

Summary::Summary(){

}

Summary::~Summary(){

}

void Summary::add(std::string s,float f) {
	values.insert_or_assign(s, f);
}
void Summary::remove(std::string s) {
	values.erase(s);
}