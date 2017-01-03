PFont font;
String[] lines;
int last;
int id = 0;
int interval = 500;
int startTime;

void setup(){
  size(400,200);
  font = loadFont("Serif.plain-48.vlw");
  lines = loadStrings("strings.txt");
  textFont(font,36);
  textAlign(CENTER,CENTER);
  last = 0;
  startTime = millis();
}

void draw(){
  background(255);
  fill(0);
  if((millis()-startTime) > interval){
    if(last < lines[id].length())last = (last+1);
    startTime = millis();
  }
  text(lines[id].substring(0,last),0,0,width,height);
}

void mouseClicked(){
  int p_id = id;
  if(last >= lines[id].length()){
    if(id < 3){
      id++;
    }else{
      id = 0;
    }
  }
  if(p_id == id){
    last = lines[id].length();
  }else{
    last = 0;
  }
}

