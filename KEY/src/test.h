
int sl = 0;
typedef struct Thanh_vien 
{ 
    String Ten; 
    String ID;
    int MSSV;
} Thanh_vien;
Thanh_vien lab[50] = {"Xuan Mai", "2817044647", 20200382};

void nhap()
{
    lab[sl].Ten = "Tran Luong";
    lab[sl].ID = ID;
    lab[sl].MSSV = 20202446;
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