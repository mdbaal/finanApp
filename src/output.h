#ifndef OUTPUT_H
#define OUTPUT_H

#include "summary.h"
#include <iostream>
#include <string>
#include <termcolor/termcolor.hpp>

class Output{
public:
	Output();
	virtual ~Output();

	 enum termColor {
		grey, //0
		red, //1
		green, //2
		yellow, //3
		blue, //4
		magenta, //5
		cyan, //6
		white //7
	};


	void drawSummary(Summary* s);
	void message(std::string msg) { std::cout << std::endl << msg << std::endl; }
	void message(std::string msg, termColor c);
	void printHelp();

private:

};

#endif //OUTPUT_H