#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include<fstream>
#include <string>

#include <dirent.h>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
 //marcin matysek rewertyn
    ofstream plik1;
    plik1.open("11.txt");
    ifstream plik2;
    int flag=0;
    string tab[1000];
    string tab2[200];


//https://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c
//source: https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("C:\\Users\\mar\\Desktop\\1\\5\\")) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
            if(flag>2)
            {
            printf ("%s\n", ent->d_name);
            plik1<<ent->d_name<<endl;
            }
            flag++;
      }
      closedir (dir);
    } else {
      /* could not open directory */
      perror ("");
      return EXIT_FAILURE;
    }
    plik1.close();
    plik2.open("11.txt",ios::binary);
    char* temp6 = new char[40*sizeof(char)]; // tymczasowy bufor na dane
    for(int j=0;j<40;j++)
    {
        temp6[j]='\0';
    }
    char* temp5 = new char[sizeof(char)]; // tymczasowy bufor na dane
    int licz2=0;

    system("pause");
    int i3=0;
    if( plik2.good() )//plik2.good()
    {
        //cout<<"plik2.good()"<<plik2.good()<<endl;

        while( !plik2.eof() )
        {
            //cout<<"!plik2.eof()"<<!plik2.eof()<<endl;
            licz2=0;
            for(int i2=0;i2<100;i2++)
            {
            plik2.read(temp5, sizeof(char));
            licz2++;
            //cout<<temp5[0]<<" "<<endl;
            if(temp5[0]==13){plik2.seekg(-(licz2),ios_base::cur);
            //cout<<(int)temp5[0]<<" "<<licz2<<endl;system("pause");
            break;}
            //bo niektore coiny sa zapisane bez spacji np Bitcoin Cash
            }
            for(int j=0;j<40;j++)
            {
                temp6[j]='\0';
            }

            plik2.read(temp6, (licz2-1)*sizeof(char));
            plik2.read(temp5, sizeof(char));
            //cout<<" m "<<(int)temp5[0]<<" y "<<endl;
            plik2.read(temp5, sizeof(char));
            //cout<<" m "<<(int)temp5[0]<<" y "<<endl;
            //cout<<temp6<<" p "<<endl;
            tab2[i3]=temp6;

            tab[i3]="C:\\Users\\mar\\Desktop\\1\\5\\" + tab2[i3] + "\\";
            //cout<<" m "<<tab[i3]<<" y "<<endl;
            cout<<tab[i3]<<endl;
            i3++;
            //system("pause");
        }
    }
    system("pause");

    plik2.close();
    ofstream plik3;
    plik3.open("12.txt");
    int flag3=0;
    DIR *dir2;
    struct dirent *ent2;

    for(int i5=0;i5<i3-2;i5++)
     {flag3=0;
    if ((dir2 = opendir (tab[i5].c_str())) != NULL) {
      /* print all the files and directories within directory */
      while ((ent2 = readdir (dir2)) != NULL) {
            if(flag3>1)
            {
            printf ("%s\n", ent2->d_name);
            plik3<<ent2->d_name<<endl;
            }
            flag3++;
      }
      closedir (dir2);
    } else {
      /* could not open directory */
      perror ("");
      return EXIT_FAILURE;
    }
    }
    plik3.close();
    system("pause");
    return 0;
}
