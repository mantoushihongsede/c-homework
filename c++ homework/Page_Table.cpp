//页表所需函数
#include<vector>
#include"Process_List_item.h"

/*创建日期：22/12/13
  函数功能：更新页表
  函数参数： 一个vector容器（新页表）, 一个vector容器（页表）, 指向目标链表表头的指针
  函数返回值：无
 */
void Update(std::vector<int>& new_page_table, std::vector<int>& page_table, Process_List_item* head)
{
	while (head != nullptr)
	{
		auto flag = new_page_table.size();
		for (int i = 0; i < head->length; i++)
		{
			new_page_table[flag] = page_table[(head->begin) + i];
		}
		head->begin = flag;
		head = head->next;
	}
	return;
}