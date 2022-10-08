#pragma once
#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

//int main()
//{
	//// 建议：
	//// 1、C++尽量去用cin和cout，能用它就用他
	//// 2、用cout和cin不方便的地方，再去用scanf和printf
	//double a = 1.0 / 3.0;
	//printf("%.3f\n", a);
	//cout << setprecision(4) << a << endl;
	
	//string str;
	//cin >> str;
	//cout << str<<endl;
	//cin >> str;
	//cout << str<<endl;
	//getline(cin,str);//获取字符串直到换行
	//cout << str<<endl;

	//有些oj需要多组测试，要求持续输出
	// ctrl+c结束
	//C++
	//string str;
	//while (cin >> str)
	//{
	//	cout << str << endl;
	//	//...
	//}
	////C语言
	//char buf[100];
	//while(scanf("%s", buf) != EOF)
	//{
	//	printf("%s\n", buf);
	//	//...
	//}
	//return 0;
//}

//struct ServerInfo
//{
//	char _ip[20];
//	int  _port;
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_filename(filename)
//	{}
//
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		ifs.read((char*)&info, sizeof(info));
//	}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename);
//		ofs.write((char*)&info, sizeof(info));
//	}
//
//	void WriteTxt(const ServerInfo& info)
//	{
//		/*ofstream ofs(_filename);
//		ofs.write(info._ip, strlen(info._ip));
//		ofs.put('\n');
//		string portstr = to_string(info._port);
//		ofs.write(portstr.c_str(), portstr.size());*/
//
//		// C++流多提供的，其他的c一样都可以实现
//		ofstream ofs(_filename);
//		ofs << info._ip << "\n" << info._port;
//	}
//
//	void ReadTxt(ServerInfo& info)
//	{
//		//ifstream ifs(_filename);
//		//ifs.getline(info._ip, 20);
//		//// 
//		//char portbuff[20];
//		//ifs.getline(portbuff, 20);
//		//info._port = stoi(portbuff);
//
//		// C++流多提供的，其他的c一样都可以实现
//		ifstream ifs(_filename);
//		ifs >> info._ip >> info._port;
//	}
//
//private:
//	string _filename;
//};

//int main()
//{
//	ServerInfo rinfo;
//	ServerInfo winfo = {"192.0.0.1", 8000};
//	// 读写 -- 二进制  -- 读写简单、高效快捷。 缺点：除了字符和字符串，内存中写到文件，是乱码
//	/*ConfigManager cfbin("config.bin");
//	cfbin.WriteBin(winfo);*/
//	//ConfigManager cfbin("config.bin");
//	//cfbin.ReadBin(rinfo);
//
//	// 读写 -- 文本
//	//ConfigManager cftxt("config.txt");
//	//cftxt.WriteTxt(winfo);
//
//	ConfigManager cftxt("config.txt");
//	cftxt.WriteTxt(rinfo);
//	cftxt.ReadTxt(rinfo);
//	return 0;
//}


//struct ServerInfo
//{
//	char _ip[20];
//	int  _port;
//};
//int main()
//{
//	ServerInfo info = { "192.0.0.1", 8000 };
//	//char buff[128];
//	//// 序列化
//	//sprintf(buff, "%s %d", info._ip, info._port);
//
//	//// 反序列化
//	//ServerInfo rinfo;
//	//sscanf(buff, "%s%d", rinfo._ip, &rinfo._port);
//
//	//stringstream ssm;
//	/*ssm << info._ip <<" "<<info._port;
//	string buff = ssm.str();*/
//
//	/*stringstream ssm;
//	ssm.str("127.0.0.1 90");*/
//
//	/*stringstream ssm("127.0.0.1 90");
//	ServerInfo rinfo;
//	ssm >> rinfo._ip >> rinfo._port;*/
//	return 0;
//}