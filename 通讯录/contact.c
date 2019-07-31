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
	//���жϿռ��Ƿ��㹻��������������
	if (pbook->_size >= pbook->_capacity)
	{
		Contact* _Newcapacity = ralloc(pbook->_capacity, sizeof(Contact)*pbook->_capacity * 2);
	//�ж������Ƿ�ɹ�
		if (_Newcapacity == NULL)
		{
			printf("relloc error\n");
			exit(-1);
		}
		pbook->_capacity = _Newcapacity;//���¿ռ����ȥ
	}
	//�ѿռ���ṹ��Contact
	Contact* array = pbook->_capacity;
	size_t i = pbook->_size;
	strcpy(array[i]._name, cname->_name);
	strcpy(array[i]._address, cname->_address);
	strcpy(array[i]._tel, cname->_tel);//ǰ����Ϊ�ַ�������
	array[i]._age = cname->_age;
	pbook->_size++;
}
//

void Contactbookdelete(Contactbook* pbook, const char name)
{
	Contact* pon = Contactbookfind(pbook, name);
	if (pon == NULL)
	{
		printf("ɾ����Ϣʱδ�ҵ������������\n");
	}
	//ponС������βԪ�صĵ�ַ��ѭ������
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
	//��������
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
		printf("���ļ�ʧ��\n");
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
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact),1,fp)==1)
	{
		ContactbookAdd(pbook, &con);
	}
	fclose(fp);
}