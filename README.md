# Unicode for modern C++

## A lightweight efficient library that provides:

- **Conversion**
    - UTF-32 to UTF-8 stream
    - UTF-8 stream to UTF-32
- **Unicode character visual width calculate**

## header-only and module support

You are developing a TUI text editor.  
And you found that Unicode characters like `你` and `😁` are not only one point, it's 1~4 bytes.  
Simply processing raw **UTF-8 byte streams** can lead to **truncate** and **garbled text**.  
To solve this, we need to convert **UTF-8 byte stream** into a **UTF-32 code point array** and store it, just for calculate; When output, conversion **UTF-32 array** back into **UTF-8 byte stream**.  
You can't find a exist *C++ Unicode library* that is lightweight and easy to use, so you made this yourself.  
**But more tricky**, some characters are full width like `中` `の` `😁`, some are half width, and you may also encounter something like `اللغة العربية`, oh... you don't know how to identify and separate them, that felt extremely difficult...  


## **So maybe you are looking for *haiyyyyh/unicode***

### Usage

recommend using module :

- compiling

```sh
make
```

- using

```cpp
import unicode;
// or use header file
#include "unicode.hpp"
```

#### **example**

```cpp
#include <print>

import unicode;

using std::string;
using std::u32string;

int main(){
    // raw UTF-8 string
    string str = (const char*)u8"😁hello world测试龎赑𥸈𦜍🌏";
    // easily conversion to UTF-32
    u32string u32str = hai::to_u32(str);
    // conversion back and print
    std::print("{}\n", hai::to_u8(u32str));
    // code point and visual width
    for(auto &ch : u32str){
        std::print("[U+{:04X}]{} ", (int)ch, hai::width(ch));
    }
    // calculate visual width of a string
    std::print("\n{}", hai::width(hai::to_u32("اللغة العربية")));
    // nothing more 乁(ツ)厂
    return 0;
}
```

#### **have a test in ./test.cpp**

```sh
make test
```

#### Output (in VSCode and kitty terminal)
```
😁hello world测试龎赑𥸈𦜍🌏
[U+1F601]2 [U+0068]1 [U+0065]1 [U+006C]1 [U+006C]1 [U+006F]1 [U+0020]1 [U+0077]1 [U+006F]1 [U+0072]1 [U+006C]1 [U+0064]1 [U+6D4B]2 [U+8BD5]2 [U+9F8E]2 [U+8D51]2 [U+25E08]2 [U+2670D]2 [U+1F30F]2 
13
```


### Local set

See line 177 in file unicode.cppm or line 282 in unicode.hpp, set variable `width_of_non_overlapping_ranges` to 2(default) or 1


### Learn more, see [reference.txt](./reference.txt)