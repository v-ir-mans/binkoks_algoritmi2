#include <iostream>
#include <bitset>

#define MAX_LEVEL 256


using namespace std;

//Kpc es uzrakstīju LV?
struct mezgls
{
    int dati;
    mezgls *adrKreisa, *adrLaba;
};

struct mezglaAdrese {
    int dzilums;
    bitset<MAX_LEVEL> adrese;

    mezglaAdrese(string adreses_teksts){

        if(adreses_teksts.length()<=MAX_LEVEL){

            int i;

            for (i = 0; i < adreses_teksts.length(); i++)
            {
                if (adreses_teksts[i]=='K')
                {
                    adrese[i]=0;
                }else if (adreses_teksts[i]=='L')
                {
                    adrese[i]=1;
                }else
                {
                    dzilums=-1;
                    cout << "Bad key\n";
                    return;
                }
                
                
            }
            
            dzilums=i;
        }
    }
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

unsigned int getNodeAtKey(mezgls *sakne, mezglaAdrese MA, mezgls *&to_change){

    mezgls *cur=sakne; bool stop_loop=false; int i = 0;


    while (!stop_loop && i < MA.dzilums)
    {
        if (MA.adrese[i]==0)
        {
            if (cur->adrKreisa!=NULL)
            {
                cur=cur->adrKreisa;
            }else{
                stop_loop=1;
            }
            
        }else{
            if (cur->adrLaba!=NULL)
            {
                cur=cur->adrLaba;
            }else{
                stop_loop=1;
            }
        }

        if (!stop_loop) i++;
    }
        
    to_change=cur;

    return MA.dzilums-i;
}

bool addNodeAtKey(mezgls *sakne, mezglaAdrese MA, int dati){

    mezgls *cur;

    unsigned int possible_to_add=getNodeAtKey(sakne, MA, cur);

    

    // getNodeAtKey atgriež cik mezglu pitrūkst līdz dotajai adresei
    // 0 nozīmē, ka pietrūkst 0 mezglu jeb tāds mezgls jau pastāv
    // -1 nozīmē, ka pietrūkst 1 mezgla jeb adrese ir iespējama, 
    // ja pievieno 1 mezglu
    if (possible_to_add==1){

        mezgls *newNode=CreateNode(dati);

        if (MA.adrese[MA.dzilums-1]==0) cur->adrKreisa=newNode;
        else cur->adrLaba=newNode;
        
    }

    return false;
    
}

int main()
{
    srand(4);

    mezgls *sakne;
    

    sakne=CreateNode(0);

    addNodeAtKey(sakne, mezglaAdrese("K"), 7);
    addNodeAtKey(sakne, mezglaAdrese("KL"), 5);

    addNodeAtKey(sakne, mezglaAdrese("L"), 12);
    addNodeAtKey(sakne, mezglaAdrese("LK"), 8);
    
    addNodeAtKey(sakne, mezglaAdrese("LL"), 6);
    addNodeAtKey(sakne, mezglaAdrese("LKK"), 20);

    TEMP_display_tree(sakne);
    cout<<endl;


    
    return 0;
}
