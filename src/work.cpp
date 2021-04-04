#include "work.h"
queue<string> getfromfile(string filename){
    public_message=filename;
    queue<string>s;
    ifstream fin;
    fin.open(filename,std::ios::in);
    if(!fin.is_open())throw FILE_ERROR;
    string t;
    while(getline(fin,t)){
        s.push(t);
    }
    return s;
}
bool initstackfromfile(string filename){
    public_message=filename;
    vector<string>s;
    ifstream fin;
    fin.open(filename,std::ios::in);
    if(!fin.is_open())throw FILE_ERROR;
    string t;
    while(getline(fin,t)){
        s=split(t,' ');
        if(s.size()==0)return FORMAT_ERROR;
        uint32_t tt=selected_stack(s[0]);
        s.erase(s.begin());
        for(auto i:s){
            Three[tt].push(s_to_i32(i));
        }
    }
    return true;
}
bool lgwork(string filename){
    public_message=filename;
    excute();
    savefile:{
        ofstream fout;
        fout.open(filename,std::ios::out);
        if(!fout.is_open())throw FILE_ERROR;
        for(size_t i=0;i<3;++i){
            fout<<('A'+i);
            while(!Three[i].empty()){
                fout<<" "<<Three[i].top();
                Three[i].pop();
            }
            fout<<'\n';
        }
    }
}
