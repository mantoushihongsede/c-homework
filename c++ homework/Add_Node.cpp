/*�������ڣ�22/12/12
  �������ܣ�����һ���µ���������뵽�����β
  ����������ָ��Ŀ�������ͷ��ָ��
  ��������ֵ������0����ʾһ������������1����ʾ�����ڴ�鲻��������2����ʾ��������ڴ治����������ֹ����
 */
#include"Free_Blocks.h"
#include"Process_List_item.h"
#include<iostream>

int Add_Node(Process_List_item* head, Free_Blocks* free)
{
	int length = 0;
	std::cout << "�����ڴ����: " << std::endl;
	std::cin >> length;
	if (length > free->length)				//������п鲻�������˳�����
	{
		std::cout << "�ڴ�鲻��: ";
		return 1;							
	}
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 2;				//�ڴ�����ʧ�����˳�����
	std::cout << "������" << std::endl;
	std::cin >> p->name;
	std::cout << "���ȼ�" << std::endl;
	std::cin >> p->Priority;
	if (head == nullptr)					//headӦ���������г�ʼ��Ϊnullptr���˴���������Ƿ�Ϊ��
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