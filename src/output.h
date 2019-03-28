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
		grey,
		red,
		green,
		yellow,
		blue,
		magenta,
		cyan,
		white
	};


	void drawSummary(Summary* s);
	void message(std::string msg) { std::cout << std::endl << msg << std::endl; }
	void message(std::string msg, int c);
	void printHelp();

private:

};

#endif //OUTPUT_H