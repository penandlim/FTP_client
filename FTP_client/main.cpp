#define CURL_STATICLIB
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <windows.h>
#include "main.h"
#include <conio.h>

using namespace std;

std::string publicip;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char ** argv)
{
	SetConsoleTitle( TEXT("LOLOLOL your le computer is getting hacked by le anonymoose XD (wow such troll)"));

     CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = "https://dl.dropboxusercontent.com/u/15599824/FTP-Server/ip.txt";
    char outfilename[FILENAME_MAX] = "ip.txt";
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }

	Sleep(1000);
	std::ifstream publicipstream("ip.txt");
	getline(publicipstream, publicip);
	ClearScreen();
	cout <<"Target : " << publicip << " (Weaboo Library)" << endl;

	std::string ftpstatus;

	for (int i = 0; i < 10; i++)
	{
		Sleep(80);
        std::cout << "\r\b\\ Connecting" << std::flush;
        Sleep(80);
        std::cout << "\r\b| Connecting" << std::flush;
        Sleep(80);
        std::cout << "\r\b/ Connecting" << std::flush;
        Sleep(80);
        std::cout << "\r\b- Connecting" << std::flush;
		if(i==9)
			std::cout << "\r| Connecting";
		for (int j = 0; j < i; j++)
		{
			std::cout << ".";
		}
	}

	sf::Ftp ftpcheck;
	sf::Ftp::Response response = ftpcheck.connect(publicip,13372, sf::seconds(5));
	if (response.isOk())
	{
		ftpstatus = " Connected :)";
	}
	else
	{
		ftpstatus = " Connection Failed :(";
	}
	std::cout << ftpstatus;

	Sleep(3000);

	int i;
	i = _getch();
	return 0;

}
