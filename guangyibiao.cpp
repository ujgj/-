#include <iostream>
#include <string>
using namespace std;

#define AtomType    int

typedef enum{ATOM,LIST}ElemTag; //ATOM = 0：原子；LIST = 1:子表 

//链式表设计法
//节点设计
typedef struct GLNode
{
    ElemTag tag;    //枚举类型的标志域，只能取定义了的枚举值
    union {
        AtomType atom;
        struct  //union联合体，下面两部分只能取其一；要么取AtomType;要么取结构体ptr,ptr包括两个指针hp,tp 
        {
            struct GLNOde *hp, *tp; 
        } ptr;
    };
} *GList;   //定义广义表类型，GList为指针

/*线性表存储之扩展线性表 = 子表法*/
/*
typedef struct GLNode
{
    ElemTag tag;
    union 
    {
        AtomType atom;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} *GList;
*/

void server(string &str, string &hstr){
    //将非空串str分割成两部分，hstr是表头
    int n = str.size();
    int i = -1;
    int k = 0;
    char ch;
    do{
        ++i;
        ch = str[i];
        if(ch == '(')   ++k;
        else if(ch == ')')  --k;
    }while (i<n && (ch!=',' || k!=0));
    if(i<n){
        hstr = str.substr(0, i);
        str = str.substr(i+1, n-i-1);
    }else{
        hstr = str.substr(0, str.size());
        str.clear();
    }
}

void CreateGList(GList &L, string s){
    //采用头尾链表存储结构，创建L
    if (s.compare("emp") == 0)  L = NULL;
    else{
        L = (GList)malloc(sizeof(GLNode));
        if (!L) exit(0);
        if(s.size() == 1){
            L->tag = ATOM;
            L->atom = s[0];
        }else{
            L->tag = LIST;
            GList p,q;
            p = L;
            string sub;
            sub = s.substr(1, s.size()-2);
            string hsub;
            do {
                server(sub, hsub);
                CreateGList(p->ptr.hp, hsub);
                q = p;
                if (!sub.empty()){
                    p = (GList)malloc(sizeof(GLNode));
                    if (!p) exit(0);
                    p->tag = LIST;
                    p->ptr.tp = p;
                }
            }while(!sub.empty());
            q->ptr.tp = NULL;
        }
    }
}

//广义表的深度
int GListDepth(GList L){
    if(!L)  return 1;
    if(L->tag == ATOM)  return 0;
    GList pp;
    int max;
    for(max=0, pp=L; pp!=L;pp=pp->ptr.tp){
        int dep = GListDepth(pp->ptr.hp);
        if(dep>max){
            max = dep;
        }
    }
    return max+1;
}
