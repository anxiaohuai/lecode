#include<iostream>
#include<mutex>
#include<thread>
#include<string>
#include <condition_variable>
using namespace std;
 
//预处理
#define MAX 10//缓冲池的最大数量
//全局变量的定义
mutex m;//建立一个互斥信号量m
condition_variable full_con;//如果某时刻缓冲池为满，那么就让full_con等待
condition_variable empty_con;//如果某时刻缓冲池为空，那么就让empty等待
string buffer[MAX];//建立一个最大数量为MAX的缓冲池,此缓冲池采用循环队列的形式
int pro_num = 0;//用pro_num来记录生产者在缓冲池的当前位置
int con_num = 0;//用con_num来记录消费者在缓冲池的当前位置
int pro_index = 0;//用index来记录现在是第几个被生产者生产的产品
 
//生产者类
class producer{
private:
	string in;//生产的产品
	int index;//用来标记现在是第几个生产者
	
public:
	producer( string in = "", int index = 0 ) : in( in ), index( index ){
	} 
	~producer( ) = default;
	void produce( );
};
 
class consumer{
private:
	string out;//消费的产品
	int index;//用来标记现在是第几个消费者
public:
	consumer( string out = "", int index = 0 ) : out( out ), index( index ){
	}
	~consumer( ) = default;
	void consume( );//消费产品
};

//生产产品函数的实现
void producer::produce( ){
		in = "生产者“" + to_string( this->index ) + "”生产的产品" + to_string( pro_index++ );//生产的产品
		unique_lock lock(m);//锁住互斥变量m,避免消费者动用缓冲池buffer
		while(( pro_num + 1 ) % MAX == con_num ){//判断缓冲池已满
			cout << "缓冲池已满!!  生产者“" << index << "”在等待一个空位" << endl;
			full_con.wait( lock );//让full进入等待状态
		}
		buffer[pro_num] = in;//将生产者生产的产品放入缓冲池
		pro_num = ( pro_num +1 ) % MAX;
		cout << in << endl;	
		empty_con.notify_all();//唤起empty	
}
 
//消费产品函数的实现
void consumer::consume(){
		unique_lock lock( m );//锁住互斥变量m，避免生产者动用缓冲池buffer
		while( pro_num == con_num ){//判断缓冲池为空
			cout << "缓冲池为空!!  消费者“" << index << "”在等待一件产品" << endl;
			empty_con.wait( lock );
		}
		out = "消费者“" + to_string( this->index ) + "”消费了" + buffer[con_num];//消费者消费的产品
		con_num = ( con_num + 1 ) % MAX;//将生产者生产的产品从缓冲池取出
		cout << out << endl;	
		full_con.notify_all();//唤起full
}
//定义了一个函数，让生产者生产50次产品
void producer_work( producer p ) {
	int i = 0;
	while( i < 50 ){
		p.produce( );
		i++;
	}
}
 
//定义了一个函数，让消费者消费50次产品	
void consumer_work( consumer c ){
	int i = 0;
	while( i < 50 ){
		c.consume( );
		i++;
	}
}
  
int main( void ){
	producer p;
	consumer c;
	thread pro( producer_work, p );
	thread con( consumer_work, c);
	pro.join( );
	con.join( );
	return 0;
}