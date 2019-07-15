#ifndef cmdH
#define cmdH

#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class MCmd;

typedef void(MCmd::*tMCmdFunc)();

class MCmd
{
protected:
	std::map<std::string, tMCmdFunc> Map;//global cmd map
	std::vector<std::string> Argv;//current command attributes
	std::vector<const char*> Buffer;//all command strings add here
	void ParseString(const char* s);
	void MapAddFunc(std::string Cmd, tMCmdFunc CmdFunc);
public:
	void BufferAddCmd(const char* s);
	void BufferExecute();
	void ExecuteString(const char* s);
	void Close();
};

#endif
