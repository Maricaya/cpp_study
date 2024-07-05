gcc 编译4步骤：
1. 预处理 -E xxx.i 预处理文件
    gcc -E hello.c -o hello.i
   1. 头文件展开。不检查语法错误，可以展开任意文件
   2. 宏定义替换。将宏名替换为宏值
   3. 替换注释。替换为空行
   4. 展开条件编译。根据条件来展开指令
2. 编译 -S xxx.s  汇编文件
    gcc -S hello.i -o hello.s
   1. 逐行检查语法错误。【重点】整个编译4步骤中最耗时的过程。
   2. 将c语言翻译城汇编指令，得到 .s 汇编文件。
3. 汇编 -c xxx.o 目标文件
    gcc -c hello.s -o hello.o 
    objdump -d hello.o
   1. 翻译，将汇编指令翻译城对应的二进制编码
   2. 

4. 链接 无 xxx.exe 可执行文件
    gcc hello.o -o hello
   1. 数据段合并
   2. 数据地址回填
   3. 库引入