#define oe 2
#define stb 3
#define clk 4
#define db1 5
#define dr1 6
#define db0 7
#define dr0 8
#define dg0 9
#define dg1 10

#define set(x) digitalWrite(x,HIGH)
#define reset(x) digitalWrite(x,LOW)
#define ulong unsigned long


ulong long task[8][2]={
  {0xF720B332D800FE40 //all
  ,0x2702330008004E},

  {0xF72080001000FE40 //2 stop
  ,0x2700000000004E},

  {0x1000FE40,//1stop left
  0x4e},

  {0x3332D800FE40//stop arrow 0
  ,0x0002330008004E},

  {0xF720B332C8000000,//0 arrow stop
  0x27023300080000},

  {0x3332C8000000,//only arrow
  0x23300080000},

  {0xF720800000000000,//only 1 arrowright
  0x27000000000000},

  {0,0}


};


void setup() {
reset(stb);
  reset(clk); 
  reset(dr1); 
  reset(dg1); 
  reset(db1); 
  reset(dr0); 
  reset(dg0);
  reset(db0);  
  Serial.begin(9600);
  
  pinMode(oe, OUTPUT);
  pinMode(stb, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(db1, OUTPUT);
  pinMode(dr1, OUTPUT);
  pinMode(dg1, OUTPUT);
  pinMode(db0, OUTPUT);
  pinMode(dr0, OUTPUT);
  pinMode(dg0, OUTPUT);  
}
//                      1000FE40
//ulong long d1=0xF720 B332 D800 FE40;
  ulong long d1=0xF720800000000000;
  
//ulong long d2=0x2702 3300 08004E;
  ulong long d2=0x4e;
byte cnt=10,x=0;
void loop() {
  //d1= 0x3100EC80;
  //d2=0x01008C;
  //d1=0x1111EC80;//triangle
  //d2=0x111008C;//triangle
/*
  d1=0xF720B332D800FE40; //all
  d2=0x2702330008004E;

  d1=0xF72080001000FE40; //2 stop
  d2=0x2700000000004E;

  d1=0x1000FE40;//1stop left
  d2=0x4e;

  d1=0x3332D800FE40; //stop arrow 0
  d2=0x0002330008004E;

  d1=0xF720B332C8000000;//0 arrow stop
  d2=0x27023300080000;

  d1=0x3332C8000000;//only arrow
  d2=0x23300080000;

  d1=0;
  d2=0;

  d1=0xF720800000000000;//only 1 arrowright
  d2=0x27000000000000;
*/

for(x=0;x<8;x++)
{
  //set(oe);
  d1=task[x][0];
  d2=task[x][1];
  d1=0x1210272024204E0;
  d2=0x1210272024204E00;

  for(byte i=0;i<64;i++)
  {
    if(bitRead(d1, i))
    {
        if(i==27 || i==30 || i==31 || i==33 || i== 36 || i==37 || i==40 || i==41 || i==44 || i==45 )
        {
          set(db0);
          reset(dg0);
        }else
        {
        set(dg0);
        reset(db0);
        }
    }
    else {
      reset(dg0);
      reset(db0);
    } 

    if(bitRead(d2, i))
    {
      if(i==19 || i==32 || i==33 || i== 36 || i==37 || i==41 )       
      {
          set(db1);
          reset(dg1);
        }else
        {
        set(dg1);
        reset(db1);
        }
    }
    else {
      reset(dg1);
      reset(db1);
    } 
    
    set(clk);
    //delay(1);
    reset(clk);


  //delay(100);
  }



  set(stb);
  delay(1);
  reset(stb);


  reset(oe);
  delay(2000);
}
//while(1);
}
