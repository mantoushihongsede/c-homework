# c-homework
程序目的：模拟计算机内存分配

基本思路：
1、模拟分页存储管理方式
2、用一个大小为1024的数组来模拟内存，每一个数组元素代表一页
3、

数据结构：
1、一个大小为1024的int数组，每一个整型数组元素都存储了一个0~1023的整数
2、页表：一个vecter<int>容器，存储物理块号
2、进程表：一个单向链表，将已分配的进程按优先级排列
3、进程页表：自定义的类的对象。每个进程创建时生成，并按优先级插入进程表。包括进程名、进程页表始址、页表长度
4、空闲块表：一个循环队列，将空闲的页排列起来

基本功能：
1、为进程分配内存：输入进程名和所需内存大小，输出分配结果，包括是否分配成功，和分配的进程编号（三位二进制串）
2、释放已分配内存：默认释放已分配内存表的第一个进程。若输入进程编号，则释放该进程所占页
2、查询已有进程：程序将已有进程信息打印在控制台中
3、地址转换：请求输入逻辑地址，输出物理地址）


