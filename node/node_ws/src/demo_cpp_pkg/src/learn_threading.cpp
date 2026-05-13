#include <iostream>
#include <thread>
#include <chrono>
#include <functional>
#include "cpp-httplib/httplib.h"
#include <string>
using namespace std;

class Download
{
public:
    void download(const string& host, const string& path, const std::function<void(const 
        string&, const string&)>&callback_word_count)
        {
            cout << std::this_thread::get_id() << endl;
            httplib::Client client(host);
            auto response = client.Get(path);
            if(response && response->status == 200){
                callback_word_count(path,result->body);
            }
        };
    void start_download(const string& host, const string& path, const function<void(const 
        string&, const string&)>&callback_word_count)
        {
            auto download_fun = bind(&Download::start_download,this,
            placeholders::_1,placeholders::_2,placeholders::_3);
            std::thread thread(download_fun,host,path,callback_word_count);
            thread.detach();
        };
}

int main()
{
    auto d = Download();
    auto word_count = [](const string& path, const string& result) ->void{
        cout << path << result.length() << result.substr(0,5) << endl;
    };
    d.start_download("","",word_count);
    d.start_download("","",word_count);
    d.start_download("","",word_count);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000*10));

    return 0;

}