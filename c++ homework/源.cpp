#include<iostream>
#include<string>
#include<vector>
#include"Process_List_item.h"
#include"Free_Blocks.h"
#include"Memory.h"

int memory_size = 16;					//ģ����ڴ�Ĵ�С����λ�������ĸ�����
int blocks_size = 16;					//�����Ĵ�С����λ��char��

int main(void)
{
	Memory memory;											//����ģ���ڴ�����ݽṹ
	memory.Initialization_Memory(memory_size, blocks_size);
	Free_Blocks free_table(memory_size);					//����ģ����п������ݽṹ
	std::vector<int> page_table;							//����ģ��ҳ������ݽṹ
	char operate;
	int flag = 0;												//��־��������־�Ƿ���һ������δɾ���Ľ���
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