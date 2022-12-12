/*创建日期：22/12/12
  函数功能：创建一个新的链表项，插入到链表结尾
  函数参数：指向目标链表表头的指针
  函数返回值：
 */
#include"Process_List_item.h"
int Add_Node(Process_List_item* head)
{
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 0;				//内存申请失败则推出函数
	if (head == nullptr)					//head应在主函数中初始化为nullptr，此处检测链表是否为空
	{
		head = p;
		return 1;
	}
	else
	{
		while (pr->next != nullptr)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	return 1;
}