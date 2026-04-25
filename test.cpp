#include "unicode.hpp" // this library

using std::string;
using std::wstring;

// 很简单的压测
int main(){
    // 尝试用长字符串模拟解析大型文件的过程
    string str = "### 整体地形 - 东部和南部地势较高，分布着平均海拔1000米以上的高原（埃塞俄比亚高原、东非高原、南非高原）和山地，非洲最高峰乞力马扎罗山位于东非高原。";
    for(int i=0; i<1e7; ++i){
        hai::u32_to_u8(hai::u8_to_u32(str));
    }
    return 0;
}


/*
ArchLinux - 计时使用 time "./test.out"
测试点:
    cc: clang++ -O0 -g -std=c++23 -stdlib=libc++
        "./test.out"  33.85s user 0.00s system 99% cpu 33.913 total
    cc: clang++ -O1 -g -std=c++23 -stdlib=libc++
        "./test.out"  3.95s user 0.00s system 99% cpu 3.955 total
    cc: clang++ -O2 -std=c++23 -stdlib=libc++
        "./test.out"  6.34s user 0.00s system 99% cpu 6.350 total
    cc: clang++ -O3 -std=c++23 -stdlib=libc++
        "./test.out"  6.44s user 0.00s system 99% cpu 6.457 total
    cc: clang++ -O0 -g -std=c++23
        "./test.out"  67.51s user 0.00s system 99% cpu 1:07.66 total
    cc: clang++ -O1 -g -std=c++23
        "./test.out"  3.21s user 0.00s system 99% cpu 3.222 total
    cc: clang++ -O2 -std=c++23
        "./test.out"  3.09s user 0.00s system 99% cpu 3.095 total
    cc: clang++ -O3 -std=c++23
        "./test.out"  3.40s user 0.00s system 99% cpu 3.405 total
    cc: g++ -O0 -g -std=c++23
        "./test.out"  75.48s user 0.01s system 99% cpu 1:15.63 total
    cc: g++ -O1 -g -std=c++23
        "./test.out"  5.44s user 0.00s system 99% cpu 5.448 total
    cc: g++ -O2 -g -std=c++23
        "./test.out"  4.64s user 0.00s system 99% cpu 4.645 total
    cc: g++ -O3 -g -std=c++23
        "./test.out"  3.73s user 0.00s system 99% cpu 3.734 total
*/