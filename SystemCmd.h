#ifndef systemcmdH
#define systemcmdH

#include "Cmd.h"

class MSystemCmd: public MCmd
{
private:
	void Echo();
public:
	void InitMap();
};

#endif
