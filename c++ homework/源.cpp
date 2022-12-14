#include<iostream>
#include<string>
#include<vector>
#include"Process_List_item.h"
#include"Free_Blocks.h"
#include"Memory.h"

const int memory_size = 16;					//ģ����ڴ�Ĵ�С����λ�������ĸ�����
const int blocks_size = 16;					//�����Ĵ�С����λ��char��

void Q_page_table(const std::vector<int>& page_table);      //����������������Page_Table.cpp��

int main(void)
{
	Memory memory;											//����ģ���ڴ�����ݽṹ
	memory.Initialization_Memory(memory_size, blocks_size);
	Free_Blocks free_table(memory_size);					//����ģ����п������ݽṹ
	std::vector<int> page_table;							//����ģ��ҳ������ݽṹ
	Process_List_item* head = nullptr;						//������������
	std::string operate;
	std::cout << "What do you what to do?" << std::endl
		<< "Create new process : Please input \"C / c\"" << std::endl
		<< "Delete new process : Please input \"D / d\"" << std::endl
		<< "Query existing processes : Please input \"P / p\"" << std::endl
		<< "Query free blocks : Please input \"FB / fb\"" << std::endl
		<< "Query page table : Please input \"PT / pt\"" << std::endl
		<< "Terminate the program : Please input \"T / t\"" << std::endl;
	while (getline(std::cin, operate)) 
	{
		if (operate == "C" || operate == "c")
		{
			int flag = Add_Node(head, free_table, page_table);
			switch (flag) {
			case 1:
				std::cout << "Memory blocks are not enough! ";
				break;
			case 2:
				std::cout << "Fatal Error! Computer Memory is not enough! ";
				return 0;
			}
			goto next_loop;
		}
		if (operate == "D" || operate == "d")
		{
			std::string process_name;
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
		if (operate == "T" || operate == "t")
		{
			if (head != nullptr)
			{
				Clear_All(head);
			}
			break;
		}
		std::cout << "Wrong input!";
		next_loop :
		std::cout<< "Create new process : Please input \"C / c\"" << std::endl
			<< "Delete new process : Please input \"D / d\"" << std::endl
			<< "Query existing processes : Please input \"P / p\"" << std::endl
			<< "Query free blocks : Please input \"FB / fb\"" << std::endl
			<< "Query page table : Please input \"PT / pt\"" << std::endl
			<< "Terminate the program : Please input \"T / t\"" << std::endl;
	}
	
}