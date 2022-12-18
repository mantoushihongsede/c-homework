// ��ַת��������Ҫ�õ��ĺ���
#include<string>
#include<iostream>
#include<vector>

/*�������ڣ�22/12/18
  �������ܣ�������ת��Ϊʮ��������
  ����������
  ��������ֵ������1����ʾ�������룻����0����ʾ��������
 */
int b_to_i(const std::string &b, int& address_i)
{
	address_i = 0;
	for (int k = 0; k < 4; k++)
	{
		if (b[k] >= '2' || b[k] < '0')
		{
			std::cout << "Wrong input!(binary plz)" << std::endl;
			return 1;
		}
		address_i += (int)pow(2, 3 - k) * (int)(b[k] - '0');
	}
	return 0;
}

/*�������ڣ�22/12/18
  �������ܣ�ʮ����ת��Ϊ������
  ����������
  ��������ֵ����
 */
void i_to_b(std::string& b,const int& address_i)
{
	int temp = address_i;
	for (int k = 0; k < 4; k++)
	{
		b[k] = (char)(temp / (int)pow(2, 3 - k) + '0');
		temp = temp - (temp / (int)pow(2, 3 - k)) * (int)pow(2, 3 - k);
	}
	return;
}

/*�������ڣ�22/12/18
  �������ܣ����߼���ַ��ʮ���ƣ��ҵ������ַ��ʮ���ƣ�
  �����������߼���ַ��ʮ���ƣ�����Ϣ���飬ҳ��
  ��������ֵ������0����ʾ��������������1����ʾ��������
 */
int check_page_table(int& address_i,const int (&information)[2], const std::vector<int>& page_table)
{
	if (address_i > information[0] + information[1] || address_i < information[0]) 
	{
		std::cout << "Address out of bounds!" << std::endl;
		return 1;
	}
	address_i = page_table[address_i];
	return 0;
}

/*�������ڣ�22/12/18
  �������ܣ�ʵ�ֵ�ַת��
  ������������Ϣ���飬ҳ��
  ��������ֵ������0����ʾ��������������1����ʾ��������
 */
int Address_Translation(const int(&information)[2], std::vector<int>& page_table)
{
	std::string page = "0000";
	std::string in_page = "0000";
	i_to_b(page, information[0]);
	i_to_b(in_page,information[0] + information[1] - 1);
	std::cout << "Address range : " << page << "0000"
		<< " to " << in_page << "1111" << std::endl;
	std::cout << "Plz input logical address!(8-bit binary) or Enter \"end\" to terminate" << std::endl;
	std::string address_b;
	int address_i = 0;
	std::cin >> address_b;
	if (address_b == "end") return 0;
	if (address_b.size() == 8)
	{
		if (b_to_i(address_b, address_i))
		{
			std::string temp;
			std::cout << "Do you want to continue?: (Y/N)" << std::endl;
			std::cin >> temp;
			if (temp == "Y") return 1;
			else return 0;
		}
		if (check_page_table(address_i, information, page_table))
		{
			std::string temp;
			std::cout << "Do you want to continue?: (Y/N)" << std::endl;
			std::cin >> temp;
			if (temp == "Y") return 1;
			else return 0;
		}
		i_to_b(address_b, address_i);
		std::cout << "Pysical address : " << address_b << std::endl;
		std::string temp;
		std::cout << "Do you want to continue?: (Y/N)" << std::endl;
		std::cin >> temp;
		if (temp == "Y") return 1;
		else return 0;
	}
	else
	{
		std::cout << "Wrong input!(8-bit plz)" << std::endl;
		std::string temp;
		std::cout << "Do you want to continue?: (Y/N)" << std::endl;
		std::cin >> temp;
		if (temp == "Y") return 1;
		else return 0;
	}
}
