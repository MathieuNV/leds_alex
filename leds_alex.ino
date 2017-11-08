#define NB_MARCHES  12

int marches[NB_MARCHES] = {2,3,4,5,6,7,8,9,10,11,12,13};

int allumage_force = A1;
int montee = A3;
int descente = A4;
int potentiometre = A0;

int valeur_potentiometre;

int toto = 0;

void setup() {
  // put your setup code here, to run once:
  
  for(int i = 0; i< NB_MARCHES; i++)
  {
    pinMode(marches[i], OUTPUT);
    analogWrite(marches[i], 0);
  }
  
  pinMode(allumage_force, INPUT_PULLUP);
  pinMode(montee, INPUT_PULLUP);
  pinMode(descente, INPUT_PULLUP);
  
  pinMode(potentiometre, INPUT);

  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:

  if( !digitalRead(allumage_force) )
  {
    
    valeur_potentiometre = analogRead(potentiometre) / 4;
    Serial.println(valeur_potentiometre);
    Marche_forcee(valeur_potentiometre);
    //Marche_forcee(valeur_potentiometre);
   
  }

  
}


void Effet1(int vitesse)
{
   for(int i = 0; i< NB_MARCHES; i++)
   {
     for(int j = 0; j< NB_MARCHES; j++)
     {
       analogWrite(marches[j], 0);
     }
     
       analogWrite(marches[i], 255);
       delay(vitesse);
   }
   
   for(int i = NB_MARCHES; i>=0; i--)
   {
     for(int j = 0; j< NB_MARCHES; j++)
     {
       analogWrite(marches[j], 0);
     }
     
       analogWrite(marches[i], 255);
       delay(vitesse);
   }
}


void Effet2(int vitesse)
{
   for(int j = 0; j< NB_MARCHES; j++)
   {
     analogWrite(marches[j], 0);
   }
     
   for(int i = 0; i< NB_MARCHES; i++)
   {
     for(int j = 0; j< 255; j++)
     {
       analogWrite(marches[i], j);
       delay(4);
     }
     delay(50);
   }
   
   delay(2000);
   
   for(int i = NB_MARCHES-1; i>=0; i--)
   {
     for(int j = 255; j>=0 ; j--)
     {
       analogWrite(marches[i], j);
       delay(4);
     }
     delay(50);
   }
}

void Marche_forcee(int valMax)
{
   for(int j = 0; j< NB_MARCHES; j++)
   {
     analogWrite(marches[j], valMax);
   }
}


void Sinus(int valMax)
{
  
   int i = 0;
  
    for(i = 0; i<valMax; i++)
    {
      for(int j = 0; j< NB_MARCHES; j++)
      {
        analogWrite(marches[j], i);
      }
      
      delay(10);
    }
    
    for(i = valMax; i>=0; i--)
    {
      for(int j = 0; j< NB_MARCHES; j++)
      {
        analogWrite(marches[j], i);
      }
      
      delay(10);
    }
    
}
