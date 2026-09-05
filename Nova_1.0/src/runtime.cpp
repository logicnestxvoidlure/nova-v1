#include "nova/core.hpp"
#include <sstream>
namespace nova{
std::string value_to_string(const Value&v){if(std::holds_alternative<Null>(v))return"null";if(auto p=std::get_if<bool>(&v))return*p?"true":"false";if(auto p=std::get_if<double>(&v)){std::ostringstream o;o<<*p;return o.str();}if(auto p=std::get_if<std::string>(&v))return*p;if(std::holds_alternative<std::shared_ptr<std::vector<Value>>>(v))return"[array]";if(std::holds_alternative<std::shared_ptr<std::unordered_map<std::string,Value>>>(v))return"{map}";if(std::holds_alternative<std::shared_ptr<Function>>(v))return"<function>";return"<object>";}
bool is_truthy(const Value&v){if(std::holds_alternative<Null>(v))return false;if(auto p=std::get_if<bool>(&v))return*p;if(auto p=std::get_if<double>(&v))return*p!=0;if(auto p=std::get_if<std::string>(&v))return!p->empty();return true;}
double as_number(const Value&v){if(auto p=std::get_if<double>(&v))return*p;throw RuntimeError("Expected number");}
}
