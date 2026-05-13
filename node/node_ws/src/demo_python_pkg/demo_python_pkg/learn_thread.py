import threading
import requests

class Download:
    def download(self, url, call_back_word_count):
        print(f'线程{threading.get_ident()} 开始下载{url}')
        response = requests.get(url)
        response.encoding = 'utf-8'
        call_back_word_count(url,response.text)

    def start_download(self, url, call_back_word_count):
        thread = threading.Thread(targets = self.download,
                                   args = (url, call_back_word_wount))
        thread.start()

def word_count(url, result):
    print(f"{url}:{len(result)}->{result[:5]}")

def main():
    download = Download()
    download.start_download('',word_count)
    download.start_download('',word_count)
    download.start_download('',word_count)