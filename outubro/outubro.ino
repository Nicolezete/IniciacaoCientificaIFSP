#define white 13
String  LED_control; //string para controle do LED

void setup() 
{
  Serial.begin(9600);        //inicializa serial em 9600bps
  pinMode(white, OUTPUT);
  digitalWrite(white, LOW);
}


void loop() 
{
  while(Serial.available())   //aguarda dados
  {
    delay(5);
    char let = Serial.read(); //armazena bytes
    LED_control += let;       //na string de controle
  }

  if(LED_control.length() > 0x00)
  {
    Serial.println(LED_control);  //imprime na Serial monitor

    if(LED_control == "brancoON") digitalWrite(white, HIGH);
    else if(LED_control == "brancoOFF") digitalWrite(white, LOW);

    LED_control = ""; //limpa string
    
  } //end readString
  
}
