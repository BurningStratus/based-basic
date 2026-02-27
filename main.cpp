#include <iostream>
#include <fstream>
#include <string>
#include <variant>
#include <regex>


// separate classes for lexer, file handling, preprocessor
// TODO: parse out the empty lines and comments

class Interpreter {
public:
	Interpreter();
};

class Token {
protected:
	std::variant<int, double, std::string> value;
	std::string type;
	unsigned line;
	unsigned column;

public:
	Token(std::string type, const std::string& val, unsigned line, unsigned column) :
		type(type), value(value), line(line), column(column) {};
	Token(std::string type, double val, unsigned line, unsigned column) :
		type(type), value(value), line(line), column(column) {};
	Token(std::string type, int val, unsigned line, unsigned column) :
		type(type), value(value), line(line), column(column) {};
};

class Lexer {
public:
	std::string code;
	std::string line;
	// keywords
	// char_pos
	// line
	// column
	// token_spec = [ () ]
	//tokens()
	std::vector<Token> tokenize(const std::string line);
};

//	10 LET D = 10
Lexer::tokenize(const std::string line)
{
	std::string code; // TODO: was a property of a class

}

int main()
{
	std::string line ;
	std::ifstream file("sample.cfg");
	if (file.is_open())
	{
		while (std::getline(file, line))
			std::cout << line << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Unable to open the file! " << std::endl;
	}

	return 0;
}

// courier's stash

// implement these as a main class
// def parse_program(self):
// def parse_expression(self):
// def operator_expression(self):
// def parse_builtin_dictionary(self):
// def collapse_call_stack(self):
// def print_builtin(self, *args, **kwargs):
// def show_builtin(self, *args, **kwargs):
// def repeat_builtin(self, *args, **kwargs):
// def make_variable_builtin(self, *args, **kwargs):
// def sum_builtin(self, *args):
// def sum_expressions_builtin(self):
// def run(self):
// def main():

// keywords:
// BASE, DATA, DEF, DIM, END, FOR, GO, GOSUB, GOTO, IF, INPUT, LET, NEXT,
// ON, OPTION, PRINT, RANDOMIZE, READ, REM, RESTORE, RETURN, STEP, STOP,
// SUB, THEN, TO

//        self.token_spec = [
//            ("argv_begin",      r'\('),     # start of argument vector
//            ("argv_end",        r'\)'),     # end of args vector
//            ("list",            r'[\[\]]'),     # end of the list
//            # all strings are changed to string_literal later
//            ("string_literal_terminated",       r'\"(.*?)"(?!\w+)'),
//            ("string_literal_unterminated",     r'\"\w+(?=\s)'),
//            ("number_literal",  r'\d+(\.\d*)?'),    # int or float
//            #("list_begin",      r'\['),     # start of the list
//            #("list_end",        r'\]'),     # end of the list
//            ("operator",        r'[\+\-\*/%]'), # operator
//            ("variable",        r':\w+'),   # variable
//            ("identifier",      r'\w+'),    # names of procedures
//            ("eol",             r'\n'),
//        ]
