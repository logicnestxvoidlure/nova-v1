#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <variant>
#include <memory>
#include <functional>
#include <stdexcept>

namespace nova {
struct Null {};
struct Function;
struct Object;
using Value=std::variant<Null,bool,double,std::string,
    std::shared_ptr<std::vector<Value>>,
    std::shared_ptr<std::unordered_map<std::string,Value>>,
    std::shared_ptr<Function>,std::shared_ptr<Object>>;
std::string value_to_string(const Value&);
bool is_truthy(const Value&);
double as_number(const Value&);
struct RuntimeError:std::runtime_error{using std::runtime_error::runtime_error;};
struct Function{
    std::vector<std::string> params;
    std::function<Value(const std::vector<Value>&)> native;
};
struct Object{std::unordered_map<std::string,Value> fields;std::shared_ptr<Object> parent;};
}
