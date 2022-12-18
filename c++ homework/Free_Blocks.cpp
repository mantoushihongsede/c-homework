//Free_blocks��ĳ�Ա����
#include"Free_Blocks.h"
#include<vector>
#include<iostream>

/*�������ڣ�22/12/13
  �������ܣ���ָ��ҳ�뿪ʼ����ָ�����ȵ�ҳ��Ӧ����������μ�����п��
  ����������һ�����ͣ���־ҳ��ʼַ��һ�����ͣ���־ҳ��ɶ���һ����vector<int>���͵����ã���־ҳ��
  ��������ֵ��
 */
void Free_Blocks::inQueue(int origin, int length,std::vector<int>& page_table)
{
	for (int i = 0; i < length; i++)
	{
		this->number[rear] = page_table[origin + i];
		this->rear = (this->rear + 1) % this->length;
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
		page_table.push_back(this->number[this->front]);
		this->front = (this->front + 1) % this->length;
	}
	return flag;
}

/*�������ڣ�22/12/14
  �������ܣ�չʾ���п�����������
  ������������
  ��������ֵ����
 */
void Free_Blocks::Q_Free_Blocks() const
{
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
	if (this->front == this->rear)
	{
		std::cout << "Without free blocks! " << std::endl;
		std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
		return;
	}
	std::cout << "Current free blocks :" << std::endl;
	for (int i = this->front; i != this->rear ; i = (i + 1) % this->length)
	{
		std::cout << this->number[i] << std::endl;
	}
	std::cout << "The end! " << std::endl;
	std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
}