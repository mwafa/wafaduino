int a = A3;
int waktu = 1000;
int lama = 0;
int baru = 0;

boolean spasi[] = {0,0,0,0,0,0};
boolean W[]     = {0,1,1,1,1,1,
                   1,0,0,0,0,0,
                   0,1,1,0,0,0,
                   1,0,0,0,0,0,
                   0,1,1,1,1,1};
boolean F[]     = {1,1,1,1,1,1,
                   0,0,0,1,0,1,
                   0,0,0,0,0,1};
boolean A[]     = {1,1,1,1,1,0,
                   0,0,0,1,0,1,
                   0,0,0,1,0,1,
                   1,1,1,1,1,0};


void setup() {
  // put your setup code here, to run once:
  for(int i=2; i<=7;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(a,INPUT);
}

void loop() {
  baru = analogRead(a);
  if(baru > 8){
    baru = 1;
  }else{
    baru = 0;
  }
  if(baru != lama){
    if(baru == 1){
      delayMicroseconds(5000);
      satu(spasi);
      lima(W);
      satu(spasi);
      empat(A);
      satu(spasi);
      tiga(F);
      satu(spasi);
      empat(A);
      satu(spasi);
    }
  }
  lama = baru;
}

void satu(boolean k[]){
  for(int i= 0;i<=5;i++){
    digitalWrite(i+2,k[i]);
  }
  delayMicroseconds(waktu);
}
void dua(boolean k[]){
  int m = 0;
  for(int i=0;i<=10;i++){
    m++;
    m = m%6;
    digitalWrite(m+2,k[i]);
    if(m=5){
      delayMicroseconds(waktu);   
    }
  }
}
void tiga(boolean k[]){
  int m = 0;
  for(int i=0;i<=15;i++){
    m++;
    m = m%6;
    digitalWrite(m+2,k[i]);
    if(m=5){
      delayMicroseconds(waktu);   
    }
  }
}
void empat(boolean k[]){
  int m = 0;
  for(int i=0;i<=20;i++){
    m++;
    m = m%6;
    digitalWrite(m+2,k[i]);
    if(m=5){
      delayMicroseconds(waktu);   
    }
  }
}
void lima(boolean k[]){
  int m = 0;
  for(int i=0;i<=25;i++){
    m++;
    m = m%6;
    digitalWrite(m+2,k[i]);
    if(m=5){
      delayMicroseconds(waktu);   
    }
  }
}

