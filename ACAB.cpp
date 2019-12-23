#include "stringconverts.h"
#include <fstream>


using namespace std;

void Compile();
void Run();
void CreateCppFile(string sourceCode , string fileName);
void CheckArguments(int argc, char* argv[]);
ifstream CheckMain(char* argv[]);
string Convert(ifstream& sourceCode);

int main(int argc , char* argv[])
{
	CheckArguments(argc, argv);
	ifstream sourceCode = CheckMain(argv);
	string cpp = Convert(sourceCode);
	//CreateCppFile(cpp , "main.cpp");
	//Compile();
	//Run();
	return 0;
}

void CheckArguments(int argc, char* argv[])
{
	if (argc <= 1)
	{
		cout << "No source code to be compiled." << endl;
		exit(1);
	}
}

ifstream CheckMain(char* argv[])
{
	ifstream sourceCode;
	sourceCode.open(argv[1]);

	if (!sourceCode.is_open())
	{
		cout << "Unable to find file: " << argv[1];
		exit(2);
	}

	return sourceCode;
}

string Convert(ifstream& sourceCode)
{
	string temp;
	string cpp = "#include <iostream>\nusing namespace std;\nint main()\n{\n";

	while (getline(sourceCode, temp))
	{
		if (int pos = temp.find("HEHE") != string::npos)
		{
			cpp += "cout << \"";
			cpp += temp.substr(pos + 4);
			cpp += "\" ;\n";
		}

		if (int pos = temp.find("HEH") != string::npos)
		{
			auto varType = temp.substr(pos + 3, 1);
			
			if (varType == "i")
				cpp += "int ";

			if (varType == "f")
				cpp += "float ";

			if (varType == "d")
				cpp += "double ";

			if (varType == "l")
				cpp += "long ";

			if (varType == "c")
				cpp += "char ";

			auto varName = temp.substr(pos + 3 + 2 );
			cpp += varName + ";\n";
			cpp += "cin >> " + varName + ";\n";
		}
	}
	cpp += "\nreturn 0;\n}";
	cout << cpp;
	return cpp;
}

void Run()
{
	system("cls");
	system("program.exe");
	cout << "\n\nThe end." << endl;
}

void Compile()
{
	system("g++ -o program.exe main.cpp");
}

void CreateCppFile(string sourceCode , string fileName)
{
		ofstream cppFile;
		cppFile.open(fileName);
		cppFile << sourceCode;
		cppFile.close();
}