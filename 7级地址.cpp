#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<fstream> // 文件流 

using namespace std;
int main()
{

	string quzhi(string a, string shengji, string shiji);

	string str, json, str1, str2, shengji, shiji; // 行字符串缓存  
	int ai = 0, q = -1;
	//string json;

	ifstream inFile;
	//读取 全国省份 
	inFile.open("d://shengji.txt");
	while (!inFile.eof()) {
		getline(inFile, str1, '\n'); // 读取一行内容，并存入缓存str中，'\n'表示一行结束的回车符   
		if (str1 != "\0")
		{
			shengji += str1;

		}
	}
	//cout << shengji << endl;
	inFile.close();


	//读取 全国市
	inFile.open("d://shiji.txt");
	while (!inFile.eof()) {
		getline(inFile, str2, '\n'); // 读取一行内容，并存入缓存str中，'\n'表示一行结束的回车符   
		if (str2 != "\0")
		{
			shiji += str2;

		}
	}
	//cout << shengji << endl;
	inFile.close();


	inFile.open("d://test.txt"); // 打开文件   

	if (inFile.is_open()) { // 若成功打开文件   
		cout << "损坏的地址簿：" << endl;
		while (!inFile.eof()) { // 若未到文件结束 

			getline(inFile, str, '\n'); // 读取一行内容，并存入缓存str中，'\n'表示一行结束的回车符   
			if (str != "\0")
			{
				//json 拼接

				if (ai == 0)
				{
					json += "[";
					json += quzhi(str, shengji, shiji);//数据切割 
				}
				else
				{
					json += ",\n" + quzhi(str, shengji, shiji);
				}
				ai++;

			}
			cout << str << endl; // 把缓存内容输出到屏幕 

		}
		cout << "保存的内容：" << endl;

		if (ai > 0)
		{
			json = json + "]";

		}
		cout << json << endl;
	}
	inFile.close();

	//保存json文件

	ofstream outFile;
	outFile.open("d://test2.json"); // 创建文件   
	if (outFile.is_open()) { // 如果创建成功，填入两行内容   

		outFile << json << endl; // 输入数字直接这样”流“进去就OK了    

	}
	outFile.close(); // 关闭文件   
	system("pause");
	return 0;
}

string zdjq(string fg, string zd)
{
	string dz_jq = "";
	int q = -1;
	q = zd.find(fg);
	if (q > -1)
	{
		dz_jq = zd.substr(0, q + fg.length());//获取省 
		zd = zd.replace(0, q + fg.length(), "");//删掉省 
	   //cout<<"省："<<dz_s1<<"   ";
	}
	return dz_jq;
}

string zdjq1(string fg, string zd)
{
	int q = -1;
	q = zd.find(fg);
	if (q > -1)
	{
		zd = zd.replace(0, q + fg.length(), "");//删掉省 
	   //cout<<"省："<<dz_s1<<"   ";
	}
	return zd;
}

