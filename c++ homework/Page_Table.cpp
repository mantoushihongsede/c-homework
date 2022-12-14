//ҳ�����躯��
#include<iostream>
#include<vector>
#include"Process_List_item.h"

/*�������ڣ�22/12/13
  �������ܣ�����ҳ��
  ���������� һ��vector��������ҳ��, һ��vector������ҳ��, ָ��Ŀ�������ͷ��ָ��
  ��������ֵ����
 */
void Update_page(std::vector<int>& new_page_table, const std::vector<int>& page_table, Process_List_item* head)
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

/*�������ڣ�22/12/14
  �������ܣ�չʾҳ��
  ����������һ��vector������ҳ��
  ��������ֵ����
 */
void Q_page_table(const std::vector<int>& page_table)
{
	int count_for_page_table = 0;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	if (page_table.size() == 0)
	{
		std::cout << "Blank page table" << std::endl;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		return;
	}
	std::cout << "Page number\t" << "Corresponding block number" << std::endl;
	for (auto one : page_table)
	{
		std::cout << count_for_page_table << "\t" << one << std::endl;
		++count_for_page_table;
	}
	std::cout << "The end! " << std::endl;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
}
