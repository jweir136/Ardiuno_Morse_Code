/**
  Take a morse code input string and make a light at pin 8 output morse code

  @param morseCode - THe string, containing only '.', '-' for short on, and long on. A short on if 1 second, and a long on is 3 seconds.
                      The pause between letters is 3 seconds. The pause between words is 7 seconds.
  @returns This function returns 0 if the function executed successfully, -1 if the function encounters an error
*/
int blinkMorseCode(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    if (morseCode.charAt(i) == '-') {
      // blink for 3 seconds...a long on
      digitalWrite(8, HIGH);
      delay(300);
      digitalWrite(8, LOW);
    } else if (morseCode.charAt(i) == '.') {
      // blink for 1 second ... a short on
      digitalWrite(8, HIGH);
      delay(100);
      digitalWrite(8, LOW);
    } else {
      // an invalid character has been returned...return an error code
      return -1;
    }
  }

  // pause for 3 seconds, signifying the end of a letter
  delay(300);

  return 0;
}

void setup() {
  // set the GPIO pin 8 to output
  pinMode(8, OUTPUT);

  // set the baud rate
  Serial.begin(9600);
}

void loop() {
  // define variables outside of the for loop
  char currentChar;

  // wait until there is data to be read from the serial buffer...employ a busywaiting method
  while (Serial.available() == 0) { }

  // read the input string and remove any waitspace before and after
  String inputStr = Serial.readString();
  inputStr.toUpperCase();
  inputStr.trim();

  // go through each character of the input string and convert each char to morse code
  for (int i = 0; i < inputStr.length(); i++) {
    currentChar = inputStr.charAt(i);

    switch (currentChar) {
      case 'A':
        blinkMorseCode(".-");
        break;
      case 'B':
        blinkMorseCode("-...");
        break;
      case 'C':
        blinkMorseCode("-.-.");
        break;
      case 'D':
        blinkMorseCode("-..");
        break;
      case 'E':
        blinkMorseCode(".");
        break;
      case 'F':
        blinkMorseCode("..-.");
        break;
      case 'G':
        blinkMorseCode("--.");
        break;
      case 'H':
        blinkMorseCode("....");
        break;
      case 'I':
        blinkMorseCode("..");
        break;
      case 'J':
        blinkMorseCode(".---");
        break;
      case 'K':
        blinkMorseCode("-.-");
        break;
      case 'L':
        blinkMorseCode(".-..");
        break;
      case 'M':
        blinkMorseCode("--");
        break;
      case 'N':
        blinkMorseCode("-.");
        break;
      case 'O':
        blinkMorseCode("---");
        break;
      case 'P':
        blinkMorseCode(".--.");
        break;
      case 'Q':
        blinkMorseCode("--.-");
        break;
      case 'R':
        blinkMorseCode(".-.");
        break;
      case 'S':
        blinkMorseCode("...");
        break;
      case 'T':
        blinkMorseCode("-");
        break;
      case 'U':
        blinkMorseCode("..-");
        break;
      case 'V':
        blinkMorseCode("...-");
        break;
      case 'W':
        blinkMorseCode(".--");
        break;
      case 'X':
        blinkMorseCode("-..-");
        break;
      case 'Y':
        blinkMorseCode("-.--");
        break;
      case 'Z':
        blinkMorseCode("--..");
        break;
      case ' ':
        // if a space occurs, then pause for 7 seconds
        delay(700);
      default:
        break;
    }
  }
}
