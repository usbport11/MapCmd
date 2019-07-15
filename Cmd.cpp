#include "Cmd.h"

void MCmd::ParseString(const char* s)
{
	const char* text;
	std::string buffer;
	
	if(!s) return;
	
	text = s;
	//fill Argv vector
	while(1)
	{
		buffer.clear();
		while(1)
		{
			// skip whitespace
			while(*text && *text <= ' ')
				text++;
			if(!*text) return;
			// skip // comments
			if(text[0] == '/' && text[1] == '/') return;
			// skip /* */ comments
			if(text[0] == '/' && text[1] =='*')
			{
				while (*text && (text[0] != '*' || text[1] != '/'))
					text++;
				if (!*text) return;
				text += 2;
			} 
			else break;
		}
		//handle quoted strings
		if(*text == '"')
		{
			text ++;
			while ( *text && *text != '"' )
				buffer += *(text++);
			Argv.push_back(buffer);
			if(!*text) return;
			continue;
		}
		//regular
		while(*text > ' ')
		{
			if( text[0] == '"' ) break;
			if( text[0] == '/' && text[1] == '/' ) break;
			// skip /* */ comments
			if( text[0] == '/' && text[1] =='*' ) break;
			buffer += *text++;
		}
		Argv.push_back(buffer);
		if(!*text) return;
	}
}

void MCmd::ExecuteString(const char* s)
{
	std::map<std::string, tMCmdFunc>::iterator it;
	//parse
	ParseString(s);
	//execute
	it = Map.find(Argv[0]);
	if(it != Map.end()) ((*this).*(Map[Argv[0]]))();
	Argv.clear();
}

void MCmd::MapAddFunc(std::string Cmd, tMCmdFunc CmdFunc)
{
	if(!CmdFunc) return;
	Map.insert(std::pair<std::string, tMCmdFunc>(Cmd, CmdFunc));
}

void MCmd::BufferAddCmd(const char* s)
{
	Buffer.push_back(s);
}

void MCmd::BufferExecute()
{
	for(int i=0; i<Buffer.size(); i++)
		ExecuteString(Buffer[i]);
	Buffer.clear();
}

void MCmd::Close()
{
	Map.clear();
	Argv.clear();
	Buffer.clear();
}

