

#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<fstream> // 文件流 
#include <codecvt>
#include<iostream>
using namespace std;


string UnicodeToUTF8(wstring  wstr)
{
	string ret;
	try {
		wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
		ret = wcv.to_bytes(wstr);
	}
	catch (const std::exception & e) {
		cerr << e.what() << std::endl;
	}
	return ret;
}

wstring UTF8ToUnicode(string  str)
{
	std::wstring ret;
	try {
		std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
		ret = wcv.from_bytes(str);
	}
	catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

int main(int argv, char** argc)
{
	wstring quzhi(wstring a, wstring shengji, wstring shiji);
	string UnicodeToUTF8(wstring  wstr);
	wstring UTF8ToUnicode(string  str);

	wstring  str, json, str1, str2, shengji, shiji, h; // 行字符串缓存  
	int ai = 0, q = -1;

	string str3;
	string json1;

	shengji = L"河北省，山西省，辽宁省，吉林省，黑龙江省，江苏省，浙江省，安徽省，";
	shengji = shengji + L"福建省，江西省，山东省，河南省，湖北省，湖南省，广东省，海南省，四川省，贵州省，";
	shengji = shengji + L"云南省，陕西省，甘肃省，青海省，台湾省，内蒙古自治区，广西壮族自治区，西藏自治区，宁夏回族自治区，新疆维吾尔自治区，香港特别行政区，澳门特别行政区";

	shiji = L"福州、厦门、泉州、漳州、龙岩、宁德、莆田、三明、南平、南安、建瓯、建阳、永安、晋江、武夷山、漳平、石狮、福安、福清、福鼎、邵武、长乐、龙海";

	if (argv < 3) return 0;
	ifstream inFile;
	inFile.open("d://1.txt"); // 打开文件   
	if (inFile.is_open())
	{ // 若成功打开文件   
		while (!inFile.eof()) { // 若未到文件结束 

			getline(inFile, str3, '\n'); // 读取一行内容，并存入缓存str中，'\n'表示一行结束的回车符 

			str = UTF8ToUnicode(str3);
			if (str != L"\0")
			{
				//json 拼接
				q = str.find(L",");
				if (q > -1)
				{
					str = str.substr(0, str.find(L"."));//去除. 
				}
				if (ai == 0)
				{
					json += L"[";
					h = quzhi(str, shengji, shiji);
					json = json + h;//数据切割 
				}
				else
				{
					json = json + L",\n" + quzhi(str, shengji, shiji);
				}
				ai++;

			}

		}
	}
	if (str != L"\0")
	{
		//json 拼接
		q = str.find(L",");
		if (q > -1)
		{
			str = str.substr(0, str.find(L"."));//去除. 
		}
		if (ai == 0)
		{
			json = L"[";
			json += quzhi(str, shengji, shiji);
		}
		else
		{
			json = json + L",\n" + quzhi(str, shengji, shiji);
		}
		ai++;

	}


	if (ai > 0)
	{
		json = json + L"]";

	}
	json1 = UnicodeToUTF8(json);

	cout << json1 << endl;
	//}
	inFile.close();

	//保存json文件

	ofstream outFile;
	outFile.open("d://2.txt"); // 创建文件   
	if (outFile.is_open())
	{ // 如果创建成功，填入两行内容   

		outFile << json1 << endl; // 输入数字直接这样”流“进去就OK了    

	}
	inFile.close();
	outFile.close(); // 关闭文件   

}

wstring zdjq(wstring fg, wstring zd)
{
	wstring dz_jq = L"";
	int q = -1;
	q = zd.find(fg);
	if (q > -1)
	{
		dz_jq = zd.substr(0, q + fg.length());//获取省 
		zd = zd.replace(0, q + fg.length(), L"");//删掉省 
	}
	return dz_jq;
}

wstring zdjq1(wstring fg, wstring zd)
{
	int q = -1;
	q = zd.find(fg);
	if (q > -1)
	{
		zd = zd.replace(0, q + fg.length(), L"");//删掉省 
	}
	return zd;
}

wstring quzhi(wstring a, wstring shengji, wstring shiji)
{
	wstring zdjq(wstring fg, wstring zd);
	wstring zdjq1(wstring fg, wstring zd);

	wstring c1, xm, dh, dz_s1, dz_s2, dz_s3, dz_s4, dz_s5, dz_s6, dz_s7, fg = L",", json, sj, sj1, m, s6_1;
	int s = 0, t, q, i, t1 = 0;

	t = 0;i = 0;
	q = a.find(L"!");

	if (q > -1)
	{

		m = a.substr(0, a.find(L"!"));
		a = a.replace(0, a.find(L"!") + 1, L"");
		//cout<<"姓名："<<xm<<"   ";
	}
	else
	{
		q = a.find(L"！");
		if (q > -1)
		{

			m = a.substr(0, a.find(L"！"));
			a = a.replace(0, a.find(L"！") + 2, L"");
			//cout<<"姓名："<<xm<<"   ";
		}
	}
	//取姓名 
	q = -1;
	q = a.find(L",");
	if (q > -1)
	{

		xm = a.substr(0, a.find(L","));//获取姓名 
		a = a.replace(0, a.find(L",") + 1, L"");//删掉姓名  
	}
	else
	{
		q = a.find(L"，");
		if (q > -1)
		{
			xm = a.substr(0, a.find(L"，"));//获取姓名 
			a = a.replace(0, a.find(L"，") + 2, L"");//删掉姓名  
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
			t++;
		}
		else
		{
			if (t > 6)
			{
				c1 = a.substr(t1, t);//获取地址 
				a = a.replace(t1, t, L"");//删掉地址中的电话 
				break;
			}
			else
			{
				t = 0;
			}
		}
		i++;
	}


	//取地址
	//一级 ：省 、自治区 
	fg = L"省";
	dz_s1 = zdjq(fg, a);
	a = zdjq1(fg, a);
	//cout<<"省1："<<dz_s1<<"   "<<"地址1："<<a<<"   ";
	if (L"" == dz_s1)
	{
		fg = L"自治区";
		dz_s1 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if (L"" == dz_s1)
		{
			fg = L"特别行政区";
			dz_s1 = zdjq(fg, a);
			a = zdjq1(fg, a);
		}
	}

	if (L"" == dz_s1)
	{
		for (unsigned int i = 4;i < a.length();i++)
		{
			sj = a.substr(0, i);
			q = -1;
			q = shengji.find(sj);
			//cout<< "  shengji:"<<sj <<"   "<<q  ;
			if (q > -1)
			{
				dz_s1 = a.substr(0, sj.length()) + L"省";//获取省 
				a = a.replace(0, sj.length(), L"");//删掉省 
				break;
			}
			i++;
		}
	}


	//二级地址 ：市、自治州、盟、地区、划区 

	fg = L"市";
	dz_s2 = zdjq(fg, a);
	a = zdjq1(fg, a);

	if (L"" == dz_s2)
	{
		fg = L"自治州";
		dz_s2 = zdjq(fg, a);
		a = zdjq1(fg, a);

		if (L"" == dz_s2)
		{
			fg = L"盟";
			dz_s2 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if (L"" == dz_s2)
			{
				fg = L"地区";
				dz_s2 = zdjq(fg, a);
				a = zdjq1(fg, a);
				if (L"" == dz_s2)
				{
					fg = L"区划";
					dz_s2 = zdjq(fg, a);
					a = zdjq1(fg, a);
				}
			}
		}
	}
	else
	{   //直辖市 的一级 赋值 
		q = -1;
		q = dz_s2.find(L"北京");
		if (q > -1)
		{
			dz_s1 = L"北京";
		}
		else
		{
			q = dz_s2.find(L"重庆");
			if (q > -1)
			{
				dz_s1 = L"重庆";
			}
			else
			{
				q = dz_s2.find(L"上海");
				if (q > -1)
				{
					dz_s1 = L"上海";
				}
				else
				{
					q = dz_s2.find(L"天津");
					if (q > -1)
					{
						dz_s1 = L"天津";
					}
				}
			}
		}

	}

	if (L"" == dz_s2)
	{
		for (unsigned int i = 4;i < a.length();i++)
		{
			sj1 = a.substr(0, i);
			q = -1;
			q = shiji.find(sj1);
			//cout<< "  shengji:"<<sj <<"   "<<q  ;
			if (q > -1)
			{
				dz_s2 = a.substr(0, sj1.length()) + L"市";//获取市 
				a = a.replace(0, sj1.length(), L"");//删掉市 
				break;
			}
			i++;
		}
	}



	//三级地址 县级市|县|旗|区

	fg = L"县";
	dz_s3 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if (L"" == dz_s3)
	{
		fg = L"区";
		dz_s3 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if (L"" == dz_s3)
		{
			fg = L"旗";
			dz_s3 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if (L"" == dz_s3)
			{
				fg = L"市";
				dz_s3 = zdjq(fg, a);
				a = zdjq1(fg, a);
			}
		}
	}

	//四级地址 街道|镇 |乡 

	fg = L"镇";
	dz_s4 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if (L"" == dz_s4)
	{
		fg = L"乡";
		dz_s4 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if (L"" == dz_s4)
		{

			fg = L"街道";
			dz_s4 = zdjq(fg, a);
			a = zdjq1(fg, a);
		}
	}

	if (L"1" == m)
	{
		//5级地址

		dz_s5 = a;
		json = L"{\"姓名\":\"" + xm + L"\",\"手机\":\"" + c1 + L"\",\"地址\":[\"" + dz_s1 + L"\",\"" + dz_s2 + L"\",\"" + dz_s3 + L"\",\"" + dz_s4 + L"\",\"" + dz_s5 + L"\"]}";

	}
	else
	{
		//5级地址 街|道 |巷|路 

		fg = L"街道";
		dz_s5 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if (L"" == dz_s5)
		{
			fg = L"街";
			dz_s5 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if (L"" == dz_s5)
			{

				fg = L"巷";
				dz_s5 = zdjq(fg, a);
				a = zdjq1(fg, a);
				if (L"" == dz_s5)
				{
					fg = L"路";
					dz_s5 = zdjq(fg, a);
					a = zdjq1(fg, a);
					if (L"" == dz_s5)
					{
						fg = L"道";
						dz_s5 = zdjq(fg, a);
						a = zdjq1(fg, a);
					}
				}
			}
		}

		//6级地址
		fg = L"号";
		dz_s6 = zdjq(fg, a);
		a = zdjq1(fg, a);

		q = -1;
		q = a.find(L".");
		if (q > -1)
		{
			a = a.substr(0, a.find(L"."));//去除. 
		}
		dz_s7 = a;

		json = L"{\"姓名\":\"" + xm + L"\",\"手机\":\"" + c1 + L"\",\"地址\":[\"" + dz_s1 + L"\",\"" + dz_s2 + L"\",\"" + dz_s3 + L"\",\"" + dz_s4 + L"\",\"" + dz_s5 + L"\",\"" + dz_s6 + L"\",\"" + dz_s7 + L"\"]}";

	}

	return json;

}

