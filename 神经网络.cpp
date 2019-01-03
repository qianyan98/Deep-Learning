//基于神经网络的语音识别程序

#include<stdio.h>
#include<malloc.h>

#define NUMV 26//顶点数
#define NUME 46//边数

double input[8]; //神经网络的输入
int edges1[NUMV][NUMV];//1号神经网络的邻接矩阵
int edges2[NUMV][NUMV];//2号神经网络的邻接矩阵
int edges3[NUMV][NUMV];//3号神经网络的邻接矩阵
double output1[4];//1号神经网络的输出
double output2[4];//2号神经网络的输出
double output3[4];//3号神经网络的输出

void CreatMGraph1() //生成1号神经网络图
{
	for (int i = 0; i < NUMV; i++)//初始化邻接矩阵
		for (int j = 0; j < NUMV; j++)
			edges1[i][j] = 0;

	//神经网络中每条有连接边的权重如下
	edges1[0][8] = 7;
	edges1[0][9] = 5;
	edges1[1][11] = 2;
	edges1[1][13] = 4;
	edges1[2][9] = 6;
	edges1[2][10] = 2;
	edges1[3][13] = 3;
	edges1[3][19] = 12;
	edges1[4][12] = 4;
	edges1[4][15] = 3;
	edges1[5][8] = 5;
	edges1[5][15] = 7;
	edges1[6][11] = 5;
	edges1[6][21] = 7;
	edges1[7][10] = 4;
	edges1[7][14] = 3;
	edges1[8][18] = 2;
	edges1[9][17] = 3;
	edges1[10][10] = 7;
	edges1[10][16] = 3;
	edges1[11][11] = 16;
	edges1[11][20] = 4;
	edges1[12][16] = 21;
	edges1[13][13] = 1;
	edges1[13][18] = 12;
	edges1[13][20] = 6;
	edges1[14][19] = 6;
	edges1[15][1] = 2;
	edges1[15][20] = 8;
	edges1[15][21] = 6;
	edges1[17][10] = 5;
	edges1[18][18] = 5;
	edges1[19][12] = 1;
	edges1[21][21] = 5;


	edges1[16][22] = 2;
	edges1[18][22] = 2;
	edges1[21][22] = 0;

	edges1[16][23] = 5;//西瓜无法满足
	edges1[17][23] = 8;
	edges1[19][23] = 390;

	edges1[17][24] =285;
	edges1[19][24] = 136;
	edges1[20][24] = 5;

	edges1[18][25] = 2;
	edges1[20][25] = 2;
	edges1[21][25] = 2;
}

void CreatMGraph2()//生成2号神经网络图
{
	for (int i = 0; i < NUMV; i++)//初始化邻接矩阵
		for (int j = 0; j < NUMV; j++)
			edges2[i][j] = 0;

	edges2[0][12] = 3;
	edges2[0][15] = 6;
	edges2[1][10] = 9;
	edges2[1][14] = 2;
	edges2[2][8] = 6;
	edges2[2][9] = 1;
	edges2[3][8] = 3;
	edges2[3][11] = 5;
	edges2[4][10] = 4;
	edges2[4][12] = 2;
	edges2[5][11] = 3;
	edges2[5][13] = 7;
	edges2[6][13] = 2;
	edges2[6][15] = 9;
	edges2[7][9] = 3;
	edges2[7][14] = 6;
	edges2[8][8] = 7;
	edges2[8][16] = 3;
	edges2[8][18] = 8;
	edges2[9][17] = 5;
	edges2[9][18] = 8;
	edges2[10][17] = 3;
	edges2[10][21] = 2;
	edges2[11][17] = 3;
	edges2[11][19] = 4;
	edges2[12][16] = 1;
	edges2[12][20] = 3;
	edges2[13][19] = 8;
	edges2[13][21] = 3;
	edges2[14][19] = 7;
	edges2[14][21] = 7;
	edges2[15][15] = 6;
	edges2[15][18] = 2;
	edges2[15][20] = 4;
	edges2[16][16] = 9;
	edges2[19][5] = 2;

	edges2[16][22] = 12;
	edges2[17][22] = 11;
	edges2[19][22] = 9;

	edges2[17][23] = 16;
	edges2[18][23] = 12;
	edges2[21][23] = 20;

	edges2[18][24] = 20;//葡萄无法满足
	edges2[20][24] = 42;

	edges2[16][25] = 11;
	edges2[19][25] = 6;
	edges2[20][25] = 4;
	edges2[21][25] = 10;
}
void CreatMGraph3()//生成3号神经网络图
{
	for (int i = 0; i < NUMV; i++)//初始化邻接矩阵
		for (int j = 0; j < NUMV; j++)
			edges3[i][j] = 0;

	edges3[0][11] = 1;
	edges3[0][14] = 4;
	edges3[1][8] = 8;
	edges3[1][9] = 9;
	edges3[2][12] = 5;
	edges3[2][13] = 2;
	edges3[3][10] = 5;
	edges3[3][14] = 8;
	edges3[4][8] = 7;
	edges3[4][15] = 8;
	edges3[5][8] = 3;
	edges3[5][12] = 1;
	edges3[6][11] = 2;
	edges3[6][15] = 9;
	edges3[7][10] = 3;
	edges3[7][13] = 2;
	edges3[7][21] = 3;
	edges3[8][18] = 2;
	edges3[9][16] = 2;
	edges3[9][18] = 6;
	edges3[10][17] = 9;
	edges3[10][21] = 5;
	edges3[11][16] = 8;
	edges3[11][19] = 2;
	edges3[12][12] = 4;
	edges3[12][17] = 7;
	edges3[12][20] = 8;
	edges3[13][21] = 4;
	edges3[14][18] = 7;
	edges3[14][21] = 7;
	edges3[15][20] = 4;
	edges3[15][21] = 8;
	edges3[18][18] = 4;
	edges3[19][13] = 1;
	
	
	edges3[16][22] = 4;
	edges3[17][22] = 10;
	edges3[18][22] = 1;
	edges3[20][22] = 15;
	edges3[21][22] = 14;

	edges3[8][23] = 166;
	edges3[16][23] = 2;
	edges3[19][23] = 1;

	edges3[13][24] = 31;
	edges3[20][24] = 41;

	edges3[17][25] = 5;//香蕉无法满足
	edges3[18][25] = 1;
	edges3[19][25] = 190;
	edges3[21][25] = 60;
}


