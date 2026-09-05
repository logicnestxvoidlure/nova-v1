# Nova 1.0

Native C++ foundation for the Nova language.

Features planned/started in this version:
- Native C++ runtime
- Lexer and parser
- AST
- Bytecode/VM foundation
- Variables and constants
- Functions and recursion foundation
- Arrays and maps foundation
- Classes and inheritance foundation
- Exceptions
- Modules
- String interpolation
- Math/string/file/JSON standard-library foundation
- REPL
- Syntax checking
- Token and AST inspection
- Bytecode inspection
- Formatter command
- Test command foundation
- Optimization-ready architecture

## Build

```bash
cmake -S . -B build
cmake --build build --config Release
```

Run:
```bash
build/nova examples/hello.nova
```

Windows:
```powershell
build\Release\nova.exe examples\hello.nova
```

## Commands

```text
nova <file.nova>
nova run <file.nova>
nova check <file.nova>
nova tokens <file.nova>
nova ast <file.nova>
nova bytecode <file.nova>
nova fmt <file.nova>
nova test
nova repl
nova --version
nova --help
```

## Example

```nova
say "Hello, Nova!"

let x = 10
const name = "Nova"

if x > 5 {
    say "big"
}

for i in range(10) {
    say i
}

fn add(a, b) {
    return a + b
}

say add(20, 22)
```

## Goal

Nova 1.0 is a native-runtime development branch. The goal is to turn Nova into a fast, stable language and eventually define Nova 1.0 as the first stable language specification.

Future work includes a complete bytecode compiler, garbage collector, package manager, native extension API, optimizer, concurrency, richer standard library and optional JIT research.
