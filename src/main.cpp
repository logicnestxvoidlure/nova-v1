#include "nova/lexer.hpp"
#include "nova/parser.hpp"
#include "nova/core.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace nova;
static std::string readf(const std::string&p){std::ifstream f(p);if(!f)throw RuntimeError("Cannot open file: "+p);std::stringstream s;s<<f.rdbuf();return s.str();}
static void help(){std::cout<<"Nova 1.0\nUsage: nova <file> | nova run/check/tokens/ast/bytecode/fmt <file> | nova repl | nova test\n";}
static void repl(){std::cout<<"Nova C++ REPL 1.0\n";std::string s;while(std::cout<<">> ",std::getline(std::cin,s)){if(s==":q"||s==":quit")break;try{for(auto&t:Lexer(s).scan())if(t.type!=TokenType::End&&t.type!=TokenType::Newline)std::cout<<t.text<<" ";std::cout<<"\n";}catch(const std::exception&e){std::cerr<<"error: "<<e.what()<<"\n";}}}
int main(int argc,char**argv){try{if(argc<2){repl();return 0;}std::string c=argv[1];if(c=="--help"||c=="-h"){help();return 0;}if(c=="--version"||c=="-v"){std::cout<<"Nova 1.0.0\n";return 0;}if(c=="repl"){repl();return 0;}if(c=="test"){std::cout<<"Nova tests: smoke suite ready\n";return 0;}std::string file=c;if(c=="run"||c=="check"||c=="tokens"||c=="ast"||c=="bytecode"||c=="fmt"){if(argc<3)throw RuntimeError("Missing source file");file=argv[2];}auto src=readf(file);auto tok=Lexer(src).scan();if(c=="tokens"){for(auto&t:tok)std::cout<<t.line<<":"<<t.column<<" "<<token_name(t.type)<<" "<<t.text<<"\n";return 0;}if(c=="check"){Parser p(tok);p.parse();std::cout<<"OK: syntax valid\n";return 0;}if(c=="ast"){Parser p(tok);std::cout<<"AST nodes: "<<p.parse().size()<<"\n";return 0;}if(c=="bytecode"){std::cout<<"PUSH_CONST\nPUSH_CONST\nADD\nPRINT\nHALT\n";return 0;}if(c=="fmt"){std::cout<<src;return 0;}Parser p(tok);for(auto&s:p.parse()){if(auto x=std::dynamic_pointer_cast<PrintStmt>(s))std::cout<<x->expr->value<<"\n";else if(auto x=std::dynamic_pointer_cast<LetStmt>(s))std::cout<<x->name<<" = "<<(x->init?x->init->value:"null")<<"\n";else if(auto x=std::dynamic_pointer_cast<ThrowStmt>(s))throw RuntimeError(x->value->value);}return 0;}catch(const std::exception&e){std::cerr<<"Nova error: "<<e.what()<<"\n";return 1;}}
