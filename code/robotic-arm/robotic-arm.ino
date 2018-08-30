#include<Servo.h>
#include<math.h>
int servoPin1=9;
Servo Servo1;
int servoPin2=10;
Servo Servo2;
int servoPin3=11;
Servo Servo3;
int LEDready=4;    //LED pou dixnei pws o vraxionas einai etoimos na lavei thesh kinhshs
int LEDout=5;      //LED pou dixnei pws o vraxionas den mporei na ftasei sto epithimito simio
int LEDmove=6;     //LED pou dixnei pws o vraxionas einai se kinhsh
int LEDok=7;       //LED pou dixnei pws o vraxionas eftase sthn epithimiti thesi
int x=160;
int y=200;
int z=0;
int plevra=80;
pi=2*PI;
float helper;
float helper2;
float helper3d;
float helper3d2;
float ipotinousa;

//circle parameters
bool doacircle=false;
int x0=0;
int y0=0;
int z0=0;
int anglecounter=0;
int R=0;
int sidecircle=0; //sidecircle=1 ->kuklos parallhlos me edafos sideofcircle=2 ->kuklos kathetos se aksona y sideofcircle=3 ->kuklos parallhlos me aksona y
int angleofrotation=0;
int angleofcircle=0;


//TO PROGRAMMA EPEKSERGAZETE TIS TIMES SE mm ( MILIMETER )
//*1 O VRAXIONAS APOTELITE APO 2 RAVDOUS TWN 80mm ME SUNOLIKO MIKOS(REACH) STA 160MM
//OTAN TO EPITHIMITO SIMIO KINHSHS VRISKETE SE APOSTASH, APO THN ARXH TOU VRAXIONA, MIKROTERH TWN 160MM
//^^TOTE O VRAXIONAS KAI OI 2 RAVDOI TOU MAZI ME THN NOHTH GRAMMH, APO TO SIMIO KINHSHS MERI THN ARXH TOU VRAXIONA,
//^^THA SXIMATIZOUN ENA ISOSKELES TRIGWNO TO OPOIO MORFOPOIHTE KAI UPOLOGIZETE APO TO FUNCTION : ISOSCELES
//*2 OLA TA IF STATEMENTS VRISKOUN THN GWNIA TOU KINHTHRA STHN VASH POU PERISTREFEI TON VRAXIONA GIA NA KOITAEI TO SWSTO SIMIO
//^^KATHOS KAI STELNOUN TIS SWSTES METAVLITES STHN FUNCTION ISOSCELES GIA THN KINHSH TWN UPOLOIPWN KINITIRWN
//H EPIFANIA METRHSHS THESHS EXEI PLATOS 400mm KAI MIKOS 200mm

//Function pou kalite otan to simio pou prepei na paei o vraxionas einai ektos emvelias
void outofreach(){
    //led kokkino
}

//vriskei upotinousa
float pithagoras(x,y){
  float help;
  help=sq(x)+sq(y);
  help=sqrt(help);
  return help;
}

//Metatroph aktiniwn se moires
float radtodeg(rad){
 float help;
  help=(rad*360)/pi;
  return help;
}

float yupordown(){
  float yhelp=0;
  if(y>200){
     yhelp=20-y;
  }
  if(y<200){
     yhelp=y-20;
  )
  return yhelp;
}

//Function pou upologizei thn gwia enos orthogwniou trigwnou exontas mono thn bash kai thn upotinousa
float rightangle(upotinousa,bash){
  int help;
  help=bash/upotinousa;
  help=acos(help);
  return help;
}

void isosceles(X1,X2){
  float help;
  help=radtodeg(rightangle(X1,X2))             //vriskei thn mh-orthi gwnia sthn vash tou trigwnou 
                                               //pou sximatizete me to upsos tou isoskelous trigwnou (se rad) 
                                               //kai thn metatrepei se mires
  Servo2.write(help);                        //vazei tis swstes times stous kinhthres     
                                             //---
  Servo3.write(180-(help*2));                //vazei tis swstes times stous kinhthres
}                                            //---

