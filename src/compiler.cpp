#include "nova/core.hpp"
#include <vector>
namespace nova{enum class OpCode{PushConstant,Add,Sub,Mul,Div,Print,Halt};struct Bytecode{std::vector<OpCode>code;std::vector<Value>constants;};Bytecode compile_demo(){return{{OpCode::PushConstant,OpCode::PushConstant,OpCode::Add,OpCode::Print,OpCode::Halt},{2.0,3.0}};}}
