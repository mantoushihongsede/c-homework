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
int Add_Node(Process_List_item* (&head), Free_Blocks& free, std::vector<int>& page_table)
{
	int length = 0;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	std::cout << "How many memory blocks are required?(1~16) " << std::endl;
	std::cin >> length;
	std::cin.get();
	if (free.size() < length || length < 0) { return 1; }	//������п鲻�������˳�����
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 2;				//�ڴ�����ʧ�����˳�����
	p->length = length;						//��ʼ�����̶�Ӧ��ҳ����
	std::cout << "Process's name: " << std::endl;
	std::cin >> p->name;					//��ʼ��������
	do{										//��ʼ���������ȼ�
		std::cout << "Priority(from 1 to 3)" << std::endl;
		std::cin >> p->Priority;
		std::cin.get();
	} while (p->Priority < 1 || p->Priority > 3);
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
	std::cout << "Successfully generated" << std::endl;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	return 0;
}


/*�������ڣ�22/12/13
  �������ܣ�ɾ��һ���ɵ������Ĭ��ɾ�����ȼ��͵ģ�����ָ��ɾ����������
  ����������ָ��Ŀ�������ͷ��ָ�룬�Կ��п������ã���ҳ������ã�Ҫɾ���Ľ�������Ĭ��Ϊ��һ��)
  ��������ֵ��ָ�������ͷ��ָ��
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
  ��������ֵ������1����ʾ����Ϊ�գ�����0����ʾ��������
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

/*�������ڣ�22/12/14
  �������ܣ��ӵ�ǰλ�ÿ�ʼչʾ����������Ϣ
  ����������ָ��Ŀ�������ͷ��ָ��
  ��������ֵ������1����ʾ����Ϊ�գ�����0����ʾ��������
 */
int Q_E_Process(Process_List_item* head)
{
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	if (head == nullptr)
	{
		std::cout << "����Ϊ��" << std::endl;
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

/*�������ڣ�22/12/17
  �������ܣ�����������Ƿ���ָ�����ֵĽ���
  ����������ָ��Ŀ�������ͷ��ָ�룬һ����������string), һ����Ϣ���飨����洢ҳ����ҳ�ڵ�ַ��
  ��������ֵ������2�����̱�Ϊ�գ�����1����ʾû�ҵ�������0����ʾ��������
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