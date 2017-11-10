# Arithmetic Interpreter
This is a simple interpreter to calculate arithmetic expression referenced from [Ruslan's Blog](https://ruslanspivak.com).

## Build
* ```$ make main```

## Need to know
* This interpreter can execute mathematical expressions like '34+7-5+3' or '2 * 52 / 8', etc.
* The numbers must be positive integers.
* The supported operations are addition, subtraction, multiplication, division
* The operations are executed from left to right, i.e. the interpreter doesn't give priority to multiplications, etc.

## Examples
```
cal>> 2 + 5 - 2 /5
1

cal>> 2 - 53 * 2
-102

cal>> 10+3-44*2
-62
```
