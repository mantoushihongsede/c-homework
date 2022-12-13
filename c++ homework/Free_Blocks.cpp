//Free_blocks��ĳ�Ա����
#include"Free_Blocks.h"
#include<vector>
#include<iostream>

/*�������ڣ�22/12/13
  �������ܣ���ָ��ҳ�뿪ʼ����ָ�����ȵ�ҳ��Ӧ����������μ�����п��
  ����������һ�����ͣ���־ҳ��ʼַ��һ�����ͣ���־ҳ��ɶ���һ����vector<int>���͵����ã���־ҳ��
  ��������ֵ������ҳ��ʼַ
 */
void Free_Blocks::inQueue(int origin, int length,std::vector<int>& page_table)
{
	for (int i = 0; i < length; i++)
	{
		this->number[rear] = page_table[origin + i];
		this->rear++;
		if (this->full())
		{
			std::cout << "Fatal Error!";
			exit(0);
		}
	}
}


/*�������ڣ�22/12/13
  �������ܣ��ӿ��п����ȡ��һ������������飬������Ӧ�Ŀ�Ŵ洢��ҳ����
  ����������һ�����ͣ���־��������飻һ����vector<int>���͵����ã���־ҳ��
  ��������ֵ������ҳ��ʼַ
 */
int Free_Blocks::outQueue(int number, std::vector<int>& page_table)
{
	int flag = page_table.size();
	for (int i = 0; i < number; i++)
	{
		page_table.push_back(this->number[this->front++]);
	}
	return flag;
}
