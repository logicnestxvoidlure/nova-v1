#pragma once
#include "nova/lexer.hpp"
#include <memory>
#include <string>
#include <vector>
namespace nova {
struct Expr{virtual~Expr()=default;};struct Stmt{virtual~Stmt()=default;};
using ExprPtr=std::shared_ptr<Expr>;using StmtPtr=std::shared_ptr<Stmt>;
struct LiteralExpr:Expr{std::string value;explicit LiteralExpr(std::string v):value(std::move(v)){}};
struct PrintStmt:Stmt{ExprPtr expr;explicit PrintStmt(ExprPtr e):expr(e){}};
struct LetStmt:Stmt{std::string name;ExprPtr init;bool constant=false;};
struct ThrowStmt:Stmt{ExprPtr value;explicit ThrowStmt(ExprPtr v):value(v){}};
class Parser{std::vector<Token> tokens;size_t current=0;public:explicit Parser(std::vector<Token>);std::vector<StmtPtr> parse();};
}
