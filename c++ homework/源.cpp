#include<iostream>
#include<string>
#include<vector>
#include"Process_List_item.h"
#include"Free_Blocks.h"
#include"Memory.h"

int memory_size = 16;					//模拟的内存的大小（单位是物理块的个数）
int blocks_size = 16;					//物理块的大小（单位是char）

int main(void)
{
	Memory memory;											//创建模拟内存的数据结构
	memory.Initialization_Memory(memory_size, blocks_size);
	Free_Blocks free_table(memory_size);					//创建模拟空闲块表的数据结构
	std::vector<int> page_table;							//创建模拟页表的数据结构
	char operate;
	int flag = 0;												//标志变量，标志是否有一创建但未删除的进程
	std::cout << "What do you what to do?" << std::endl
		<< "Create new process : Please input \"C / c\"" << std::endl
		<< "Query existing processes : Please input \"Q / q\"" << std::endl
		<< "Terminate the program : Please input \"T / t\"" << std::endl;
	while (std::cin >> operate) 
	{
		if (operate == 'C' || operate == 'c')
		{

		}
		if (operate == 'Q' || operate == 'q');
		if (operate == 'T' || operate == 't');
		std::cout << "What do you what to do?" << std::endl
			<< "Create new process : Please input \"C / c\"" << std::endl
			<< "Query existing processes : Please input \"Q / q\"" << std::endl
			<< "Terminate the program : Please input \"T / t\"" << std::endl;
	}
	
}