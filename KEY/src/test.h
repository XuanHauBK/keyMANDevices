
int sl = 0;
typedef struct Thanh_vien 
{ 
    String Ten; 
    String ID;
    String MSSV;
} Thanh_vien;
Thanh_vien lab[50] = {"Xuan Mai", "2817044647", "20200382"};

void nhap()
{

    lab[sl].ID = ID;

}

int quetID()
{ 

    for(int i = 0; i <= sl ; i++)
    {
        if(ID == lab[i].ID) 
        { 
           return 1;
        } 
    
    } 
    return 0;


}