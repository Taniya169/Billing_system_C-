#include<iostream>
#include<fstream>
using namespace std;

class Shopping
{
    private:
       int pcode;        // product code
       int price;
       float dis;          // discount
       string pname;       // product name

    public:
       void menu();          // function for  menu
       void administrator();  // function for administrator
       void buyer();          // function for buyer
       void add();            //function for add item
       void edit();           //function for edit any item
       void rem();            // function for removing any item
       void list();           // function to list the items
       void receipt();        // receipt function
};

void Shopping :: menu()
   {
      m:
       int choice;
       string email;
       string password;

       cout<<"\t\t\t\t_____________________________________\n";
       cout<<"\t\t\t\t                                     \n";
       cout<<"\t\t\t\t        Supermarket Main menu        \n";
       cout<<"\t\t\t\t                                     \n";
       cout<<"\t\t\t\t_____________________________________\n";
       cout<<"\t\t\t\t                                     \n";
       cout<<"\t\t\t\t|   1)  Administrator     |\n";
       cout<<"\t\t\t\t|                         |\n";
       cout<<"\t\t\t\t|   1)  Buyer             |\n";
       cout<<"\t\t\t\t|                         |\n";
       cout<<"\t\t\t\t|   1)  Exit              |\n";
       cout<<"\t\t\t\t|                         |\n";
       cout<<"\n\t\t\t   Please select!";
       cin>>choice;

       switch(choice)
       {
         case 1:
              cout<<"\t\t\t  Please Login \n";
              cout<<"\t\t\t  Enter Email   \n";
              cin>>email;
              cout<<"\t\t\t  password       \n";
              cin>>password;

              if(email=="robby@gmail.com" && password=="robby@123")
              {
               administrator();
              }
              else{
               cout<<"Invalid email/password";
              }
              break;
       
       case 2:
           {
            buyer();
           }
      case 3:
            {
               exit(0); 
                }
       default :
             {
               cout<<"Please select from the given options";
             }
       }
     goto m;     // goto is jump statement so it is helping us to jump in main menu
   }


void Shopping :: administrator()
{ 
   m:
   int choice;
   cout<<"\n\t\t\t|______1) Add the product________|";
   cout<<"\n\t\t\t|                                |";
   cout<<"\n\t\t\t|______2) Modify the product_____|";
   cout<<"\n\t\t\t|                                |";
   cout<<"\n\t\t\t|______3) Delete the product_____|";
   cout<<"\n\t\t\t|                                |";
   cout<<"\n\t\t\t|______4) Back to the main menu__|";

   cout<<"\n\n\t Please enter your choice";
   cin>>choice;
   switch(choice)
   {
      case 1:
          add();
          break;
      case 2:
           edit();
           break;
      case 3:
           rem();
           break;
      case 4:
           menu();  
           break;   
       default :
           cout<<"Invalid choice! ";
   }
    goto m;
} 

void Shopping :: buyer()
{
   m:
   int choice;
   cout<<"\t\t\t   Buyer  \n";
   cout<<"\t\t\t_________________ \n";
   cout<<"                        \n";
   cout<<"\t\t\t1) Buy product    \n";
   cout<<"                        \n";
   cout<<"\t\t\t2) Go back        \n";
   cout<<"\t\t\t Enter your choice  :";
   cin>>choice;

   switch(choice)
   {
      case 1:
           receipt();
           break;
      case 2:
            menu();
      default :
           cout<<"Invalid choice";
   }
   
   goto m;

}

void Shopping :: add()
{
   m:
   fstream data; // object of fstream class
   int c;
   int token=0;
   float p;
   float d;
   string n;

   cout<<"\n\n\t\t\t  Add new product";
   cout<<"\n\n\t Product code of the product ";
   cin>>pcode;
   cout<<"\n\n\t Name of the product ";
   cin>>pname;
   cout<<"\n\t\t Price of the product ";
   cin>>price;
   cout<<"\n\n\t Discount on product";
   cin>>dis;

   data.open("database.txt",ios::in);  //open the file in read mode

   if(!data)      //if data file doesn't exist
   {
       data.open("database.txt", ios::app|ios::out);           //open file in write mode
       data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
       data.close();
   }
   else{
      data>>c>>n>>p>>d;     //read from the file
      while(!data.eof())
      {
         if(c==pcode)
         {
             token++;
         }
         data>>c>>n>>p>>d;
      }
      data.close();

   }
   if(token==1)
   {
      goto m;
   }
   else{
          data.open("database.txt", ios::app|ios::out);           //open file in write mode
       data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
       data.close();
   }
   cout<<"\n\n\t\t  Record inserted !";

}

