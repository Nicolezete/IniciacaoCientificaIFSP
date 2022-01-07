#define potenciometro A0
   // define armazena na memória flash
   int led = 6;
   int buzzer = 10;
   long int var;

   void setup() {
     Serial.begin (9600);
     pinMode (led, OUTPUT);
     pinMode (buzzer, OUTPUT);
   }

   void loop() {
     // lendo
     var = analogRead (potenciometro);
  
     tone (buzzer, var, 500);
  
     // relendo
     var = map(var, 0, 1023, 0, 255);
     Serial.println (var);
  
     analogWrite (led, var);

     delay (500);
   }
