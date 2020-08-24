#include <getch.h>
#include<stdlib.h>
#include "game2048.h"
#include "derection.h"
#include "tools.h"
#define WIN 32
int (*view)[4]=NULL;
// 初始化相关资源、加载数据
void init_game(void)
{
	debug("%s\n",__func__);
	// 初始化随机数
	// 申请堆内存
	view=(int(*)[4])malloc(sizeof(int)*4*4);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			view[i][j]=0;
		}
	}
	// 从文件中加载数据	
}

// 运行游戏
void run_game(void)
{
	debug("%s\n",__func__);
	for(;;)
	{
		// 显示界面
		rand_numb();
		show_view();
		// 随机产生一个数字
		// 检查是否还能继续
		if(is_godie())
		{
			exit_game();
			return;
		}
		// 获取方向键并处理
		switch(getch())
		{
			case 183:up(); break;
			case 184:down(); break;
			case 185:right(); break;
			case 186:left(); break;
		}
	}
}

// 释放相关资源、保存数据
void exit_game(void)
{
	debug("%s\n",__func__);
	// 保存数据
	free(view);
	view=NULL;
	// 释放堆内存
}