void Shopping :: edit()
{
   fstream data,data1;
   int pkey;
   int token=0;
   int c;
   float p;
   float d;
   string n;

   cout<<"\n\t\t\t Modify the record";
   cout<<"\n\t\t\t product code : ";
   cin>>pkey;

   data.open("database.txt",ios::in);
   if(!data)
   {
      cout<<"\n\nFile doesn't exist";
   }
   else{
      data1.open("database1.txt",ios::app|ios::out);

      data>>pcode>>pname>>price>>dis;
      while(!data.eof())
      {
         if(pkey==pcode)
         {
            cout<<"\n\t\t Product of new code :";
            cin>>c;
            cout<<"\n\t\t Name of the product :";
            cin>>n;
            cout<<"\n\t\t Price :";
            cin>>p;
            cout<<"\n\t\t Discount :";
            cin>>d; 
            data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            cout<<"\n\n\t\t Record edited ";
            token++;
         }
         else{
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
         }
         data>>pcode>>pname>>price>>dis;
      }
      data.close();
      data1.close();


     remove("database.txt");
     rename("database1.txt","database.txt");

     if(token==0)
     {
      cout<<"\n\n Record not found sorry!";
     }
   }
}

void Shopping :: rem()
{
   fstream data,data1;
   int pkey;
   int token=0;
   cout<<"\n\n\t Delete product";
   cout<<"\n\n\t Product code";
   cin>>pkey;
   data.open("database.txt",ios::in);
   if(!data)
   {
      cout<<"File doesn't exist";

   }
   else{
      data1.open("database1.txt",ios::app|ios::out);
      data>>pcode>>pname>>price>>dis;
      while(!data.eof())
      {
         if(pcode==pkey)
         {
            cout<<"\n\n\t Product deleted succesfully";
            token++;

         }
         else{
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
         }
         data>>pcode>>pname>>price>>dis;
      }
      data.close();
      data1.close();
      remove("database.txt");
      rename("database1.txt","database.txt");

      if(token==0){
         cout<<"\n\n Record not found";
      }
   }
}
void Shopping ::list()    //it will help us to showing the list to the customer or buyer
{
   fstream data;
   data.open("database.txt",ios::in);
   cout<<"\n\n|________________________________________________\n";
   cout<<"ProNo\t\tPrice\n";
   cout<<"\n\n|________________________________________________\n";
   data>>pcode>>pname>>price>>dis;
   while(!data.eof())
   {
      cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
      data>>pcode>>pname>>price>>dis;
   }
      data.close();
}

void Shopping ::receipt()
{  
   
   fstream data;
   int arrc[100];
   int arrq[100];
   char choice;
   int c=0;
   float amount;
   float dis=0;
   float total=0;

   cout<<"\n\n\t\t\t\t  RECEIPT";
   data.open("database.txt",ios::in);
   if(!data)
   {
      cout<<"\n\n Empty database";
   }
   else{
      data.close();
      list();
      cout<<"\n_____________________________________\n";
      cout<<"\n|                                     \n";
      cout<<"\n      Please place the order          \n";
      cout<<"\n|                                     \n";
      cout<<"\n_____________________________________\n";

     do{
      m:
      cout<<"\n \n Enter  Product code : ";
      cin>>arrc[c];
      cout<<"\n\nEnter the product quantity :";
      cin>>arrq[c];
      for(int i=0;i<c;i++)
      {
         if(arrc[c]==arrc[i])
         {
            cout<<"\n\n Duplicate product code.please try again!";
            goto m;
         }
      }
      c++;
      cout<<"\n\n Do you want to buy another product ? if yes then press y else no";
      cin>>choice;
     }
     while(choice =='y');


     cout<<"\n\n\t\t\t _____________________RECEIPT_____________________\n";
     cout<<"\n Product No\t product Name \tproduct quantity\tprice\tAmount with discount\n";

     for(int i=0;i<c;i++)
     {
      data.open("database.txt",ios::in);
      data>>pcode>>pname>>price>>dis;
      while(!data.eof())
      {
         if(pcode==arrc[i])
         {
            amount=price*arrq[i];
            dis=amount-(amount*dis/100);
            total=total+dis;
            cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;       
          }
           data>>pcode>>pname>>price>>dis;
      }
     }
      
   data.close();
   }
   cout<<"\n\n______________________________________________";
   cout<<"\n Total Amount : "<<total;
}

int main(){
   Shopping s;
   s.menu();
}

