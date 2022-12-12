/*创建日期：22/12/12
  函数功能：创建一个新的链表项，插入到链表结尾
  函数参数：指向目标链表表头的指针
  函数返回值：返回0，表示一切正常；返回1，表示空闲内存块不够；返回2，表示程序空闲内存不够，建议终止程序
 */
#include"Free_Blocks.h"
#include"Process_List_item.h"
#include<iostream>

int Add_Node(Process_List_item* head, Free_Blocks* free)
{
	int length = 0;
	std::cout << "所需内存块数: " << std::endl;
	std::cin >> length;
	if (length > free->length)				//如果空闲块不够，则退出函数
	{
		std::cout << "内存块不够: ";
		return 1;							
	}
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 2;				//内存申请失败则退出函数
	std::cout << "进程名" << std::endl;
	std::cin >> p->name;
	std::cout << "优先级" << std::endl;
	std::cin >> p->Priority;
	if (head == nullptr)					//head应在主函数中初始化为nullptr，此处检测链表是否为空
	{
		head = p;
	}
	else
	{
		while (pr->next != nullptr)
		{
			if (pr->next->Priority > pr->Priority)
			{
				p->next = pr->next;
				break;
			}
			pr = pr->next;
		}
		pr->next = p;
	}
	//
	return 0;
}