void dataflow1() //1号神经网络中的数据流动
{
	double temp[22];

	temp[8] = input[0] * edges1[0][8] + input[5] * edges1[5][8];//第一层隐藏层
	temp[9] = input[0] * edges1[0][9] + input[2] * edges1[2][9];
	temp[15] = input[4] * edges1[4][15] + input[5] * edges1[5][15];//由于15号神经元的反馈作为1号神经元的输入，所以先计算15号神经元
	input[1] = input[1] + temp[15] * edges1[15][1];//1号神经元接受1号输入和15号的反馈
	temp[11] = input[1] * edges1[1][11] + input[6] * edges1[6][11];//暂时忽略11号神经元的自我反馈
	temp[11] = temp[11] * (edges1[11][11] + 1);//11号神经元的自我反馈
	temp[13] = input[1] * edges1[1][13] + input[3] * edges1[3][13];
	temp[13] = temp[13] * (edges1[13][13] + 1);//13号神经元的自我反馈
	temp[14]=input[7] * edges1[7][14];

	temp[17] = temp[9] * edges1[9][17];//第二层隐藏层
	temp[10] = input[2] * edges1[2][10] + input[7] * edges1[7][10]+temp[17]*edges1[17][10];//暂时忽略10号神经元的自我反馈
	temp[10]= temp[10] * (edges1[10][10] + 1);
	temp[19] = input[3] * edges1[3][19] + temp[14] * edges1[14][19];//计算出19号才能计算出12号才能计算出16号
	temp[12] = input[4] * edges1[4][12] + temp[19] * edges1[19][12];
	temp[16] = temp[10] * edges1[10][16] + temp[12] * edges1[12][16];
	temp[18] = temp[8] * edges1[8][18] + temp[13] * edges1[13][18];
	temp[18] = temp[18] * (edges1[18][18] + 1);
	temp[20] = temp[11] * edges1[11][20] + temp[13] * edges1[13][20]+temp[15]*edges1[15][20];
	temp[21] = input[6] * edges1[6][21] + temp[15] * edges1[15][21];
	temp[21] = temp[21] * (edges1[21][21] + 1);//21号神经元的自我反馈

	output1[0] = temp[16] * edges1[16][22] + temp[18] * edges1[18][22] + temp[21] * edges1[21][22];//最后一层神经元结果存入输出数组
	output1[1] = temp[16] * edges1[16][23] + temp[17] * edges1[17][23] + temp[19] * edges1[19][23];
	output1[2] = temp[17] * edges1[17][24] + temp[19] * edges1[19][24] + temp[20] * edges1[20][24];
	output1[3] = temp[18] * edges1[18][25] + temp[20] * edges1[20][25] + temp[21] * edges1[21][25];

}

