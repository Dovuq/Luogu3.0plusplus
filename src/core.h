#include "base.h"
#include <queue>
using std::queue;
extern luogu_stack Three[3];
extern uint32_t state_num,default_state;
extern vector<order>orders;
bool initall(queue<string>s);
bool excute();
bool savefile(string filename);
