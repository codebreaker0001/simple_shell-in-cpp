#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <cstring>

using namespace std;

bool executeBuiltin(vector<string> arg)
{

    if (arg.empty())
        return 0;

    if (arg[0] == "exit")
    {
        int exitCode = (arg.size() > 1 && isdigit(arg[1][0])) ? stoi(arg[1]) : 0;

        exit(exitCode);
    }

    if (arg[0] == "echo")
    {
        for (int i = 1; i < arg.size(); i++)
        {
            cout << arg[i] << " ";
        }
        cout << endl;
        return 1;
    }

    if (arg[0] == "type" and arg.size() > 1)
    {

        for (int i = 1; i < arg.size(); i++)
        {
            if (arg.size() > 1 and (arg[i] == "type" or arg[i] == "exit" or arg[i] == "echo"))
            {
                cout << arg[i] << " is shell builtin command " << endl;
            }
            else
            {
                bool flag = 0;

                string path = getenv("PATH");
                stringstream ss(path);
                string dir;

                while (getline(ss, dir, ':'))
                {
                    DIR *dp = opendir(dir.c_str());

                    if (!dp)
                        continue;

                    struct dirent *entry;
                    while ((entry = readdir(dp)) != nullptr )
                    {
                        if (entry->d_name == arg[i])
                        {
                            cout << arg[i] << " is " << dir << " " << arg[i] << endl;
                            flag = 1;
                            break;
                        }
                    }
                    closedir(dp);
                    if (flag)
                        break;
                }
                if(!flag){
                    cout<<arg[i]<<" not found"<<endl;
                }
            }
        }
        return 1;
    }
    return 0 ;
}

vector<string> splitCommand(string command)
{

    vector<string> arg;

    stringstream ss(command);

    string word;

    while (ss >> word)
    {
        arg.push_back(word);
    }

    return arg;
}


void executeExternal(vector<string> arg){
    if(arg.empty()) return ;


    pid_t pid = fork();

    if(pid==-1){
        cout<<"Fork Failed"<<endl;
        return;
    }
    // child Process
    if(pid==0){
        vector<char *> c_args;

        for(auto k: arg) {
            c_args.push_back(&k[0]);
        }

        c_args.push_back(nullptr);
        execvp(c_args[0],c_args.data());

        perror("Command execution failed");
        exit(1);
    }
    else{
        int status;

        waitpid(pid,&status,0);
    }
}

void shellLoop()
{
    while (1)
    {
        cout << "$";
        cout.flush();

        string command;

        if (!getline(cin, command) || command == "exit")
        {
            break;
        }

        vector<string> arg = splitCommand(command);

        for (int i = 0; i < arg.size(); i++)
        {
            cout << arg[i] << " ";
        }
        cout << endl;

        if (arg.empty())
            continue;

        if (executeBuiltin(arg))
        {
            continue;
        }

        executeExternal(arg);
    }
}

int main()
{

    shellLoop();
    cout << "hheee";
    return 0;
}
