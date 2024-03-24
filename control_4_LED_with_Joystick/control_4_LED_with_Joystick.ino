const int LRpin = A0 ;
const int UDpin = A1 ;

int GPin = 6;
int BPin = 9;
int YPin = 10;
int RPin = 11;

int LR ;
int LR_first ;
int UD ;
int UD_first ;
int R , Y , G , B;


int freezone = 10;

void setup() 
{
  LR_first = analogRead(LRpin);
  UD_first = analogRead(UDpin);

}

void loop()
{
  LR = analogRead(LRpin);
  UD = analogRead(UDpin);

  if ( UD >= UD_first + freezone)
  {
    B = 0;
    R = map( UD , UD_first , 1023 , 0 , 255 );
  }
  else if ( UD <= UD_first - freezone)
  {
    R = 0;
    B = map( UD , UD_first , 1023 , 0 , 255 );
  }
  else 
    R = 0;
    B = 0;

  if ( LR >= LR_first + freezone)
  {
    Y = 0;
    G = map( LR , LR_first , 1023 , 0 , 255 );
  }
  else if ( LR <= LR_first - freezone)
  {
    G = 0;
    Y = map( LR , LR_first , 1023 , 0 , 255 );
  }
  else 
    R = 0;
    B = 0;


  analogWrite( RPin , R );
  analogWrite( YPin , Y );
  analogWrite( GPin , G );
  analogWrite( BPin , B );
}
