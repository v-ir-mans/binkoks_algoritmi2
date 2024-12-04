#include <iostream>
    
using namespace std;

//Kpc es uzrakstīju LV?
struct mezgls
{
    int dati;
    mezgls *adrKreisa, *adrLaba;
};

mezgls *CreateNode (int dati)
{
    mezgls *newNode; 		
    newNode = new mezgls;	

    newNode->dati=dati;

    newNode->adrKreisa=NULL;	
    newNode->adrLaba=NULL;	

    return newNode;		
}

int generateRandomInt() {
    
    return rand() % 10 + 1;
}

void TEMP_display_tree(mezgls *sakne){
    mezgls *cur=sakne;

    cout<<cur->dati<<";";

    if (cur->adrKreisa!=NULL)
    {
        TEMP_display_tree(cur->adrKreisa);
    }
    
    if (cur->adrLaba!=NULL)
    {
        TEMP_display_tree(cur->adrLaba);
    }
}

bool addNodeAtKey(mezgls *sakne, string key){
    cout<<key;

    return false;
}

int main()
{
    srand(4);

    mezgls *sakne, *K, *KL, *L, *LK, *LL, *LKK;
    

    sakne=CreateNode(0);

    //---- Hardcoded tree

    K = CreateNode(7);
    KL = CreateNode(5);
    L = CreateNode(12);
    LK = CreateNode(8);
    LL = CreateNode(6);
    LKK = CreateNode(20);

    sakne->adrKreisa=K;

    K->adrLaba=KL;

    sakne->adrLaba=L;

    L->adrLaba=LL;

    L->adrKreisa=LK;

    LK->adrKreisa=LKK;

    //----

    TEMP_display_tree(sakne);
    addNodeAtKey(sakne, "LKL");
    
    return 0;
}
