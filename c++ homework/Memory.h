//ģ���ڴ�����ݽṹ��Ϊ�˱���Խ����ʣ������װһ��
#pragma once
#ifndef MEMORY
#define MEMORY

#include<string>
#include<vector>
class Memory {
public:
	void Initialization_Memory(int M, int N);					//��ʼ��ģ���ڴ�����ݽṹ
private:
	std::vector<std::string> memory;
};

#endif