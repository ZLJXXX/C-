#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
//���嵥��ͨѶ¼��Ա����Ϣ
typedef struct Contact
{
	char _name[16];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;
//����ͨѶ¼���
typedef struct Contactbook
{
	Contact* _Contactarray;
	size_t _size;//��ϵ�˵ĸ���
	size_t _capacity;//ͨѶ¼������
}Contactbook;
void ContactbookInit(Contactbook* pbook);
void ContactbookDestory(Contactbook* pbook);
void ContactbookAdd(Contactbook* pbook, Contact* cname);
void Contactbookdelete(Contactbook* pbook, const char name);
void Contactbookfind(Contactbook* pbook, const char name);
void Contactbooksave(Contactbook* pbook, const char* file);
void Contactbookload(Contactbook* pbook, const char* file);
void Contactbookprint(Contactbook* pbook);
