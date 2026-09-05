#pragma once
#include <string>
#include <vector>
namespace nova {
enum class TokenType{Identifier,Number,String,Let,Const,Fn,If,Else,While,For,In,Return,Break,Continue,Class,This,Try,Catch,Finally,Throw,Import,True,False,Null,Plus,Minus,Star,Slash,Percent,Equal,EqualEqual,Bang,BangEqual,Less,LessEqual,Greater,GreaterEqual,And,Or,LeftParen,RightParen,LeftBrace,RightBrace,LeftBracket,RightBracket,Comma,Dot,Colon,Newline,End};
struct Token{TokenType type;std::string text;int line;int column;};
class Lexer{std::string source;size_t pos=0;int line=1,column=1;void advance();char peek()const;char peek_next()const;public:explicit Lexer(std::string);std::vector<Token> scan();};
std::string token_name(TokenType);
}
