## Solution

There are 3 steps (shit implementation)

- Scan the string to list of token
```cpp
std::string s = "(Apple -> Banana) -> Grape";
// to
std::vector tok = {"(Apple ", " Banana) ", " Grape"};
```

- Clearing each token from space or something except `L_PAREN` and `R_PAREN`

- Concatenating to expected value by checking if the token have `L_PAREN`

```cpp
std::vector tok = {"(Apple ", " Banana) ", " Grape"};
// to
std::vector ret = {"(Apple -> Banana)", "Grape"};
```