void dataflow2() //2号神经网络中的数据流动
{
	double temp[22];

	temp[8] = input[2] * edges2[2][8] + input[3] * edges2[3][8];//第一层隐藏层
	temp[8] = temp[8] * (edges2[8][8] + 1);
	temp[9] = input[2] * edges2[2][9] + input[7] * edges2[7][9];
	temp[10] = input[1] * edges2[1][10] + input[4] * edges2[4][10];
	temp[11] = input[3] * edges2[3][11] + input[5] * edges2[5][11];
	temp[12] = input[4] * edges2[4][12] + input[0] * edges2[0][12];
	temp[13] = input[5] * edges2[5][13] + input[6] * edges2[6][13];
	temp[14] = input[1] * edges2[1][14]+ input[7] * edges2[7][14];
	temp[15] = input[0] * edges2[0][15] + input[6] * edges2[6][15];
	temp[15] = temp[15] * (edges2[15][15] + 1);

	temp[16] = temp[8] * edges2[8][16] + temp[12] * edges2[12][16];//第二层隐藏层
	temp[16] = temp[16] * (edges2[16][16] + 1);
	temp[17] = temp[9] * edges2[9][17]+temp[10] * edges2[10][17] + temp[11] * edges2[11][17];
	temp[18] = temp[8] * edges2[8][18] + temp[9] * edges2[9][18] + temp[15] * edges2[15][18];
	temp[19] = temp[11] * edges2[11][19] + temp[14] * edges2[14][19];
	temp[20] = temp[12] * edges2[12][20] + temp[15] * edges2[15][20];
	temp[21] = temp[10] * edges2[10][21] + temp[13] * edges2[13][21]+temp[14] * edges2[14][21];

	output2[0] = temp[16] * edges2[16][22] + temp[17] * edges2[17][22] + temp[19] * edges2[19][22];//最后一层神经元结果存入输出数组
	output2[1] = temp[17] * edges2[17][23] + temp[18] * edges2[18][23] + temp[21] * edges2[21][23];
	output2[2] = temp[18] * edges2[18][24] + temp[20] * edges2[20][24];
	output2[3] = temp[16] * edges2[16][25] + temp[19] * edges2[19][25] + temp[20] * edges2[20][25] + temp[21] * edges2[21][25];

}

void dataflow3() //3号神经网络中的数据流动
{
	double temp[22];

	temp[8] = input[1] * edges3[1][8] + input[4] * edges3[4][8];//第一层隐藏层
	temp[9] = input[1] * edges3[1][9] + input[5] * edges3[5][9];
	temp[10] = input[3] * edges3[3][10] + input[7] * edges3[7][10];
	temp[11] = input[0] * edges3[0][11] + input[6] * edges3[6][11];
	temp[19] = input[11] * edges3[11][19];//由于19号神经元反馈到上一层，提前计算
	temp[12] = input[2] * edges3[2][12] + input[5] * edges3[5][12];
	temp[12] = temp[12] * (edges3[12][12] + 10);
	temp[13] = input[2] * edges3[2][13] + input[7] * edges3[7][13]+temp[19] * edges3[19][13];
	temp[14] = input[0] * edges3[0][14] + input[3] * edges3[3][14];
	temp[15] = input[4] * edges3[4][15] + input[6] * edges3[6][15];

	temp[16] = temp[9] * edges3[9][16] + temp[11] * edges3[11][16];//第二层隐藏层
	temp[17] = temp[10] * edges3[10][17] + input[12] * edges3[12][17] ;
	temp[18] = temp[8] * edges3[8][18] + temp[9] * edges3[9][18] + temp[14] * edges3[14][18];
	temp[18] = temp[18] * (edges3[18][18] + 6);
	temp[20] = temp[12] * edges3[12][20] + temp[15] * edges3[15][20];
	temp[21] = temp[13] * edges3[13][21] + temp[15] * edges3[15][21] + temp[14] * edges3[14][21]+input[7]*edges3[7][21];

	output3[0] = temp[16] * edges3[16][22] + temp[17] * edges3[17][22] + temp[18] * edges3[18][22] + temp[20] * edges3[20][22];//最后一层神经元结果存入输出数组
	output3[1] = temp[8] * edges3[8][23] + temp[19] * edges3[19][23] + temp[21] * edges3[21][23];
	output3[2] = temp[13] * edges3[13][24] + temp[16] * edges3[16][24] + temp[20] * edges3[20][24];
	output3[3] = temp[17] * edges3[17][25] + temp[19] * edges3[19][25] + temp[18] * edges3[18][25] + temp[21] * edges3[21][25];

}

