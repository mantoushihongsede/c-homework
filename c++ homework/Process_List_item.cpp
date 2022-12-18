//Process_List_item类的非成员接口函数

#include<iostream>
#include<vector>
#include"Free_Blocks.h"
#include"Process_List_item.h"

/*创建日期：22/12/12
  函数功能：创建一个新的链表项，插入到链表结尾
  函数参数：指向目标链表表头的指针，对空闲块表的引用，对页表的引用
  函数返回值：返回0，表示一切正常；返回1，表示空闲内存块不够；返回2，表示程序空闲内存不够，建议终止程序
 */
int Add_Node(Process_List_item* (&head), Free_Blocks& free, std::vector<int>& page_table)
{
	int length = 0;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	std::cout << "How many memory blocks are required?(1~16) " << std::endl;
	std::cin >> length;
	std::cin.get();
	if (free.size() < length || length < 0) { return 1; }	//如果空闲块不够，则退出函数
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 2;				//内存申请失败则退出函数
	p->length = length;						//初始化进程对应的页表长度
	std::cout << "Process's name: " << std::endl;
	std::cin >> p->name;					//初始化进程名
	do{										//初始化进程优先级
		std::cout << "Priority(from 1 to 3)" << std::endl;
		std::cin >> p->Priority;
		std::cin.get();
	} while (p->Priority < 1 || p->Priority > 3);
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
	p->begin = free.outQueue(length, page_table);
	std::cout << "Successfully generated" << std::endl;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	return 0;
}


/*创建日期：22/12/13
  函数功能：删除一个旧的链表项，默认删除优先级低的，除非指定删除的链表项
  函数参数：指向目标链表表头的指针，对空闲块表的引用，对页表的引用，要删除的进程名（默认为第一个)
  函数返回值：指向链表表头的指针
 */
Process_List_item* Delete_Node(Process_List_item* (& head), Free_Blocks& free, std::vector<int>& page_table, std::string process_name = "null")
{
	if (head == nullptr)
	{
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		std::cout << "NO process now" << std::endl;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		return head;
	}
	auto check = head;
	auto front = head;
	if (process_name == "null" || process_name == head->name) //默认情况下和目标进程为第一个进程时，均删除第一个进程表项
	{
		free.inQueue(head->begin, head->length, page_table);
		auto temp = head->next;
		delete head;
		return temp;
	}
	while (check->name != process_name)						//检索目的进程
	{
		if (check->next == nullptr)							//始终未找到
		{
			free.inQueue(head->begin, head->length, page_table);
			auto temp = head->next;
			delete head;
			return temp;
		}
		front = check;
		check = check->next;								//检索下一个进程表项
	}
	auto now = check;										//能运行到这说明找到了目标进程表项
	free.inQueue(now->begin, now->length, page_table);
	if (now->next == nullptr)								//当前为最后一个表项
	{
		front->next = nullptr;
		delete now;
	}
	else													//不是最后一个表项
	{
		front->next = now->next;
		delete now;
	}
	return head;
}


/*创建日期：22/12/13
  函数功能：从当前位置开始删除整个链表
  函数参数：指向目标链表表头的指针
  函数返回值：返回1，表示链表为空；返回0，表示正常结束
 */
int Clear_All(Process_List_item* head)
{
	if (head == nullptr)
	{
		return 1;
	}
	while (head->next != nullptr)
	{
		auto temp = head->next;
		delete head;
		head = temp;
	}
	delete head;
	return 0;
}

/*创建日期：22/12/14
  函数功能：从当前位置开始展示整个链表信息
  函数参数：指向目标链表表头的指针
  函数返回值：返回1，表示链表为空；返回0，表示正常结束
 */
int Q_E_Process(Process_List_item* head)
{
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	if (head == nullptr)
	{
		std::cout << "链表为空" << std::endl;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		return 1;
	}
	do {
		std::cout << "Current process name :" << head->name << std::endl;
		std::cout << "Current process' name's Priority:" << head->Priority << std::endl;
		std::cout << "Current process's home page :" << head->begin << std::endl;
		std::cout << "Current process' name's total pages :" << head->length << std::endl;
		if (head->next != nullptr)
		{
			std::cout << "Next process name :" << head->next->name << std::endl;
		}
		else
		{
			std::cout << "Final process" << std::endl;
		}
		head = head->next;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	} while (head != nullptr);
	return 0;
}

/*创建日期：22/12/17
  函数功能：检查链表中是否有指定名字的进程
  函数参数：指向目标链表表头的指针，一个进程名（string), 一个信息数组（用与存储页数和页内地址）
  函数返回值：返回2，进程表为空；返回1，表示没找到；返回0，表示正常结束
 */
int Check(Process_List_item* (&head), std::string name, int information[2])
{
	if (head == nullptr)
	{
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		std::cout << "Empty process list!" << std::endl;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		return 2;
	}
	else
	{
		while (head->name != name)
		{
			if (head->next == nullptr)
			{
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				std::cout << "Process not found" << std::endl;
				std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
				return 1;
			}
			head = head->next;
		}
		information[0] = head->begin;
		information[1] = head->length;
		return 0;
	}
}