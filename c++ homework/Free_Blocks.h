//���п����ʵ�Ǹ�ѭ������
#pragma once
#ifndef FREE_BLOCKS
#define FREE_BLOCKS
#define N 64
#include<vector>

class Free_Blocks {
private:
	int number[N + 1] = { 0 };							//���
	int front = 0;       //ָ�����
	int rear = 0;		//ָ���β
public:
	Free_Blocks() { for (rear = 0; rear < N; rear++) number[rear] = rear; } // Ĭ�Ϲ��캯��
	int full() const { return (this->rear == this->front) ? 1 : 0; }		//����Ƿ�Ϊ���ĳ�Ա����
	int empty() const { return (this->rear == this->front) ? 1 : 0; }		//����Ƿ�Ϊ�յĳ�Ա����
	void inQueue(int origin, int length, std::vector<int>& page_table);		//��Ӻ���
	int outQueue(int number, std::vector<int>& page_table);					//���Ӻ���
	int size() { return this->rear - this->front; }							//���ض���ʵ�ʳ���
};

#endif
