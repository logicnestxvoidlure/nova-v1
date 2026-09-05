#include "nova/core.hpp"
#include <iostream>
namespace nova{
enum class Op{Constant,Add,Sub,Mul,Div,Print,Halt};
struct Instruction{Op op;Value value{Null{}};};
class VM{public:void run(const std::vector<Instruction>&code){std::vector<Value>s;for(auto&i:code){switch(i.op){case Op::Constant:s.push_back(i.value);break;case Op::Add:{auto b=as_number(s.back());s.pop_back();auto a=as_number(s.back());s.pop_back();s.push_back(a+b);break;}case Op::Sub:{auto b=as_number(s.back());s.pop_back();auto a=as_number(s.back());s.pop_back();s.push_back(a-b);break;}case Op::Mul:{auto b=as_number(s.back());s.pop_back();auto a=as_number(s.back());s.pop_back();s.push_back(a*b);break;}case Op::Div:{auto b=as_number(s.back());s.pop_back();auto a=as_number(s.back());s.pop_back();if(b==0)throw RuntimeError("division by zero");s.push_back(a/b);break;}case Op::Print:std::cout<<value_to_string(s.back())<<'\n';s.pop_back();break;case Op::Halt:return;}}}};
}
