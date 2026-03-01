#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iterator>

// #include <fstream>
// #include <algorithm>
#include <variant>


// separate classes for lexer, file handling, preprocessor
// TODO: parse out the empty lines and comments

#if 0
class Interpreter {
public:
	Interpreter();
};
#endif

#if 0
class Token {
public:
	std::string type;
	std::variant<std::string, double, int> value;
	unsigned line;
	unsigned column;

	Token(std::string type, const std::string& val, unsigned line, unsigned column) :
		type(type), value(val), line(line), column(column)
	{};

	Token(std::string type, double val, unsigned line, unsigned column) :
		type(type), value(val), line(line), column(column)
	{};

	Token(std::string type, int val, unsigned line, unsigned column) :
		type(type), value(val), line(line), column(column)
	{};


};
#endif

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
	//std::vector<std::string> tokenize(const std::string line);
	std::vector<std::string> tokenize(const std::string line);
};

//	10 LET D = 10

//std::vector<std::string>
std::vector<std::string>
Lexer::tokenize(const std::string line)
{
	// tok_regex = '|'.join('(?P<%s>%s)' % pair for pair in self.token_spec)
	// ("number_literal",  r'\d+(\.\d*)?'),    # int or float
	// const std::regex re(R"(\d+(\.\d*)?))");

	const std::regex expr_number{R"(\d+(\.\d*)?)"};
	const std::regex expr_d{R"([\s|,]+)"};
	const std::regex expr_D{R"((?P<NUMBER>\d+)(?P<STRING>\w+)"};

	std::vector<std::string> tokenized;

	//std::sregex_token_iterator it{line.begin(),line.end(), expr_number};
	//std::sregex_token_iterator end;
	std::cmatch match;
	std::regex_match(line, match, expr_D);


	for (; it != end; ++it)
	{
		std::cout << "M >> " << *it << std::endl;
		tokenized.push_back(*it);
	}
	

// 	for (std::sregex_iterator it = line_begin; it != line_end; ++it)
//	{
//		std::smatch match = *it;
//		// -- std::string match_str = match.str()
//		tokenized.push_back(match.str());
//	}

	// Additional check to remove empty strings
	//tokenized.erase( 
		//std::remove_if(tokenized.begin(), tokenized.end(), line.empty()), tokenized.end());

	return tokenized;
}
#if 0
{
	std::vector<Token> tokenized;
	std::basic_stringstream<char> sstream{line};

	int i;
	double d;
	std::string s;

	if (sstream >> i)
	{
		tokenized.push_back(Token{"NUMBER", i, 0, 0});
	} else if (sstream >> d) {
		tokenized.push_back(Token{"DOUBLE", d, 0, 0});
	} else if (sstream >> s) {
		tokenized.push_back(Token{"STRING", s, 0, 0});
	} 

	return tokenized;
}
#endif

int main()
{
	std::string line;
	Lexer lexer;

	std::cout << "<<: ";
	//while (std::getline(std::cin, line))
	//{
	line =
	"10 GOTO \n"
	"30 INSERT \n"
	"50 30 20 \n"
	;
		std::vector<std::string> o = lexer.tokenize(line);

		for (auto token : o)
        		std::cout << ": " << token << std::endl;

		std::cout << "<<: ";
	//}
		
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