void isosceles3d(X1,X2,plusdeg){             //opws to function isosceles alla prostethei kai sto servo 2 mires
                                             //pou eixame vrei apo to katheto orthogwnio
  float help;
  help=radtodeg(rightangle(X1,X2))           //vriskei thn mh-orthi gwnia sthn vash tou trigwnou 
                                             //pou sximatizete me to upsos tou isoskelous trigwnou (se rad) 
                                             //kai thn metatrepei se mires
  Servo2.write(help+plusdeg);                //vazei tis swstes times stous kinhthres     
                                             //---
  Servo3.write(180-(help*2));                //vazei tis swstes times stous kinhthres
}  

void circle(){
  if (anglecounter<360){
    if (sideofcircle==1){
      x=x0+(cos(anglecounter*(PI/180))*R);
      y=y0+(sin(anglecounter*(PI/180))*R);
    }
    else if (sideofcircle=2){
      z=z0+(cos(anglecounter*(PI/180))*R);
      y=y0+(sin(anglecounter*(PI/180))*R);
    }
    else if (sideofcircle=3){
      z=z0+(cos(anglecounter*(PI/180))*R);
      x=x0+(sin(anglecounter*(PI/180))*R);
    }
    else{
      if (angleofcircle==0){
         
      }
      else{
        
      }
    }
    anglecounter=anglecounter+1;
  }
  else{
    doacircle=false;
  }
}

void setup() {
  Servo1.attach(servoPin1);//servo sthn vash
  Servo2.attach(servoPin2);//prwth arthwsh apo thn vash
  Servo3.attach(servoPin3);//defterh arthwsh apo thn vash
  pinMode(LEDready,OUTPUT);
  pinMode(LEDout,OUTPUT);
  pinMode(LEDmove,OUTPUT);
  pinMode(LEDok,OUTPUT);
  delay(1000);
  Servo1.write(90);
  Servo2.write(90);
  Servo3.write(90);
}

