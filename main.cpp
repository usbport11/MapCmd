#include <math.h>
#include "SystemCmd.h"

int main(int argc, char** argv)
{
	MSystemCmd SystemCmd;
	SystemCmd.InitMap();
	SystemCmd.BufferAddCmd("echo hello world!");
	SystemCmd.BufferExecute();
	SystemCmd.Close();
	
	return 0;
}