#ifndef __USER_H__
	#define __USER_H__

	#include <stdio.h>
	#include <stdlib.h>
	#include <sqlite3.h>
	#include <string.h>

	typedef struct USER {
		char id[4];
		char name[20];
		char password[20];
		char startTime[20];
		struct USER* next;
	} User;
	
	/**
	 * 查询user表Demo
	 */
	void userDemo(void);
	/**
	 * 查询数据时的回调函数
	 */
	static int select_callback(void* data, int col_count, char** col_values, char** col_name);
	/**
	 * 打印UserLinked链表
	 */
	void printUserLinked(User* userLinked);
	/**
	 * 获取UserLinked链表
	 */
	User* getUserLinked(char* sql);
	/**
	 * 释放链表中的数据
	 */
	void freeUserLinked(User* userLinked);
	/**
	 * 更新数据库
	 */
	int updateUserDB(char* sql);
	
#endif
