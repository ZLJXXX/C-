#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void ContactbookInit(Contactbook* pbook)
{
	assert(pbook);
	pbook->_Contactarray = (Contact*)malloc(sizeof(Contact)* 8);
	if (pbook->_Contactarray == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	pbook->_size = 0;
	pbook->_capacity = 8;
}
void ContactbookDestory(Contactbook* pbook)
{
	assert(pbook);
	free(pbook->_Contactarray);
	pbook->_Contactarray = NULL;
	pbook->_size = 0;
	pbook->_capacity = 0;
}
void ContactbookAdd(Contactbook* pbook, Contact* cname)
{
	assert(pbook);
	//先判断空间是否足够，若已满则增容
	if (pbook->_size >= pbook->_capacity)
	{
		Contact* _Newcapacity = ralloc(pbook->_capacity, sizeof(Contact)*pbook->_capacity * 2);
	//判断增容是否成功
		if (_Newcapacity == NULL)
		{
			printf("relloc error\n");
			exit(-1);
		}
		pbook->_capacity = _Newcapacity;//把新空间给过去
	}
	//把空间给结构体Contact
	Contact* array = pbook->_capacity;
	size_t i = pbook->_size;
	strcpy(array[i]._name, cname->_name);
	strcpy(array[i]._address, cname->_address);
	strcpy(array[i]._tel, cname->_tel);//前三个为字符串拷贝
	array[i]._age = cname->_age;
	pbook->_size++;
}
//

void Contactbookdelete(Contactbook* pbook, const char name)
{
	Contact* pon = Contactbookfind(pbook, name);
	if (pon == NULL)
	{
		printf("删除信息时未找到您输入的姓名\n");
	}
	//pon小于数组尾元素的地址则循环成立
	while (pon < pbook->_Contactarray + (pbook->_size - 1))
	{
		memcpy(pon, pon + 1, sizeof(Contact)); 
		pon++;
	}
	pbook->_size--;
}
Contact* Contactbookfind(Contactbook* pbook, const char name)
{
	assert(pbook && name);
	//遍历数组
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		if (strcmp(pbook->_Contactarray[i]._name, name) == 0)
		{
			return &pbook->_Contactarray[i];
		}
	}
	return NULL;
}
void Contactbooksave(Contactbook* pbook, const char* file)
{
	FILE* fp = fopen(file, "wb");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
	}
	Contact* array = pbook->_Contactarray;
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fwrite(&array[i], sizeof(Contact), 1, fp);
	}
	fclose(fp);
}
void Contactbookload(Contactbook* pbook, const char* file)
{
	FILE* fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact),1,fp)==1)
	{
		ContactbookAdd(pbook, &con);
	}
	fclose(fp);
}