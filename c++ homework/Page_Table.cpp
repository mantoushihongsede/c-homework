//ҳ�����躯��
#include<vector>
#include"Process_List_item.h"

/*�������ڣ�22/12/13
  �������ܣ�����ҳ��
  ���������� һ��vector��������ҳ��, һ��vector������ҳ��, ָ��Ŀ�������ͷ��ָ��
  ��������ֵ����
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