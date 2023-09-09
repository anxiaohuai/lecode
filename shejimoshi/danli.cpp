
Singleton* Singleton::m_pInstance = nullptr;
std::mutex Singleton::m_mutex;
class Singleton
{
private:
 	Singleton(){};
    ~Singleton() {};// 私有化 可以避免 直接 delete s1 ，必须 使用 delInstance
    Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;
    static Singleton* m_pInstance;
    static std::mutex m_mutex;
public:  
  	static Singleton* getInstance() {
        //第一个检查，如果只是读操作，就不许用加锁
        if (m_pInstance == nullptr) {
            std::lock_guard<std::mutex> lck(m_mutex);
            //第二个检查，保证只有一个
            if (m_pInstance == nullptr) {
                //这条语句实际上做了三件事，第一件事申请一块内存，第二件事调用构造函数，第三件是将该内存地址赋给instance_。
                m_pInstance = new Singleton;
            }
        }
        return m_pInstance;
    }
    static void delInstance(){ // 为了多线程安全，释放操作也要做 double-check
    	if(m_pInstance != nullptr) 
    	{
    		std::lock_guard<std::mutex> lck(m_mutex);
    		if(m_pInstance != nullptr) 
    		{
            	delete m_pInstance;
            	m_pInstance = nullptr;
        	}
    	}        
    };

};  
