
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<fstream> // �ļ��� 

using namespace std;
int main()
{
	string quzhi(string a, string shengji, string shiji);

	string str, json, str1, str2, shengji, shiji; // ���ַ�������  
	int ai = 0, q = -1;
	//string json;

	shengji = "�ӱ�ʡ��ɽ��ʡ������ʡ������ʡ��������ʡ������ʡ���㽭ʡ������ʡ��";
	shengji = shengji + "����ʡ������ʡ��ɽ��ʡ������ʡ������ʡ������ʡ���㶫ʡ������ʡ���Ĵ�ʡ������ʡ��";
	shengji = shengji + "����ʡ������ʡ������ʡ���ຣʡ��̨��ʡ�����ɹ�������������׳�������������������������Ļ������������½�ά���������������ر��������������ر�������";

	shiji = "���ݡ����š�Ȫ�ݡ����ݡ����ҡ����¡������������ƽ���ϰ�����걡�����������������������ɽ����ƽ��ʯʨ�����������塢���������䡢���֡�����";
	ifstream inFile;
	infile.open(argc[1]); // ���ļ�   
	if (inFile.is_open())
	{ // ���ɹ����ļ�   
		while (!inFile.eof()) { // ��δ���ļ����� 

			getline(inFile, str, '\n'); // ��ȡһ�����ݣ������뻺��str�У�'\n'��ʾһ�н����Ļس���   
			if (str != "\0")
			{
				//json ƴ��
				q = str.find(",");
				if (q > -1)
				{
					str = str.substr(0, str.find("."));//ȥ��. 
				}
				if (ai == 0)
				{
					json += "[";
					json += quzhi(str, shengji, shiji);//�����и� 
				}
				else
				{
					json += ",\n" + quzhi(str, shengji, shiji);
				}
				ai++;

			}

		}
	}
	if (str != "\0")
	{
		//json ƴ��
		q = str.find(",");
		if (q > -1)
		{
			str = str.substr(0, str.find("."));//ȥ��. 
		}
		if (ai == 0)
		{
			json = "[";
			json += quzhi(str, shengji, shiji);//�����и� 
		}
		else
		{
			json += ",\n" + quzhi(str, shengji, shiji);
		}
		ai++;

	}


	if (ai > 0)
	{
		json = json + "]";

	}
	cout << json << endl;
	//}
//inFile.close();

//����json�ļ�

	ofstream outfile;
	outfile.open(argc[2]);
	std::string str((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());// �����ļ�   
	if (outFile.is_open())
	{ // ��������ɹ���������������   

		outFile << json << endl; // ��������ֱ��������������ȥ��OK��    

	}
	infile.close();
	outFile.close(); // �ر��ļ�   

	return 0;
}

string zdjq(string fg, string zd)
{
	string dz_jq = "";
	int q = -1;
	q = zd.find(fg);
	if (q > -1)
	{
		dz_jq = zd.substr(0, q + fg.length());//��ȡʡ 
		zd = zd.replace(0, q + fg.length(), "");//ɾ��ʡ 
	}
	return dz_jq;
}

string zdjq1(string fg, string zd)
{
	int q = -1;
	q = zd.find(fg);
	if (q > -1)
	{
		zd = zd.replace(0, q + fg.length(), "");//ɾ��ʡ 
	}
	return zd;
}

string quzhi(string a, string shengji, string shiji)
{
	string zdjq(string fg, string zd);
	string zdjq1(string fg, string zd);

	string c1, xm, dh, dz_s1, dz_s2, dz_s3, dz_s4, dz_s5, dz_s6, dz_s7, fg = ",", json, sj, sj1, m, s6_1;
	int s = 0, t, q, i, t1 = 0;

	t = 0;i = 0;
	q = a.find("!");
	if (q > -1)
	{

		m = a.substr(0, a.find("!"));
		a = a.replace(0, a.find("!") + 1, "");
		//cout<<"������"<<xm<<"   ";
	}
	else
	{
		q = a.find("��");
		if (q > -1)
		{

			m = a.substr(0, a.find("��"));
			a = a.replace(0, a.find("��") + 2, "");
			//cout<<"������"<<xm<<"   ";
		}
	}
	//ȡ���� 
	q = -1;
	q = a.find(",");
	if (q > -1)
	{

		xm = a.substr(0, a.find(","));//��ȡ���� 
		a = a.replace(0, a.find(",") + 1, "");//ɾ������  
	}
	else
	{
		q = a.find("��");
		if (q > -1)
		{
			//	q= a.find("��")��
			xm = a.substr(0, a.find("��"));//��ȡ���� 
			a = a.replace(0, a.find("��") + 2, "");//ɾ������  
			//cout<<"����1��"<<xm<<"   ";
		}
	}
	//ȡ�绰 
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
				c1 = a.substr(t1, t);//��ȡ��ַ 
				a = a.replace(t1, t, "");//ɾ����ַ�еĵ绰 
				break;
			}
			else
			{
				t = 0;
			}
		}
		i++;
	}


	//ȡ��ַ
	//һ�� ��ʡ �������� 
	fg = "ʡ";
	dz_s1 = zdjq(fg, a);
	a = zdjq1(fg, a);
	//cout<<"ʡ1��"<<dz_s1<<"   "<<"��ַ1��"<<a<<"   ";
	if ("" == dz_s1)
	{
		fg = "������";
		dz_s1 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s1)
		{
			fg = "�ر�������";
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
				dz_s1 = a.substr(0, sj.length()) + "ʡ";//��ȡʡ 
				a = a.replace(0, sj.length(), "");//ɾ��ʡ 
				break;
			}
			i++;
		}
	}


	//������ַ ���С������ݡ��ˡ����������� 

	fg = "��";
	dz_s2 = zdjq(fg, a);
	a = zdjq1(fg, a);

	if ("" == dz_s2)
	{
		fg = "������";
		dz_s2 = zdjq(fg, a);
		a = zdjq1(fg, a);

		if ("" == dz_s2)
		{
			fg = "��";
			dz_s2 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if ("" == dz_s2)
			{
				fg = "����";
				dz_s2 = zdjq(fg, a);
				a = zdjq1(fg, a);
				if ("" == dz_s2)
				{
					fg = "����";
					dz_s2 = zdjq(fg, a);
					a = zdjq1(fg, a);
				}
			}
		}
	}
	else
	{   //ֱϽ�� ��һ�� ��ֵ 
		q = -1;
		q = dz_s2.find("����");
		if (q > -1)
		{
			dz_s1 = "����";
		}
		else
		{
			q = dz_s2.find("����");
			if (q > -1)
			{
				dz_s1 = "����";
			}
			else
			{
				q = dz_s2.find("�Ϻ�");
				if (q > -1)
				{
					dz_s1 = "�Ϻ�";
				}
				else
				{
					q = dz_s2.find("���");
					if (q > -1)
					{
						dz_s1 = "���";
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
				dz_s2 = a.substr(0, sj1.length()) + "��";//��ȡ�� 
				a = a.replace(0, sj1.length(), "");//ɾ���� 
				break;
			}
			i++;
		}
	}



	//������ַ �ؼ���|��|��|��

	fg = "��";
	dz_s3 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if ("" == dz_s3)
	{
		fg = "��";
		dz_s3 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s3)
		{
			fg = "��";
			dz_s3 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if ("" == dz_s3)
			{
				fg = "��";
				dz_s3 = zdjq(fg, a);
				a = zdjq1(fg, a);
			}
		}
	}

	//�ļ���ַ �ֵ�|�� |�� 

	fg = "��";
	dz_s4 = zdjq(fg, a);
	a = zdjq1(fg, a);
	if ("" == dz_s4)
	{
		fg = "��";
		dz_s4 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s4)
		{

			fg = "�ֵ�";
			dz_s4 = zdjq(fg, a);
			a = zdjq1(fg, a);
		}
	}

	if ("1" == m)
	{
		//5����ַ

		dz_s5 = a;
		json = "{\"����\":\"" + xm + "\",\"�ֻ�\":\"" + c1 + "\",\"��ַ\":[\"" + dz_s1 + "\",\"" + dz_s2 + "\",\"" + dz_s3 + "\",\"" + dz_s4 + "\",\"" + dz_s5 + "\"]}";

	}
	else
	{
		//5����ַ ��|�� |��|· 

		fg = "�ֵ�";
		dz_s5 = zdjq(fg, a);
		a = zdjq1(fg, a);
		if ("" == dz_s5)
		{
			fg = "��";
			dz_s5 = zdjq(fg, a);
			a = zdjq1(fg, a);
			if ("" == dz_s5)
			{

				fg = "��";
				dz_s5 = zdjq(fg, a);
				a = zdjq1(fg, a);
				if ("" == dz_s5)
				{
					fg = "·";
					dz_s5 = zdjq(fg, a);
					a = zdjq1(fg, a);
					if ("" == dz_s5)
					{
						fg = "��";
						dz_s5 = zdjq(fg, a);
						a = zdjq1(fg, a);
					}
				}
			}
		}

		//6����ַ
		fg = "��";
		dz_s6 = zdjq(fg, a);
		a = zdjq1(fg, a);

		q = -1;
		q = a.find(".");
		if (q > -1)
		{
			a = a.substr(0, a.find("."));//ȥ��. 
		}
		dz_s7 = a;

		json = "{\"����\":\"" + xm + "\",\"�ֻ�\":\"" + c1 + "\",\"��ַ\":[\"" + dz_s1 + "\",\"" + dz_s2 + "\",\"" + dz_s3 + "\",\"" + dz_s4 + "\",\"" + dz_s5 + "\",\"" + dz_s6 + "\",\"" + dz_s7 + "\"]}";

	}

	return json;

}

