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

const char* titles[]  = {"Mool Mantar","Pauri 1","Pauri 2","Pauri 3","Pauri 4","Pauri 5","Pauri 6","Pauri 7","Pauri 8","Pauri 9","Pauri 10","Pauri 11","Pauri 12","Pauri 13","Pauri 14","Pauri 15","Pauri 16","Pauri 17","Pauri 18","Pauri 19","Pauri 20","Pauri 21","Pauri 22","Pauri 23","Pauri 26","Pauri 27","Pauri 28","Pauri 29","Pauri 30","Pauri 31","Pauri 32","Pauri 33","Pauri 34","Pauri 35","Pauri 36","Pauri 37","Pauri 38","Salok"};

const static char p1[]  PROGMEM = "ik onkaar\nSat Naam\nkartaa purakh nirbh-a-o nirvair akaal moorat\najoonee saibhN gur parsaad. jap.\naad sach jugaad sach.\nhai bhee sach naanak hosee bhee sach.";
const static char p2[]  PROGMEM = "sochai soch naa hov-a-ee jay sochee lakh vaar\nchupai chup naa hov-a-ee jay laa-i rahaa liv taar\nbhukhi-aa bhukh naa utree jay bannaa puree-aa bhaar\nsehas si-aanpaa lakh hoh taa ik naa chalai naal\nkiv sachi-aaraa ho-ee-ai kiv koorhai tutai paal-hukam rajaa-ee chalnaa naanak likhi-aa naal\n";
const static char p3[]  PROGMEM = "hukmee hovan aakaar hukam na kahi-aa jaa-ee.\nhukmee hovan jee-a hukam milai vadi-aa-ee.\nhukmee utam neech hukam likh dukh skh paa-ee-ah.\niknaa hukmee bakhsees ik hukmee sadaa bhavaa-ee-ah.\nhukmai andar sabh ko baahar hukam na ko-ay.\nnaanak hukmai jay bujhai ta ha-umai kahai na ko-ay.";
const static char p4[]  PROGMEM = "gaavai ko taan hovai kisai taan. gaavai ko daat jaanai neesaan.\n gaavai ko gun vadi-aa-ee-aa chaar. gaavai ko vidi-aa vikham veechaar.\ngaavai ko saaj karay tan khayh. gaavai ko jee-a lai fir dayh.\ngaavai ko jaapai disai door. gaavai ko vaykhai haadraa hadoor.\nkathnaa kathee na aavai tot. kath kath kathee kotee kot kot.\ndaydaa day laiday thak paahi. jugaa jugantar khaahee khaahi.\nhukmee hukam chalaa-ay raahu. naanak vigsai vayparvaahu.";
const static char p5[]  PROGMEM = "saachaa saahib saach naa-ay bhaakhi-aa bhaa-o apaar.\naakhahi mangahi dayhi dayhi daat karay daataar.\nfayr ke agai rakhee-ai jit disai darbaar.\nmuhou ke bolan bolee-ai jit sun Dharay pi-aar.\namrit vaylaa sach naa-o vadi-aa-ee veechaar.\nkarmee aavai kaprhaa nadree mokh du-aar.\nnaanak evai jaanee-ai sabh aapay sachiaar.";
const static char p6[]  PROGMEM = "thaapi-aa na jaa-ay keetaa na ho-ay. aapay aap niranjan so-ay.\njin sayvi-aa tin paa-i-aa maan. naanak gaavee-ai gunee niDhaan.\ngaavee-ai sunee-ai man rakhee-ai bhaa-o. dukh parhar sukh ghar lai jaa-ay.\ngurmukh naadaN gurmukh vaydaN gurmukh rahi-aa samaa-ee.\ngur eesar gur gorakh barmaa gur paarbatee maa-ee.\njay ha-o jaanaa aakhaa naahee kahnaa kathan na jaa-ee.\nguraa ik dayhi bujhaa-ee. sabhnaa jee-aa kaa ik daataa so mai visar na jaa-ee.";
const static char p7[]  PROGMEM = "tirath naavaa jay tis bhaavaa vin bhaanay ke naa-ay karee.\njaytee sirath upaa-ee vaykhaa vin karmaa ke milai la-ee.\nmat vich ratan javaahar maanik jay ik gur kee sikh sunee.\nguraa ik dayhi bujhaa-ee.\nsabhnaa jee-aa kaa ik daataa so mai visar na jaa-ee.";
const static char p8[]  PROGMEM = "jay jug chaaray aarjaa hor dasoonee ho-ay.\nnavaa khanda vich jaanee-ai naal chalai sabh ko-ay.\nchanga naa-o rakhaa-ay kai jas keerat jag lay-ay.\njay tis nadar na aavee ta vaat na puchhai kay.\nkeetaa andar keet kar dosee dos Dharay.\nnaanak nirgun gun karay gunvanti-aa gun day.\ntayhaa ko-ay na sujh-ee je tis gun ko-ay karay.";
const static char p9[]  PROGMEM = "suni-ai siDh peer sur naath.\nsuni-ai Dharat Dhaval aakaas.\nsuni-ai deep lo-a paataal.\nsuni-ai pohi na sakai kaal.\nnaanak bhagtaa sadaa vigaas.\nsuni-ai dookh paap kaa naas.";
const static char p10[] PROGMEM = "suni-ai eesar barmaa ind.\nsuni-ai mukh saalaahan mand.\nsuni-ai jog jugat tan bhayd.\nsuni-ai saasat simrit vayd.\nnaanak bhagtaa sadaa vigaas.\nsuni-ai dookh paap kaa naas.";
const static char p11[] PROGMEM = "suni-ai sat santokh gi-aan.\nsuni-ai athsath kaa isnaan.\nsuni-ai parh parh paavahi maan.\nsuni-ai laagai sahj Dhi-aan.\nnaanak bhagtaa sadaa vigaas.\nsuni-ai dookh paap kaa naas.";
const static char p12[] PROGMEM = "suni-ai saraa gunaa kay gaah.\nsuni-ai saykh peer paatisaah.\nsuni-ai anDhay paavahi raahu.\nsuni-ai haath hovai asgaahu.\nnaanak bhagtaa sadaa vigaas.\nsuni-ai dookh paap kaa naas.";
const static char p13[] PROGMEM = "mannay kee gat kahee na jaa-ay.\njay ko kahai pichhai pachhutaa-ay.\nkaagad kalam na likhanhaar.\nmannay kaa bahi karan veechaar.\naisaa naam niranjan ho-ay.\njay ko man jaanai man ko-ay.";
const static char p14[] PROGMEM = "mannai surat hovai man buDh.\nmannai sagal bhavan kee suDh.\nmannai muhi chotaa naa khaa-ay.\nmannai jam kai saath na jaa-ay.\naisaa naam niranjan ho-ay.\njay ko man jaanai man ko-ay.";
const static char p15[] PROGMEM = "mannai maarag thaak na paa-ay.\nmannai pat si-o pargat jaa-ay.\nmannai mag na chalai panth.\nmannai Dharam saytee san-banDh.\naisaa naam niranjan ho-ay.\njay ko man jaanai man ko-ay.";
const static char p16[] PROGMEM = "mannai paavahi mokh du-aar.\nmannai parvaarai saaDhaar.\nmannai tarai taaray gur sikh.\nmannai naanak bhavahi na bhikh.\naisaa naam niranjan ho-ay.\njay ko man jaanai man ko-ay.";
const static char p17[] PROGMEM = "panch parvaan panch parDhaan. panchay paavahi dargahi maan.\npanchay sohahi dar raajaan. panchaa kaa gur ayk Dhi-aan.\njay ko kahai karai veechaar. kartay kai karnai naahee sumaar.\nDhoul Dharam da-i-aa kaa poot. santokh thaap rakhi-aa jin soot.\njay ko bujhai hovai sachiaar. Dhavlai upar kaytaa bhaar.\nDhartee hor parai hor hor. tis tay bhaar talai kavan jor\njee-a jaat rangaa kay naav. sabhnaa likhi-aa vurhee kalaam.\nayhu laykhaa likh jaanai ko-ay. laykhaa likhi-aa kaytaa ho-ay.\nkaytaa taan su-aalihu roop. kaytee daat jaanai koun koot.\nkeetaa pasaa-o ayko kavaa-o. tis tay ho-ay lakh daree-aa-o.\nkudrat kavan kahaa veechaar. vaari-aa na jaavaa ayk vaar.\njo tuDh bhaavai saa-ee bhalee kaar. too sadaa salaamat nirankaar.";
const static char p18[] PROGMEM = "asaNkh jap asaNkh bhaa-o. asaNkh poojaa asaNkh tap taa-o.\nasaNkh garanth mukh vayd paath. asaNkh jog man rahahi udaas.\nasaNkh bhagat gun gi-aan veechaar. asaNkh satee asaNkh daataar.\nasaNkh soor muh bhakh saar. asaNkh mon liv laa-ay taar.\nkudrat kavan kahaa veechaar. vaari-aa na jaavaa ayk vaar.\njo tuDh bhaavai saa-ee bhalee kaar. too sadaa salaamat nirankaar.";
const static char p19[] PROGMEM = "asaNkh moorakh anDh ghor. asaNkh chor haraamkhor.\nasaNkh amar kar jaahi jor. asaNkh galvadh hati-aa kamaahi.\nasaNkh paapee paap kar jaahi. asaNkh koorhi-aar koorhay firaahi.\nasaNkh malaychh mal bhakh khaahi. asaNkh nindak sir karahi bhaar.\nnaanak neech kahai veechaar. vaari-aa na jaavaa ayk vaar.\njo tuDh bhaavai saa-ee bhalee kaar.  too sadaa salaamat nirankaar.";
const static char p20[] PROGMEM = "asaNkh naav asaNkh thaav. agamm agamm asaNkh lo-a.\nasaNkh kehahi sir bhaar ho-ay. akhree naam akhree saalaah.\nakhree gi-aan geet gun gaah. akhree likhan bolan baan.\nakhraa sir sanjog vakhaan. jin ayhi likhay tis sir naahi.\njiv furmaa-ay tiv tiv paahi. jaytaa keetaa taytaa naa-o. vin naavai naahee ko thaa-o.\nkudrat kavan kahaa veechaar. vaari-aa na jaavaa ayk vaar.\njo tuDh bhaavai saa-ee bhalee kaar. too sadaa salaamat nirankaar.";
const static char p21[] PROGMEM = "bharee-ai hath pair tan dayh. paanee Dhotai utras khayh.\nmoot paleetee kaparh ho-ay. day saaboon la-ee-ai oh Dho-ay.\nbharee-ai mat paapaa kai sang. oh Dhopai naavai kai rang.\npunnee paapee aakhan naahi. kar kar karnaa likh lai jaahu.\naapay beej aapay hee khaahu. naanak hukmee aavhu jaahu.";
const static char p22[] PROGMEM = "tirath tap da-i-aa dat daan. jay ko paavai til kaa maan.\nsuni-aa mani-aa man keetaa bhaa-o. antargat tirath mal naa-o.\nsabh gun tayray mai naahee ko-ay. vin gun keetay bhagat na ho-ay.\nsu-asat aath banee barmaa-o. sat suhaan sadaa man chaa-o.\nkavan so vaylaa vakhat kavan kavan thit kavan vaar. kavan se rutee maahu kavan jit ho-aa aakaar.\nvayl na paa-ee-aa pandtee je hovai laykh puraan. vakhat na paa-i-o kaadee-aa je likhan laykh kuraan.\nthit vaar naa jogee jaanai rut maahu naa ko-ee. jaa kartaa sirthee ka-o saajay aapay jaanai so-ee.\nkiv kar aakhaa kiv saalaahee ki-o varnee kiv jaanaa.  naanak aakhan sabh ko aakhai ik doo ik si-aanaa.\nvadaa saahib vadee naa-ee keetaa jaa kaa hovai. naanak jay ko aapou jaanai agai ga-i-aa na sohai.";
const static char p23[] PROGMEM = "paataalaa paataal lakh aagaasaa aagaas.\norhak orhak bhaal thakay vayd kahan ik vaat.\nsahas athaarah kahan kataybaa asuloo ik Dhaat.\nlaykhaa ho-ay ta likee-ai laykhai ho-ay vinaas.\nnaanak vadaa aakhee-ai aapay jaanai aap.";
const static char p24[] PROGMEM = "saalaahee saalaahi aytee surat na paa-ee-aa.\nnadee-aa atai vaah pavahi samund na jaanee-ahi.\nsamund saah sultaan girhaa saytee maal Dhan.\nkeerhee tul na hovnee jay tis manhu na veesrahi.";
const static char p25[] PROGMEM = "ant na siftee kahan na ant. ant na karnai dayn na ant.\nant na vaykhan sunan na ant. ant na jaapai ki-aa man mant.\nant na jaapai keetaa aakaar. ant na jaapai paaraavaar.\nant kaaran kaytay billaahi. taa kay ant na paa-ay jaahi.\nayhu ant na jaanai ko-ay. bahutaa kahee-ai bahutaa ho-ay.\nvadaa saahib oochaa thaa-o. oochay upar oochaa naa-o.\nayvad oochaa hovai ko-ay. tis oochay ka-o jaanai so-ay.\njayvad aap jaanai aap aap. naanak nadree karmee daat.";
const static char p26[] PROGMEM = "bahutaa karam likhi-aa naa jaa-ay. vadaa daataa til na tamaa-ay.\nkaytay mangahi joDh apaar.kayti-aa ganat nahee veechaar.\nkaytay khap tutahi vaykaar. kaytay lai lai mukar paahi.\nkaytay moorakh khaahee khaahi. kayti-aa dookh bhookh sad maar.\nayhi bhe daat tayree daataar. band khalaasee bhaanai ho-ay.\nhor aakh na sakai ko-ay. jay ko khaa-ik aakhan paa-ay. oh jaanai jaytee-aa muhi khaa-ay.\naapay jaanai aapay day-ay. aakhahi se bhe kay-ee kay-ay.\njis no bakhsay sifat saalaah. naanak paatisaahee paatisaahu.";
const static char p27[] PROGMEM = "amul gun amul vaapaar. amul vaapaaree-ay amul bhandaar.\namul aavahi amul lai jaahi. amul bhaa-ay amulaa samaahi.\namul Dharam amul deebaan. amul tul amul parvaan.\namul bakhsees amul neesaan. amul karam amul furmaan.\namulo amul aakhi-aa na jaa-ay. aakh aakh rahay liv laa-ay.\naakhahi vayd paath puraan. aakhahi parhay karahi vakhi-aan. aakhahi barmay aakhahi ind.\naakhahi gopee tai govind. aakhahi eesar aakhahi siDh. aakhahi kaytay keetay buDh.\naakhahi daanav aakhahi dayv. aakhahi sur nar mun jan sayv.\nkaytay aakhahi aakhan paahi. kaytay kahi kahi uth uth jaahi.\naytay keetay hor karayhi. taa aakh na sakahi kay-ee kay-ay.\njayvad bhaavai tayvad ho-ay. naanak jaanai saachaa so-ay.\njay ko aakhai boluvigaarh. taa likee-ai sir gaavaaraa gaavaar.";
const static char p28[] PROGMEM = "so dar kayhaa so ghar kayhaa jit bahi sarab samaalay.\nvaajay naad anayk asankhaa kaytay vaavanhaaray. kaytay raag paree si-o kahee-an kaytay gaavanhaaray.\ngaavahi tuhno pa-un paanee baisantar gaavai raajaa Dharam du-aaray.\ngaavahi chit gupat likh jaaneh likh likh Dharam veechaaray.\ngaavahi eesar barmaa dayvee sohan sadaa savaaray. gaavahi ind idaasan baithay dayviti-aa dar naalay.\ngaavahi siDh samaaDhee andar gaavan saaDh vichaaray.\ngaavan jatee satee santokhee gaavahi veer karaaray.gaavan pandit parhan rakheesar jug jug vaydaa naalay.\ngaavahi mohnee-aa man mohan surgaa machh pa-i-aalay.\ngaavan ratan upaa-ay tayray athsath tirath naalay. gaavahi joDh mahaabal sooraa gaavahi khaanee chaaray.\ngaavahi khand mandal varbhandaa kar kar rakhay Dhaaray.\nsay-ee tuDhuno gaavahi jo tuDh bhaavan ratay tayray bhagat rasaalay.\nhor kaytay gaavan say mai chit na aavan naanak ki-aa veechaaray.\nso-ee so-ee sadaa sach saahib saachaa saachee naa-ee. hai bhee hosee jaa-ay na jaasee rachnaa jin rachaa-ee.\nrangee rangee bhaatee kar kar jinsee maa-i-aa jin upaa-ee.\nkar kar vaykhai keetaa aapnaa jiv tis dee vadi-aa-ee. jo tis bhaavai so-ee karsee hukam na karnaa jaa-ee.\nso paatisaahu saahaa paatisaahib naanak rahan rajaa-ee.";
const static char p29[] PROGMEM = "munda santokh saram pat jholee Dhi-aan kee karahi bibhoot.\nkhinthaa kaal ku-aaree kaa-i-aa jugat dandaa parteet.\naa-ee panthee sagal jamaatee man jeetai jag jeet.\naadays tisai aadays.\naad aneel anaad anaahat jug jug ayko vays.";
const static char p30[] PROGMEM = "bhugat gi-aan da-i-aa bhandaaran ghat ghat vaajeh naad.\naap naath naathee sabh jaa kee riDh siDh avraa saad.\nsanjog vijog du-ay kaar chalaaveh laykhay aavahi bhaag.\naadays tisai aadays.\naad aneel anaad anaahat jug jug ayko vays.";
const static char p31[] PROGMEM = "aykaa maa-ee jugat vi-aa-ee tin chaylay parvaan.\nik sansaaree ik bhandaaree ik laa-ay deebaan.\njiv tis bhaavai tivai chalaavai jiv hovai furmaan.\noh vaykhai onaa nadar na aavai bahutaa ayhu vidaan.\naadays tisai aadays.\naad aneel anaad anaahat jug jug ayko vays.";
const static char p32[] PROGMEM = "aasan lo-ay lo-ay bhandaar.\njo kichh paa-i-aa so aykaa vaar.\nkar kar vaykhai sirjanhaar.\nnaanak sachay kee saachee kaar.\naadays tisai aadays.\naad aneel anaad anaahat jug jug ayko vays.";
const static char p33[] PROGMEM = "ik doo jeebhou lakh hohi lakh hoveh lakh vees.\nlakh lakh gayrhaa aakhee-ahi ayk naam jagdees.\nayt raahi pat pavrhee-aa charhee-ai ho-ay ikees.\nsun galaa aakaas kee keetaa aa-ee rees.\nnaanak nadree paa-ee-ai koorhee koorhai thees.";
const static char p34[] PROGMEM = "aakhan jor chupai nah jor.\njor na mangan dayn na jor.\njor na jeevan maran nah jor.\njor na raaj maal man sor.\njor na surtee gi-aan veechaar.\njor na jugtee chhutai sansaar.\njis hath jor kar vaykhai so-ay.\nnaanak utam neech na ko-ay.";
const static char p35[] PROGMEM = "raatee rutee thitee vaar. pavan paanee agnee paataal.\ntis vich Dhartee thaap rakhee Dharam saal. tis vich jee-a jugat kay rang.\ntin kay naam anayk anant. karmee karmee ho-ay veechaar.\nsachaa aap sachaa darbaar. tithai sohan panch parvaan.\nnadree karam pavai neesaan. kach pakaa-ee othai paa-ay.\nnaanak ga-i-aa jaapai jaa-ay.";
const static char p36[] PROGMEM = "Dharam khand kaa ayho Dharam. gi-aan khand kaa aakhhu karam.\nkaytay pavan paanee vaisantar kaytay kaan mahays.\nkaytay barmay ghaarhat gharhee-ahi roop rang kay vays.\nkaytee-aa karam bhoomee mayr kaytay kaytay Dhoo updays.\nkaytay ind chand soor kaytay kaytay mandal days.\nkaytay siDh buDh naath kaytay kaytay dayvee vays.\nkaytay dayv daanav mun kaytay kaytay ratan samund.\nkaytee-aa khaanee kaytee-aa banee kaytay paat narind.\nkaytee-aa surtee sayvak kaytay naanak ant na ant.";
const static char p37[] PROGMEM = "gi-aan khand meh gi-aan parchand.\ntithai naad binod kod anand.\nsaram khand kee banee roop.\ntithai ghaarhat gharhee-ai bahut anoop.\ntaa kee-aa galaa kathee-aa naa jaahi.\njay ko kahai pichhai pachhutaa-ay.\ntithai gharhee-ai surat mat man buDh.\ntithai gharhee-ai suraa siDhaa kee suDh.";
const static char p38[] PROGMEM = "karam khand kee banee jor. tithai hor na ko-ee hor.\ntithai joDh mahaabal soor. tin meh raam rahi-aa bharpoor.\ntithai seeto seetaa mahimaa maahi. taa kay roop na kathnay jaahi.\nnaa ohi mareh na thaagay jaahi. jin kai raam vasai man maahi.\ntithai bhagat vaseh kay lo-a. karahi anand sachaa man so-ay.\nsach khand vasai nirankaar. kar kar vaykhai nadar nihaal.\ntithai khand mandal varbhand. jay ko kathai ta ant na ant.\ntithai lo-a lo-a aakaar. jiv jiv hukam tivai tiv kaar.\nvaykhai vigsai kar veechaar. naanak kathnaa karrhaa saar.";
const static char p39[] PROGMEM = "jat paahaaraa Dheeraj suni-aar.\nahran mat vayd hathee-aar.\nbha-o khalaa agan tap taa-o.\nbhaaNdaa bhaa-o amrit tit dhaal.\ngharhee-ai sabad sachee taksaal.\njin ka-o nadar karam tin kaar.\nnaanak nadree nadar nihaal.";

const char* const PROGMEM prayers[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,p37,p38,p39};

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
      int prayer = random(0, 38);
      printer.doubleHeightOn();
      printer.boldOn();
      printer.println(titles[prayer]);
      printer.justify('C');
      printer.boldOff();
      strcpy_P(buffer, (char*)pgm_read_word(&(prayers[prayer])));
      printer.println();
      printer.println(buffer);
      printer.println(F("\n\n\n"));
      
    }
    delay(500);
  }
  lastButtonState = buttonState;
}
