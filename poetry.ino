#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include <avr/pgmspace.h>

#define TX_PIN 11 // Arduino transmit labeled RX on printer
#define RX_PIN 12 // Arduino receive labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

// -----------------------------------------------------------------------

int buttonState     = 0;
int lastButtonState = 0;

const char* titles[] = {"You Fit Into Me", "The Shortest and Sweetest\n of Songs", "Invisible Fish", "Their Sex Life", "The Garden", "Do Not Stand at My Grave\n and Weep", "Happiness", "For a Rainy Day", "In Spring Rain", "Memory", "And the Days are Not Full Enough", "1.1.87", "Exile", "Alba", "The Thief Left it Behind", "Tourists", "Nothing Gold Can Stay", "In this World", "Harlem"};

const char* authors[] = {"Margaret Atwood", "George MacDonald", "Joy Harjo", "A.R. Ammons", "Jacques Prevert", "Mary Elizabeth Frye", "Carl Sandburg", "D.A. Levy", "Kobayashi Issa", "Violet Wiggins Newton", "Ezra Pound", "Seamus Heaney", "Donald Hall", "Ezra Pound", "Ryokan", "D.H. Lawrence", "Robert Frost", "Kobayashi Issa", "Langston Hughes"};

const static char poem1[]  PROGMEM = "you fit into me\nlike a hook into an eye\n\na fish hook\nan open eye";
const static char poem2[]  PROGMEM = "Come\nHome.";
const static char poem3[]  PROGMEM = "Invisible fish swim this ghost\nocean now described by waves of\nsand, by water-worn rock. Soon\nthe fish will learn to walk.\nThen humans will come ashore\nand paint dreams on the dying\nstone. Then later, much later,\nthe ocean floor will be\npunctuated by Chevy trucks,\ncarrying the dreamers'\ndecendants, who are going to the\nstore.";
const static char poem4[]  PROGMEM = "One failure on\nTop of another";
const static char poem5[]  PROGMEM = "Thousands and thousands of years\nWould not be enough\nTo tell of\nThat small second of eternity\nWhen you held me\nWhen I held you\nOne morning\nIn winter's light\nIn Montsouris Park\nIn Paris\nOn Earth\nThis Earth that is a star";
const static char poem6[]  PROGMEM = "Do not stand at my grave\n and weep\nI am not there; I do not sleep.\nI am a thousand winds that blow,\nI am the diamond glints on snow,\nI am the sun on ripened grain,\nI am the gentle autumn rain.\nWhen you awaken in the morning's\n hush\nI am the swift uplifting rush\nOf quiet birds in circling\n flight.\nI am the soft starshine at\n night.\nDo not stand at my grave and\n cry:\nI am not there; I did not die.";
const static char poem7[]  PROGMEM = "I ASKED the professors who teach\n the meaning of life to tell\nme what is happiness.\nAnd I went to famous executives\n who boss the work of\nthousands of men.\n\nThey all shook their heads\n and gave me a smile as though\nI was trying to fool with them\nAnd then one Sunday afternoon\n I wandered out along\nthe Desplaines river\nAnd I saw a crowd of Hungarians\n under the trees with\ntheir women and children\nand a keg of beer and an\naccordion.";
const static char poem8[]  PROGMEM = "kisses\nwe tried to save\npressed in books\nlike flowers from\na sun warmed day\nonly\nyears later to\nopen yellowing pages\nto find those same\nkisses - wilted and dry.";
const static char poem9[]  PROGMEM = "In spring rain\na pretty girl\nyawning.";
const static char poem10[] PROGMEM = "Memory is a fragile thing;\nA bee's honey, and its sting.";
const static char poem11[] PROGMEM = "And the days are not full enough\nAnd the nights are not full\n enough\nAnd life slips by like a field\n mouse\nNot shaking the grass";
const static char poem12[] PROGMEM = "Dangerous pavements.\nBut I face the ice this year\nWith my father's stick.";
const static char poem13[] PROGMEM = "A boy who played and talked and\n and read with me\nFell from a maple tree.\n\nI loved her, but I told her I\n did not,\nAnd wept, and then forgot.\n\nI walked the streets where I was\n born and grew,\nAnd all the streets were new.";
const static char poem14[] PROGMEM = "As cool as the pale wet leaves\nof lily-of-the-valley\nShe lay beside me in the dawn.";
const static char poem15[] PROGMEM = "The Thief\nleft It behind ---\nThe moon at the window.";
const static char poem16[] PROGMEM = "There is nothing to look at\n anymore,\neverything has been seen\n to death.";
const static char poem17[] PROGMEM = "Nature's first green is gold,\nHer hardest hue to hold.\nHer early leaf's a flower;\nBut only so an hour.\nThen leaf subsides to leaf,\nSo Eden sank to grief,\nSo dawn goes down to day.\nNothing gold can stay.";
const static char poem18[] PROGMEM = "In this world\nwe walk on the roof of hell,\n gazing at flowers.";
const static char poem19[] PROGMEM = "What happens to a dream\n deferred?\n\nDoes it dry up\nlike a raisin in the sun?\n\nOr fester like a sore - \nAnd then run?\n\nDoes it stink like rotten meat?\nOr crust and sugar over -\nlike a syrupy sweet?\n\nMaybe it just sags\nlike a heavy load.\n\nOr does it explode?";

const char* const PROGMEM poems[] = {poem1, poem2, poem3, poem4, poem5, poem6, poem7, poem8, poem9, poem10, poem11, poem12, poem13, poem14, poem15, poem16, poem17, poem18, poem19};

char buffer [420];

void setup() {
  pinMode(8, INPUT);
  pinMode(3, OUTPUT);

  randomSeed(analogRead(4));
  Serial.begin(9600);
  mySerial.begin(9600);
  printer.begin();       // Init printer (same regardless of serial type)
}

void loop() {
  buttonState = digitalRead(8);
  digitalWrite(8, HIGH);
  digitalWrite(3, HIGH);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      digitalWrite(3, LOW);
      int poem = random(0, 18);
      printer.justify('C');
      printer.boldOn();
      printer.doubleHeightOn();
      printer.println(titles[poem]);
      printer.boldOff();
      printer.doubleHeightOff();
      printer.println(authors[poem]);
      printer.justify('L');
      strcpy_P(buffer, (char*)pgm_read_word(&(poems[poem])));
      printer.println();
      printer.println(buffer);
      printer.println(F("\n\n\n"));
      printer.println(F("CUT HERE------------------------"));
      printer.println(F("\n\n\n"));
      
    }
    delay(500);
  }
  lastButtonState = buttonState;
}
