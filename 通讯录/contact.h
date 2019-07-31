#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
//定义单个通讯录成员的信息
typedef struct Contact
{
	char _name[16];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;
//定义通讯录表格
typedef struct Contactbook
{
	Contact* _Contactarray;
	size_t _size;//联系人的个数
	size_t _capacity;//通讯录的容量
}Contactbook;
void ContactbookInit(Contactbook* pbook);
void ContactbookDestory(Contactbook* pbook);
void ContactbookAdd(Contactbook* pbook, Contact* cname);
void Contactbookdelete(Contactbook* pbook, const char name);
void Contactbookfind(Contactbook* pbook, const char name);
void Contactbooksave(Contactbook* pbook, const char* file);
void Contactbookload(Contactbook* pbook, const char* file);
void Contactbookprint(Contactbook* pbook);