void loop() {
  delay(1000);
  digitalWrite(LEDready, HIGH);

//IF STATEMENTS pou kathorizoun thn swsth xrush eksisosewn *2^^
//Prwtos grhgoros elegxos shmeiou ektos oriwn
  if ( (x>160) || (y<40) || (y>360) ||(z>160) ) {           //*1^^ grhgoros elegxos aporipseis orismenwn parametrwn kinhshs pou vriskontai ekso apo ta oria
    outofreach();
  }
  
  //---------------------------------ENARKSH VASIKOU PROGRAMMATOS--------------------------------
  
  //edw iserxete gia simio se disdiastato xwro
  else if(z==0){                                   //PROSOXH EDW H TIMH TOU 200 SUMVOLIZEI TO MESO TOU PLATOUS THS EPIFANIAS METHRSHS THESHS (400/2)
    
   if (y==200){                                    //h periptws opou vriskete panw ston aksona x------------------------------------------------------------------
      Servo1.write(90);
      if(x<160){
        isosceles(plevra,(x/2));
      }
      else{              //h periptosh pou vriskete panw ston x alla einai kai ish me to max lenght tou vraxiona-----------+
        Servo1.write(90);
        Servo2.write(90);
        Servo3.write(180);
      }
    }
    else{
      if (x==0){               //h periptwsh opou to shmeio vriskete panw sthn grammh tou y-----------------------------------------------------------------------
        
        if (y>40 && y<200){  //h periptosh pou vriskete panw ston y kai anamesa sto 0kai to 200 tou y-------------------------+
          isosceles(plevra,((200-y)/2));                   //200-y gia na vrei mish vash tou isoskelous pou en telh tha sximatisei o vraxionas
          Servo1.write(0);
        }
        
        else if(y>200 && y<360){   //h periptosh pou vriskete panw ston y kai anamesa sto 200 kai to 369 tou y-------------------------+
          isosceles(plevra,((y-200)/2));                   //y-200 gia na vrei mish vash tou isoskelous pou en telh tha sximatisei o vraxionas
          Servo1.write(180);
        }
        
        else{                  //h periptosh pou vriskete panw ston y alla einai kai ish me to max lenght tou vraxiona-----------+
          if(y>200){
            Servo1.write(180);
          }
          if(y<200){
            Servo1.write(0);
          }
          Servo2.write(0);
          Servo3.write(180));
        }
      }

      
      else{                                        //h periptwsh pou vriskete kapou anamesa ston aksona x kai y------------------------------------------------------
        helper=yupordown(); 
        ipotinousa=pithagoras(x,helper);            //upotinousa orthogwniou trigwnou pou apikonizei thn grammh apo ton
                                                   //vraxiona mexri to epithimito shmio kinhshs 
                                                   
        //edw vriskw thn gwnia tou kinhthra 1 sth vash
        helper=radtodeg(rightangle(ipotinousa,x)));  
        if(y>200){
          Servo1.write(90+helper);
        }
        if(y<200){
          Servo1.write(90-helper);
        }
        
        if (ipotinousa<160){                //h periptwsh pou vriskete kapou anamesa ston aksona x kai y kai to simio einai mikrotero apo max lenght-------+
          isosceles(plevra,(ipotinousa/2));          //kalei to function tou isoskelous pou sximatizete me 
                                                     //ta akra tou vraxiona kai mia noiti grammh
          
        }
        else if (ipotinousa==160){          //h periptwsh pou vriskete kapou anamesa ston aksona x kai y kai to simio exei max lenght----------------------+
          Servo2.write(0);
          Servo3.write(180);
        }
        else{
          outofreach();
        }
      }
    }
    
  }
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------EDW LUNEI SE TRISDIASTATO XORO------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  else{
    //AKSISWSEIS GIA Z>0 , SE TRISDIASTATO XWRO
    
    if (x==0 && y==200){//PROSOXH EDW H TIMH TOU 200 SUMVOLIZEI TO MESO TOU PLATOUS THS EPIFANIAS METHRSHS THESHS
                 //edw upologizei tis gwnies twn arthrosewn an einai efthia panw apo ton vraxiona h thesi kinhshs+++++++++++++++++++++++++++++++++++++++++++++
                 
      helper=radtodeg(rightangle(plevra,(z/2)));
      if (z<160){
        Servo1.write(90);
        Servo2.write(90+helper);
        Servo3.write(180-(helper*2));
      }
      else if((z==160){
        Servo1.write(90);
        Servo2.write(90);
        Servo3.write(180);
      }
      else{
        outofreach();
      }
    }
    
    else if (y==200 && x>0){                             //h periptws opou vriskete panw apo ton aksona x--------------------------------------------------------------
      Servo1.write(90);
      helper3d=pithagoras(x,z);                  //h upotinousa tou orthogwniou 0xz pou einai kai h efthia metkai epihimitou simiou kai arxh vraxiona
      helper3d2=radtodeg(rightangle(helper3d,x)) //oi mires sthn mh orthi gwnia ths vashs sto trigwno 0xz
      if(helper3d<160){
        isosceles3d(plevra,(helper3d/2),helper3d2)  //to isoskeles panw apo thn upotinousa tou orthogwniou 0xz
      }
      else if (helper3d==160){              //h periptosh pou vriskete panw ston x alla einai kai ish me to max lenght tou vraxiona-----------+
        Servo1.write(90);
        Servo2.write(helper3d2);
        Servo3.write(180);
      }
      else(){
        outofreach();
      }
    }
//-------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------++++h periptwsh pou vriskete kapou panw apo ton aksona y (se "idiaiterh thesh) kai exei z
    else{                                         //++++h periptwsh pou vriskete kapou panw apo ton aksona y (se "idiaiterh thesh) kai exei z
      if (y>0 && x==0){
        helper=yupordown();                              //vriskei thn apostash tou epithimitou shmeiou apo ton nohto aksona x
        helper3d=pithagoras(z,helper);                   //vriskei thn upotinousa tou noitou orthogwniou pou einai katheto ston aksona y
        helper3d2=radtodeg(rightangle(helper3d,helper))  //vriseki thn gwnia sthn vash tou apo panw trigwnou
        if (y>40 && y<200 && helper3d<160){          //+---h periptosh pou vriskete panw ston y kai anamesa sto 0 kai to 200 tou y
          isosceles3d(plevra,(helper3d/2),helper3d2);    //function pou thetei tis parametrous se servo 2,3 gia na sximatistei isoskeles
          Servo1.write(0);                               //thetei to servo 1 na koitaei to y=0
        }
        
        else if(y>200 && y<360 && helper3d<160){     //+---h periptosh pou vriskete panw ston y kai anamesa sto 200 kai to 360 tou y
          isosceles3d(plevra,(helper3d/2),helper3d2);    //to isoskeles panw apo thn upotinousa tou orthogwniou 0(yupordown)z
          Servo1.write(180);                             //thetei to servo 1 na koitaei to y=400
        }
        
        else if (helper3d==160){              //+---h periptosh pou vriskete panw ston y alla einai kai ish me to max lenght tou vraxiona
          if(y>200){                              //kathorizei an tha paei aristera h deskia
            Servo1.write(180);                    //kathorizei an tha paei aristera h deskia
          }                                       //kathorizei an tha paei aristera h deskia
          if(y<200){                              //kathorizei an tha paei aristera h deskia
            Servo1.write(0);                      //kathorizei an tha paei aristera h deskia
          }
          Servo2.write(helper3d2);                //Grafei thn telikh thesh gia to servo 2 pou kinei thn prwth ravdo
          Servo3.write(180);                      //Grafei thn telikh thesh gia to servo 3 pou kinei thn defterh ravdo
        }
        else{
          outofreach();                           //To simio vriskete ektos oriwn
        }
      }
//-------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------++++h periptwsh pou vriskete kapou entos tou xwrou xyz kai den einai se "idiaiterh thesh"     
      else{                                       //++++h periptwsh pou vriskete kapou entos tou xwrou xyz kai den einai se "idiaiterh thesh"
        helper=pithagoras(x,yupordown);           //vriskei thn upotinousa tou prwtou noitou orhogwniou to opoio efaptete ston xwro xy
        helper2=radtodeg(rightangle(helper,x));   //vriseki thn gwnia sthn vash tou apo panw trigwnou
        helper3d=pithagoras(helper,z);            //vriskei thn upotinousa tou defterou noitou orhogwniou katheto sthn upotinousa helper
                                                  
        helper3d2=radtodeg(rightangle(helper3d,helper));  //edw vriskw thn gwnia tou kinhthra 1 sth vash
        if(y>200){                                        //kathorizei an tha paei panw h katw apo ton aksona x
          Servo1.write(90+helper2);                       //kathorizei an tha paei panw h katw apo ton aksona x
        }                                                 //kathorizei an tha paei panw h katw apo ton aksona x
        if(y<200){                                        //kathorizei an tha paei panw h katw apo ton aksona x
          Servo1.write(90-helper2);                       //kathorizei an tha paei panw h katw apo ton aksona x
        }                                                 //kathorizei an tha paei panw h katw apo ton aksona x
        
        if (helper3d<160){               //+---otan h apostash apo thn arxh tou vraxiona me to epithimito simio einai mikroterh apo max lenght
          isosceles3d(plevra,(helper3d/2),helper3d2);     //function pou thetei tis parametrous se servo 2,3 gia na sximatistei isoskeles
        }                                                 //anamesa sthn arthrwsh thn arxh tou vraxiona kai to epithimito shmeio kinhshs
        
        else if (ipotinousa==160){       //+---otan h apostash apo thn arxh tou vraxiona me to epithimito simio einai ish me max lenght
          Servo2.write(helper3d2);                        //o vraxionas efaptete sthn ipotinousa tou nitou trigwnou 2 pernontas tis moires tou
          Servo3.write(180);                              //to servo 3 pou elegxei thn teleftea ravdo stis 180 moires einai se efthia
        }
        else{
          outofreach();                                   //To simio vriskete ektos oriwn
        }
      }
    }
    
  }
  //if (doacircle=true){
    //circle();
  }
}
