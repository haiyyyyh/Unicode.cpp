# Unicode for modern C++

## A lightweght header-only library that provides:

- **Conversion**
    - UTF-32 to UTF-8 stream
    - UTF-8 stream to UTF-32
- **Unicode character visual width calculate**


You are developing a TUI text editor.  
And you found that Unicode characters like `你` and `😁` are not only one point, it's 1~4 bytes.  
Simply processing raw **UTF-8 byte streams** can lead to **truncate** and **garbled text**.  
To solve this, we need to convert **UTF-8 byte stream** into a **UTF-32 code point array** and store it, just for calculate; When output, conversion **UTF-32 array** back into **UTF-8 byte stream**.  
You can't find a exist *C++ Unicode library* that is lightweight and easy to use, so you made this yourself.
**But more tricky**, some characters are full width like `中` `の` and **emoji**, while others are half width, but you don't know how to identify and separate them, that felt extremely difficult...  


## **So maybe you are looking for *haiyyyyh/unicode***

### Usage

```cpp
#include <print>
#include "hai/unicode.hpp" // this library

using std::string;
using std::wstring;

int main(){
    string str = "😁hello world测试龎赑𥸈𦜍🌏";  // raw string
    wstring wstr = hai::u8_to_u32(str);       // conversion easily
    std::print("\"{}\" with length {}\n", str, str.length());
    std::print("{}\n", hai::u32_to_u8(wstr)); // conversion back and out put
    for(auto &ch : wstr){
        std::print("[U+{:04X}]{} ", (int)ch, hai::width(ch)); // code point and visual width
    }
    std::print("\n{}", hai::str_width(wstr)); // calculate visual width of a string
    // nothing more 乁(ツ)厂
    return 0;
}
```


#### Output (in VSCode and kitty terminal)
```
"😁hello world测试龎赑𥸈𦜍🌏" with length 39
😁hello world测试龎赑𥸈𦜍🌏
[U+1F601]2 [U+0068]1 [U+0065]1 [U+006C]1 [U+006C]1 [U+006F]1 [U+0020]1 [U+0077]1 [U+006F]1 [U+0072]1 [U+006C]1 [U+0064]1 [U+6D4B]2 [U+8BD5]2 [U+9F8E]2 [U+8D51]2 [U+25E08]2 [U+2670D]2 [U+1F30F]2 
27
```


### Local set

See line 290 of source, set variable `width_of_non_overlapping_ranges` to 2(default) or 1