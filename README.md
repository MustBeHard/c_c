#-------------------------
c_c Practice for C
记录C语言和汇编语言的练习
汇编为AT&T Linux版本

-------------------------#


汇编常用的寄存器
ax bx cx dx
di si ip 

ilinux 系统调用号：
0 read
1 write
2 file open
3 file close


文件号：
0 键盘
1 屏幕

中断号：
60 系统退出号



struct 内存会对齐，汇编里也是如此

sort 冒泡排序 选择排序 插入排序 快速排序

file 字符级别的读写，句子，和流

pointer 指针本身存储的是一段内存的首地址，但是指针通常会代表这段内存内存的数据
int * test; //声明一个地址在test,步长为int的指针


function and args
汇编内一般会提供6个寄存器存储函数的参数
所以C语言内参数超过6个，可能需要使用特殊手段，故一般不建议

strings and chars

注意在某些函数内，字符串要手动确定添加结尾符号\0
在汇编内，buff区则不用管理\0,因为通常使用字符串长度管理


