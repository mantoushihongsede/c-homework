/*�������ڣ�22/12/12
  �������ܣ�����һ���µ���������뵽�����β
  ����������ָ��Ŀ�������ͷ��ָ��
  ��������ֵ��
 */
#include"Process_List_item.h"
int Add_Node(Process_List_item* head)
{
	Process_List_item* p = new Process_List_item;
	Process_List_item* pr = head;
	if (p == nullptr) return 0;				//�ڴ�����ʧ�����Ƴ�����
	if (head == nullptr)					//headӦ���������г�ʼ��Ϊnullptr���˴���������Ƿ�Ϊ��
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