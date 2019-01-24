#include "output.h"

Output::Output(){

}

Output::~Output(){


}

void Output::drawSummary(Summary* s) {
	std::map<std::string, float> _map = s->getMap();
	for (std::map<std::string,float>::iterator it = _map.begin(); it != _map.end(); ++it) {
		std::cout << it->first << " - " << it->second << std::endl;
	}

}