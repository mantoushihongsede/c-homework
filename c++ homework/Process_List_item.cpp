//Process_List_item��ķǳ�Ա�ӿں���

#include<iostream>
#include<vector>
#include"Free_Blocks.h"
#include"Process_List_item.h"

/*�������ڣ�22/12/12
  �������ܣ�����һ���µ���������뵽�����β
  ����������ָ��Ŀ�������ͷ��ָ�룬�Կ��п������ã���ҳ�������
  ��������ֵ������0����ʾһ������������1����ʾ�����ڴ�鲻��������2����ʾ��������ڴ治����������ֹ����
 */
int Add_Node(Process_List_item* head, Free_Blocks& free, std::vector<int>& page_table)
{
	int length = 0;
	std::cout << "�����ڴ����: " << std::endl;
	std::cin >> length;
	if (free.size() < length)		//������п鲻�������˳�����
	{
		std::cout << "�ڴ�鲻��: ";
		return 1;
	}
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 2;				//�ڴ�����ʧ�����˳�����
	p->length = length;						//��ʼ�����̶�Ӧ��ҳ����
	std::cout << "������" << std::endl;
	std::cin >> p->name;					//��ʼ��������
	std::cout << "���ȼ�" << std::endl;
	std::cin >> p->Priority;				//��ʼ���������ȼ�
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
	p->begin = free.outQueue(length, page_table);
	return 0;
}


/*�������ڣ�22/12/13
  �������ܣ�ɾ��һ���ɵ������Ĭ��ɾ�����ȼ��͵ģ�����ָ��ɾ����������
  ����������ָ��Ŀ�������ͷ��ָ�룬�Կ��п������ã���ҳ������ã�Ҫɾ���Ľ�������Ĭ��Ϊ��һ��)
  ��������ֵ��ָ�������ͷ��ָ��
 */
Process_List_item* Delete_Node(Process_List_item* head, Free_Blocks& free, std::vector<int>& page_table, std::string process_name = "null")
{
	auto check = head;
	auto front = head;
	if (process_name == "null" || process_name == head->name) //Ĭ������º�Ŀ�����Ϊ��һ������ʱ����ɾ����һ�����̱���
	{
		free.inQueue(head->begin, head->length, page_table);
		auto temp = head->next;
		delete head;
		return temp;
	}
	while (check->name != process_name)						//����Ŀ�Ľ���
	{
		if (check->next == nullptr)							//ʼ��δ�ҵ�
		{
			free.inQueue(head->begin, head->length, page_table);
			auto temp = head->next;
			delete head;
			return temp;
		}
		front = check;
		check = check->next;								//������һ�����̱���
	}
	auto now = check;										//�����е���˵���ҵ���Ŀ����̱���
	free.inQueue(now->begin, now->length, page_table);
	if (now->next == nullptr)								//��ǰΪ���һ������
	{
		front->next = nullptr;
		delete now;
	}
	else													//�������һ������
	{
		front->next = now->next;
		delete now;
	}
	return head;
}


/*�������ڣ�22/12/13
  �������ܣ��ӵ�ǰλ�ÿ�ʼɾ����������
  ����������ָ��Ŀ�������ͷ��ָ��
  ��������ֵ����
 */
void Clear_All(Process_List_item* head)
{
	auto now = head;
	while (now->next != nullptr)
	{
		head = now->next;
		delete now;
	}
}