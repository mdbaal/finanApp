#ifndef INPUT_H
#define INPUT_H

#include "commands.h"
#include <string>
#include <iostream>

class Input{
public:
	Input();
	virtual ~Input();
	
	std::string readline();
private:
	

};

#endif //INPUT_H