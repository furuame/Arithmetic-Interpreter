# Arithmetic Interpreter
This is a simple interpreter to calculate arithmetic expression referenced from [Ruslan's Blog](https://ruslanspivak.com).

## Build
* ```$ make main```

## Need to know
* This interpreter can execute mathematical expressions like '34+7-5+3' or '2 * 52 / 8', etc.
* The supported operations are addition (+), subtraction (-), multiplication (*), division (/), power (^)
* The operations are executed from left to right, i.e. the interpreter doesn't give priority to multiplications, etc.
* Support Precedence and Parentheses.

## Limits
* Number in the interpreter is handled with integer, so error exists when expression has float-point operation.

## Examples
```
cal>> 2 + 5 - 2 /5
1

cal>> 2 - 53 * 2
-102

cal>> 10+3-44*2
-62

cal>> 2 ^ 5 - 1
31

cal>> 2 + - - 1
3
```
