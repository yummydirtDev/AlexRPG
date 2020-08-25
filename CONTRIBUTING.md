# Contributing

To contribute to AlexRPG, make a fork, make your changes and make a descriptive pull request.

## Style

Use camelCase

When writing blocks, put the brace on the same line as the statement for example do:

```
if (code == "working") {
    do stuff;
}
```

Instead of:

```
if (code == "working")
{
    do stuff;
}
```

Use 4 spaces for indentation, and don't indent the case statement in switch statements. Example:

```
switch (code) {
case "working":
    do stuff;
    break;
}
```

Prefer brace initialization, and put spaces in between the braces and the initialization value. Example:

```
std::string code{ "working" };
```

Remember to use descriptive variable and function names and leave comments! Example:

```
std::string makeCodeWork() {
    std::string code {"working"};
    return code;\
}
```