string quzhi(string a, string shengji, string shiji)
{
	string zdjq(string fg, string zd);
	string zdjq1(string fg, string zd);

	string c1, xm, dh, dz_s1, dz_s2, dz_s3, dz_s4, dz_s5, dz_s6, dz_s7, fg = ",", json, sj, sj1;
	string s6_1, s6_2;
	int s = 0, t, q, i, t1 = 0, t2 = -1, m = 0;

	//	cin>>a;
	t = 0;i = 0;

	//取姓名 
	q = a.find(",");
	if (q > -1)
	{
		//	q= a.find(",")；
	   // cout<<a.find(",")<<"   ";
		xm = a.substr(0, a.find(","));//获取姓名 
		a = a.replace(0, a.find(",") + 1, "");//删掉姓名  
	   //cout<<"姓名："<<xm<<"   ";
	}
	else
	{
		q = a.find("，");
		if (q > -1)
		{
			//	q= a.find("，")；
			xm = a.substr(0, a.find("，"));//获取姓名 
			a = a.replace(0, a.find("，") + 2, "");//删掉姓名  
			//cout<<"姓名1："<<xm<<"   ";
		}
	}
	//取电话 
	while (a[i] != '.')
	{
		if (a[i] >= '0'&&a[i] <= '9')
		{
			if (t == 0)
			{
				t1 = i;

			}
			//c[t]=a[i];
			t++;
		}
		else
		{
			if (t > 6)
			{
				c1 = a.substr(t1, t);//获取地址 
				a = a.replace(t1, t, "");//删掉地址中的电话 
		 //	cout<<c1<<"  截取前地址： "<< a;
				break;
			}
			else
			{
				//	c[0]='\0';
				t = 0;
			}
		}
		i++;
	}


	//取地址
	//一级 ：省 、自治区 
	fg = "省";
	dz_s1 = zdjq(fg, a);
	a = zdjq1(fg, a);
	//cout<<"省1："<<dz_s1<<"   "<<"地址1："<<a<<"   ";
	if ("" == dz_s1)
	{
		fg = "自治区";
		dz_s1 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s1)
		{
			fg = "特别行政区";
			dz_s1 = zdjq(fg, a);
			a = zdjq1(fg, a);
		}
	}

	if ("" == dz_s1)
	{
		for (unsigned int i = 4;i < a.length();i++)
		{
			sj = a.substr(0, i);
			q = -1;
			q = shengji.find(sj);
			//cout<< "  shengji:"<<sj <<"   "<<q  ;
			if (q > -1)
			{
				dz_s1 = a.substr(0, sj.length()) + "省";//获取省 
				a = a.replace(0, sj.length(), "");//删掉省 
				break;
			}
			i++;
		}
	}


	//二级地址 ：市、自治州、盟、地区、划区 

	fg = "市";
	dz_s2 = zdjq(fg, a);
	a = zdjq1(fg, a);

	if ("" == dz_s2)
	{
		fg = "自治州";
		dz_s2 = zdjq(fg, a);
		a = zdjq1(fg, a);

		if ("" == dz_s2)
		{
			fg = "盟";
			dz_s2 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if ("" == dz_s2)
			{
				fg = "地区";
				dz_s2 = zdjq(fg, a);
				a = zdjq1(fg, a);
				if ("" == dz_s2)
				{
					fg = "区划";
					dz_s2 = zdjq(fg, a);
					a = zdjq1(fg, a);
				}
			}
		}
	}
	else
	{   //直辖市 的一级 赋值 
		q = -1;
		q = dz_s2.find("北京");
		if (q > -1)
		{
			dz_s1 = "北京";
		}
		else
		{
			q = dz_s2.find("重庆");
			if (q > -1)
			{
				dz_s1 = "重庆";
			}
			else
			{
				q = dz_s2.find("上海");
				if (q > -1)
				{
					dz_s1 = "上海";
				}
				else
				{
					q = dz_s2.find("天津");
					if (q > -1)
					{
						dz_s1 = "天津";
					}
				}
			}
		}

	}

	if ("" == dz_s2)
	{
		for (unsigned int i = 4;i < a.length();i++)
		{
			sj1 = a.substr(0, i);
			q = -1;
			q = shiji.find(sj1);
			//cout<< "  shengji:"<<sj <<"   "<<q  ;
			if (q > -1)
			{
				dz_s2 = a.substr(0, sj1.length()) + "市";//获取市 
				a = a.replace(0, sj1.length(), "");//删掉市 
				break;
			}
			i++;
		}
	}



	//三级地址 县级市|县|旗|区

	fg = "县";
	dz_s3 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if ("" == dz_s3)
	{
		fg = "区";
		dz_s3 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s3)
		{
			fg = "旗";
			dz_s3 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if ("" == dz_s3)
			{
				fg = "市";
				dz_s3 = zdjq(fg, a);
				a = zdjq1(fg, a);
			}
		}
	}

	//四级地址 区|镇 |乡 

	fg = "镇";
	dz_s4 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if ("" == dz_s4)
	{
		fg = "乡";
		dz_s4 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s4)
		{

			fg = "街道";
			dz_s4 = zdjq(fg, a);
			a = zdjq1(fg, a);
		}
	}

	//5级地址 街|道 |巷|路 


	fg = "街";
	dz_s5 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if ("" == dz_s5)
	{

		fg = "巷";
		dz_s5 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s5)
		{
			fg = "路";
			dz_s5 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if ("" == dz_s5)
			{
				fg = "道";
				dz_s5 = zdjq(fg, a);
				a = zdjq1(fg, a);
			}
		}
	}


	//6级地址
	fg = "号";
	dz_s6 = zdjq(fg, a);
	a = zdjq1(fg, a);


	q = -1;
	q = a.find(".");
	if (q > -1)
	{
		a = a.substr(0, a.find("."));//去除. 
	}
	dz_s7 = a;

	json = "{\"姓名\":\"" + xm + "\",\"手机\":\"" + c1 + "\",\"地址\":[\"" + dz_s1 + "\",\"" + dz_s2 + "\",\"" + dz_s3 + "\",\"" + dz_s4 + "\",\"" + dz_s5 + "\",\"" + dz_s6 + "\",\"" + dz_s7 + "\"]}";

	return json;

}