int main()
{
	int num1, num2, num3, num,nump,numq,tem;//三个神经网络的输出结果及最终结果
	double output_sum[4],temp;//三个神经网络的输出和

	CreatMGraph1();//搭建1号神经网络
	CreatMGraph2();//搭建2号神经网络
	CreatMGraph3();//搭建3号神经网络
	
	printf("请输入8维向量（只输数字，空格隔开）：");
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &input[0], &input[1], &input[2], &input[3], &input[4], &input[5], &input[6], &input[7]);
	dataflow1();//数据输入1号神经网络进行计算
	dataflow2();//数据输入2号神经网络进行计算
	dataflow3();//数据输入3号神经网络进行计算

	//printf("1号神经网络的输出是：%lf %lf %lf %lf\n", output1[0], output1[1], output1[2], output1[3]);//调试用
	//printf("2号神经网络的输出是：%lf %lf %lf %lf\n", output2[0], output2[1], output2[2], output2[3]);
	//printf("3号神经网络的输出是：%lf %lf %lf %lf\n", output3[0], output3[1], output3[2], output3[3]);

	num1 = 0;//分别计算三个神经网络输出结果中的最大值
	if (output1[1] > output1[num1]) 
		num1 = 1;
	if (output1[2] > output1[num1]) 
		num1 = 2;
	if (output1[3] > output1[num1]) 
		num1 = 3;
	num2 = 0;
	if (output2[1] > output2[num2])
		num2 = 1;
	if (output2[2] > output2[num2])
		num2 = 2;
	if (output2[3] > output2[num2])
		num2 = 3;
	num3 = 0;
	if (output3[1] > output3[num3])
		num3 = 1;
	if (output3[2] > output3[num3])
		num3 = 2;
	if (output3[3] > output3[num3])
		num3 = 3;


	if (num1 == num2 == num3)//三个神经网络输出结果一致
		num = num1;
	else if (num1 == num2)//有两个神经网络结果一致
		num = num1;
	else if (num1 == num3)
		num = num1;
	else if (num2 == num3)
		num = num2;
	else {            //三个神经网络结果都不一样，求三个神经网络的输出的和，重新评估
		output_sum[0] = output1[0] + output2[0]+ output3[0];
		output_sum[1] = output1[1] + output2[1]+ output3[1];
		output_sum[2] = output1[2] + output2[2]+ output3[2];
		output_sum[3] = output1[3] + output2[3]+ output3[3];
		num= 0;
		if (output_sum[1] > output_sum[num])
			num = 1;
		if (output_sum[2] > output_sum[num])
			num = 2;
		if (output_sum[3] > output_sum[num])
			num = 3;
	}

	switch (num)//输出识别结果
	{
	case 0:printf("识别结果为：苹果\n"); break;
	case 1:printf("识别结果为：西瓜\n"); break;
	case 2:printf("识别结果为：葡萄\n"); break;
	case 3:printf("识别结果为：香蕉\n"); break;
	default:
		break;
	}

	output_sum[0] = output1[0] + output2[0] + output3[0];
	output_sum[1] = output1[1] + output2[1] + output3[1];
	output_sum[2] = output1[2] + output2[2] + output3[2];
	output_sum[3] = output1[3] + output2[3] + output3[3];

	nump = 0;//假设0号输出是最大的
	numq = 2;//假设2号输出是第二大的
	if (output_sum[0] < output_sum[1]) {//对四个输出和进行归并排序
		temp = output_sum[0];
		output_sum[0] = output_sum[1];
		output_sum[1] = temp;
		nump = 1;
	}
	if (output_sum[2] < output_sum[3]) {
		temp = output_sum[2];
		output_sum[2] = output_sum[3];
		output_sum[3] = temp;
		numq = 3;
	}
	if (output_sum[0] < output_sum[2]) {
		temp = output_sum[0];
		output_sum[0] = output_sum[2];
		tem = nump;//暂时保存nump
		nump = numq;
		if (temp < output_sum[3]) {//前两个小于后两个
			output_sum[1] = output_sum[3];
			if (numq == 3)//如果交换过2号和3号输出
				numq = 2;
			else
				numq = 3;
		}
		else {
			output_sum[1] = temp;
			numq = tem;//判断第0、1号是否交换过
		}
	}
	else {
		if (output_sum[1] < output_sum[2]) {
			output_sum[1] = output_sum[2];
		}
		else {
			if (nump == 1)//如果交换过0号和1号输出
				numq = 0;
			if (nump == 0)
				numq = 1;
		}
	}

	//可能结果
	if (nump == num)//如果识别结果和num相同，则输出第二可能结果
		nump = numq;

	switch (nump)//输出可能识别结果
	{
	case 0:printf("可能结果为：苹果\n"); break;
	case 1:printf("可能结果为：西瓜\n"); break;
	case 2:printf("可能结果为：葡萄\n"); break;
	case 3:printf("可能结果为：香蕉\n"); break;
	default:
		break;
	}

	return 0;
}
