#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include"Process_List_item.h"
#include"Free_Blocks.h"
#include"Memory.h"

const int memory_size = 16;					//模拟的内存的大小（单位是物理块的个数）
const int blocks_size = 16;					//物理块的大小（单位是char）

void Q_page_table(const std::vector<int>& page_table);      //函数声明，定义在Page_Table.cpp中
int Address_Translation(const int(&information)[2], std::vector<int>& page_table);

int main(void)
{
	Memory memory;											//创建模拟内存的数据结构
	memory.Initialization_Memory(memory_size, blocks_size);
	Free_Blocks free_table(memory_size);					//创建模拟空闲块表的数据结构
	std::vector<int> page_table;							//创建模拟页表的数据结构
	Process_List_item* head = nullptr;						//创建进程链表
	std::string operate;
	std::cout << "What do you what to do?" << std::endl
		<< "Create new process : Please input \"C / c\"" << std::endl
		<< "Delete new process : Please input \"D / d\"" << std::endl
		<< "Query existing processes : Please input \"P / p\"" << std::endl
		<< "Query free blocks : Please input \"FB / fb\"" << std::endl
		<< "Query page table : Please input \"PT / pt\"" << std::endl
		<< "Convert logical address to physical address : Please input \"CT/ ct\"" << std::endl
		<< "Terminate the program : Please input \"T / t\"" << std::endl;
	while (std::cin >> operate) 
	{
		if (operate == "C" || operate == "c")
		{
			int flag = Add_Node(head, free_table, page_table);
			if (flag == 0) goto next_loop;
			if (flag == 1)
			{
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				std::cout << "Memory blocks are not enough! " << std::endl;
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				goto next_loop;
			}
			if (flag == 2)
			{
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				std::cout << "Fatal Error! Computer Memory is not enough! " << std::endl;
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				return 0;
			}
		}
		if (operate == "D" || operate == "d")
		{
			std::string process_name;
			std::cin.get();
			std::cout << "Process name: ";
			getline(std::cin, process_name);
			head = Delete_Node(head, free_table, page_table, process_name);
			goto next_loop;
		}
		if (operate == "P" || operate == "p")
		{
			Q_E_Process(head);
			goto next_loop;
		}
		if (operate == "FB" || operate == "fb")
		{
			free_table.Q_Free_Blocks();
			goto next_loop;
		}
		if (operate == "PT" || operate == "pt")
		{
			Q_page_table(page_table);
			goto next_loop;
		}
		if (operate == "CT" || operate == "ct")
		{
			std::string ch;
			std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
			std::cout << "In which process do you want to implement?" << std::endl;
			std::cin >> ch;
			int information[2] = { 0 };			//模拟页表寄存器
			int flag = 1;						//返回值为1时，重复执行Check
			while (flag == 1)	flag = Check(head, ch, information);
			if (flag == 2)
			{
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				goto next_loop;
			}
			flag = 1;							//返回值为1时，重复执行Address_Translation
			while(flag == 1) flag = Address_Translation(information, page_table);
			std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
			goto next_loop;
		}
		if (operate == "T" || operate == "t")
		{
			if (head != nullptr)
			{
				Clear_All(head);
			}
			break;
		}
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		std::cout << "Wrong input!" << std::endl;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	next_loop :
		std::cout << "\n\n\n";
		std::cout << "What do you what to do?" << std::endl
			<< "Create new process : Please input \"C / c\"" << std::endl
			<< "Delete new process : Please input \"D / d\"" << std::endl
			<< "Query existing processes : Please input \"P / p\"" << std::endl
			<< "Query free blocks : Please input \"FB / fb\"" << std::endl
			<< "Query page table : Please input \"PT / pt\"" << std::endl
			<< "Convert logical address to physical address : Please input \"CT/ ct\"" << std::endl
			<< "Terminate the program : Please input \"T / t\"" << std::endl;
	}
}

