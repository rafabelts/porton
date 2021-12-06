int IN1 = 8;  //se declara la variable de la entrada 2 del l298n
int IN2 = 9;  //se declara la variable de la entrada 2 del l298n

int bt1 = 7; //se declara el push bottom 1
int bt1state = LOW; //se declara el estado del push bottom 1


int bt2 = 5; //se declara el push bottom 2
int bt2state = LOW; //se declara el estado del push bottom 2

int sen1 = 4; //se declara el tope de carrera 1
int sen1sta = LOW; //se declara el estado del tope de carrera 1

int sen2 = 3; //se declara el tope de carrera 1
int sen2sta = LOW; //se declara el estado del tope de carrera 1

void setup () {
  pinMode(bt2, INPUT);  //la señal que recibira el push sera de entrada
  pinMode(bt1, INPUT); //la señal que recibira el push sera de entrada

  pinMode(IN2, OUTPUT); //la señal que recibira la entrada 2 del l298 sera de salida
  pinMode(IN1, OUTPUT); //la señal que recibira la entrada 2 del l298  sera de salida
}

void apaga(){ //funcion para apagar el motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

void abre(){  //funcion para descender 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void cierra (){  //funcion para ascender 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void loop(){
  bt1state = digitalRead(bt1); // estado del boton 1 es igual a la lectura del boton 1
  bt2state = digitalRead(bt2); // estado del boton 2 es igual a la lectura del boton 2
  
  sen1sta = digitalRead(sen1); // estado del tope 1 es igual a la lectura del tope 1
  sen2sta = digitalRead(sen2); // estado del tope 1 es igual a la lectura del tope 1

  
  if(bt2state == HIGH){  //sentencia condicional que indica que mientras el estado del tope 2 sea diferente a HIGH (ALTO, 1) el motor haga la funcion de bajar 
    while (sen2sta != HIGH){
      abre();

    } 
    apaga(); // apagar cuando el tope 2 no cumpla el loop while
  }    

  else if (bt1state == HIGH){ //sentencia condicional que indica que mientras el estado del tope 1 sea diferente a HIGH (ALTO, 1) el motor haga la funcion de subir
    while(sen1sta =HIGH){
      cierra();
    }
    apaga(); // apagar cuando el tope 2 no cumpla el loop while
  }
  
  else{ //sentencia condicional que indica que si no se cumple ninguna condicion de if o else if, el motor se mantenga apagado
    apaga();  
  }
}
