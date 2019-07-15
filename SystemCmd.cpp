#include "SystemCmd.h"

void MSystemCmd::Echo()
{
	for(int i=1; i<Argv.size(); i++)
	{
		std::cout<<Argv[i]<<" ";
	}
	std::cout<<std::endl;
}

void MSystemCmd::InitMap()
{
	MapAddFunc("echo", (tMCmdFunc)&MSystemCmd::Echo);
}
