//Free_blocks类的成员函数
#include"Free_Blocks.h"
#include<vector>
#include<iostream>

/*创建日期：22/12/13
  函数功能：从指定页码开始，将指定长度的页对应的物理块依次加入空闲块表
  函数参数：一个整型，标志页表始址；一个整型，标志页表成都；一个对vector<int>类型的引用，标志页表
  函数返回值：返回页表始址
 */
void Free_Blocks::inQueue(int origin, int length,std::vector<int>& page_table)
{
	for (int i = 0; i < length; i++)
	{
		this->number[rear] = page_table[origin + i];
		this->rear++;
		if (this->full())
		{
			std::cout << "Fatal Error!";
			exit(0);
		}
	}
}


/*创建日期：22/12/13
  函数功能：从空闲块表上取下一定数量的物理块，并将对应的块号存储到页表中
  函数参数：一个整型，标志所需物理块；一个对vector<int>类型的引用，标志页表
  函数返回值：返回页表始址
 */
int Free_Blocks::outQueue(int number, std::vector<int>& page_table)
{
	int flag = page_table.size();
	for (int i = 0; i < number; i++)
	{
		page_table.push_back(this->number[this->front++]);
	}
	return flag;
}
