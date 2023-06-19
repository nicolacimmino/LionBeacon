// Lion Beacon.
//  Copyright (C) 2023 Nicola Cimmino
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see http://www.gnu.org/licenses/.
//
//
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

#define TIME_UNIT 400

char morseAZ[] = ".-  -...-.-.-.. .   ..-.--. ......  .----.- .-..--  -.  --- .--.--.-.-. ... -   ..- ...-.-- -..--.----..";
char morse09[] = "-----.----..---...--....-.....-....--...---..----.";

void dot()
{
  digitalWrite(13, HIGH);
  delay(TIME_UNIT);
  digitalWrite(13, LOW);
  delay(TIME_UNIT);
}

void dash()
{
  digitalWrite(13, HIGH);
  delay(TIME_UNIT * 2);
  digitalWrite(13, LOW);
  delay(TIME_UNIT);
}

void pause()
{
  delay(TIME_UNIT * 4);
}

void morse(char c)
{
  for (uint8_t ix = 0; ix < 5; ix++)
  {
    char symbol = ' ';

    if (c >= 'A' && c <= 'Z')
    {
      if(ix == 4) {
        break;
      }
      symbol = morseAZ[ix + ((c - 'A') * 4)];
    }

    if (c >= '0' && c <= '9')
    {
      symbol = morse09[ix + ((c - '0') * 5)];
    }

    if (symbol == '.')
    {
      dot();
    }
    else if (symbol == '-')
    {
      dash();
    }
  }

  pause();
}

void loop()
{
  // B C N
  // -...   -.-.   -.
  morse('B');
  morse('C');
  morse('N');
  morse('4');
  morse('9');

  pause();
  pause();
  pause();
}