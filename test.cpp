#include "unicode.hpp"

using std::string;
using std::u32string;

// 很简单的压测
int main(){
    // 尝试用长字符串模拟解析大型文件的过程
    string str = (const char *)u8"### 整体地形 - 东部和南部地势较高，分布着平均海拔1000米以上的高原（埃塞俄比亚高原、东非高原、南非高原）和山地，非洲最高峰乞力马扎罗山位于东非高原。";
    for(int i=0; i<1e7; ++i){
        hai::to_u8(hai::to_u32(str));
    }
    return 0;
}


/*
ArchLinux - 计时使用 time "./test.out"
测试点:
    cc: clang++ -O0 -stdlib=libc++
        54.27s user 0.00s system 99% cpu 54.376 total
    cc: clang++ -O1 -stdlib=libc++
        4.11s user 0.00s system 99% cpu 4.117 total
    cc: clang++ -O2 -stdlib=libc++
        6.64s user 0.00s system 99% cpu 6.655 total
    cc: clang++ -O3 -stdlib=libc++
        6.46s user 0.00s system 99% cpu 6.475 total
    cc: clang++ -O0
        66.75s user 0.00s system 99% cpu 1:06.86 total
    cc: clang++ -O1
        3.58s user 0.00s system 99% cpu 3.590 total
    cc: clang++ -O2
        3.21s user 0.00s system 99% cpu 3.217 total
    cc: clang++ -O3
        3.35s user 0.00s system 99% cpu 3.352 total
    cc: g++ -O0
        78.57s user 0.01s system 99% cpu 1:18.77 total
    cc: g++ -O1
        5.54s user 0.00s system 99% cpu 5.552 total
    cc: g++ -O2
        4.81s user 0.00s system 99% cpu 4.814 total
    cc: g++ -O3
        3.87s user 0.00s system 99% cpu 3.873 total
*/